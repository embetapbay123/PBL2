#include <iostream>
#include <string>
#include <conio.h> // Dùng cho _getch() trên Windows
#include <windows.h> // Dùng cho SetConsoleCursorPosition

using namespace std;

// Hàm di chuyển con trỏ đến vị trí cụ thể
void moveCursor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm nhập dữ liệu từ textbox
string getInput(int x, int y, bool isPassword = false) {
    string input = "";
    char ch;

    moveCursor(x, y); // Di chuyển con trỏ đến vị trí nhập

    while (true) {
        ch = _getch(); // Đọc một ký tự từ bàn phím

        if (ch == '\r') { // Phím Enter
            break;
        } else if (ch == '\b') { // Phím Backspace
            if (!input.empty()) {
                input.pop_back(); // Xóa ký tự cuối trong chuỗi
                cout << "\b \b"; // Di chuyển con trỏ lùi lại và xóa ký tự trên màn hình
            }
        } else if (ch >= 32 && ch <= 126) { // Ký tự có thể in được
            input += ch;
            if (isPassword) {
                cout << '*'; // Hiển thị dấu * nếu là mật khẩu
            } else {
                cout << ch; // Hiển thị ký tự bình thường
            }
        }
    }

    return input;
}

int main() {
    string username, password;

    // Hiển thị giao diện
    system("cls");
    cout << "+--------------------------+" << endl;
    cout << "|        LOGIN FORM       |" << endl;
    cout << "+--------------------------+" << endl;
    cout << "| Username:               |" << endl;
    cout << "| Password:               |" << endl;
    cout << "+--------------------------+" << endl;
    cout << "| [Enter] Login           |" << endl;
    cout << "+--------------------------+" << endl;

    // Nhập Username
    username = getInput(12, 3, false); // Nhập tại dòng 3, cột 12 (sau "Username:")

    // Nhập Password
    password = getInput(12, 4, true); // Nhập tại dòng 4, cột 12 (sau "Password:")

    // Hiển thị kết quả
    system("cls");
    cout << "Thông tin đăng nhập:" << endl;
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;

    return 0;
}
