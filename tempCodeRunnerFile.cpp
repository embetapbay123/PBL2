#include <windows.h>
#include <iostream>

int main() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    if (hStdin == INVALID_HANDLE_VALUE) {
        std::cerr << "Error getting input handle." << std::endl;
        return 1;
    }

    // Bật chế độ xử lý sự kiện chuột
    DWORD fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    if (!SetConsoleMode(hStdin, fdwMode)) {
        std::cerr << "Error setting console mode." << std::endl;
        return 1;
    }

    std::cout << "Click inside the console window to trigger an event..." << std::endl;

    INPUT_RECORD inputRecord;
    DWORD events;
    bool running = true;

    while (running) {
        ReadConsoleInput(hStdin, &inputRecord, 1, &events);

        if (inputRecord.EventType == MOUSE_EVENT) {
            MOUSE_EVENT_RECORD mouseEvent = inputRecord.Event.MouseEvent;

            if (mouseEvent.dwEventFlags == 0 && mouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
                COORD mousePos = mouseEvent.dwMousePosition;
                std::cout << "Mouse clicked at (" << mousePos.X << ", " << mousePos.Y << ")" << std::endl;

                // Ví dụ: Kết thúc chương trình nếu nhấn vào góc trái trên (0,0)
                if (mousePos.X == 0 && mousePos.Y == 0) {
                    std::cout << "Exiting..." << std::endl;
                    running = false;
                }
            }
        }
    }

    return 0;
}
