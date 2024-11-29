#ifndef DOHOA_H
#define DOHOA_H

#include <iostream>
#include <conio.h> // Sử dụng cho _getch trên Windows
#include <iomanip>
#include <windows.h>
#include <limits>
using namespace std;

void hideCursor() {
    cout << "\033[?25l";  // Ẩn con trỏ
}

void showCursor() {
    cout << "\033[?25h";  // Hiển thị lại con trỏ
}

void clearScreen() {
   COORD cursorPosition;	cursorPosition.X = 0;	
   cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void printNoti() {
    system("pause");
}

void setColor(int colorCode) {
    cout << "\033[" << colorCode << "m";
}

void resetColor() {
    cout << "\033[0m";
}

void drawBox(const string& text, bool selected, int out = 25) {
    if (selected) {
        setColor(31); // Màu đỏ cho lựa chọn hiện tại (mã màu ANSI cho màu đỏ)
    } else {
        setColor(32); // Màu xanh dương cho các lựa chọn khác (mã màu ANSI cho màu xanh dương)
    }

    cout << setw(43) << left << ' ' << " ╔═══════════════════════════╗\n"; // Góc trên cùng
    cout << setw(43) << left << ' ' << " ║ ";
    if (selected) cout << "> ", out -= 2; // Thêm dấu > nếu là lựa chọn hiện tại
    cout << setw(out) << left << text;
    cout << " ║\n";
    cout << setw(43) << left << ' ' << " ╚═══════════════════════════╝\n"; // Góc dưới cùng
    resetColor(); // Đặt lại màu về mặc định
}

int printMenu(string menu[], int MENU_SIZE, const string& name) {
    int choice = 0;
    char key;
    system("cls");
    hideCursor();
    while (true) {
        clearScreen();
        cout << endl << setw(43 + (29 - name.size()) / 2) << left << ' ' << name << endl << endl;

        for (int i = 0; i < MENU_SIZE; i++) {
            drawBox(menu[i], i == choice);
        }

        key = _getch();

        if (key == 72) { // Mũi tên lên
            choice = (choice - 1 + MENU_SIZE) % MENU_SIZE;
        } else if (key == 80) { // Mũi tên xuống
            choice = (choice + 1) % MENU_SIZE;
        } else if (key == 13) { // Phím Enter
            cout << "\nBan da chon: " << menu[choice] << endl;
            showCursor();
            printNoti();
            break;
        }
    }
    return choice;
}

#endif
