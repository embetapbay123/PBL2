#ifndef USER_H
#define USER_H
#include <iostream>
#include <conio.h>
#include "Element.h"
#include "Reader.h"
using namespace std;
enum UserRole {
    ADMIN,
    READER
};
class User : public Element {
private:
    // đối với user thì id là account đăng nhập, name chính là role
    // nmae = "ADMIN", "READER"
    string pass;
public:
    User() {}
    User(Reader newUser) : pass(newUser.getId()), Element(newUser.getId(), "READER") {}
    User(const string& Id, const string& Pass, const string& Role) : Element(Id, Role), pass(Pass) {}
    bool isAvailabletoDelete() const {return 1;}
    bool authenticate(const string& inputPass) const {
        return pass == inputPass;
    }
    void changePassword() {
        string oldPass, newPass, confirmPass;

        cout << "Nhập mật khẩu cũ: ";
        oldPass = inputPasswordWithAsterisks();

        if (!authenticate(oldPass)) {
            cout << "Sai mật khẩu cũ! Không thể đổi mật khẩu." << endl;
            return;
        }

        cout << "Nhập mật khẩu mới: ";
        newPass = inputPasswordWithAsterisks();
        cout << "Xác nhận mật khẩu mới: ";
        confirmPass = inputPasswordWithAsterisks();

        if (newPass != confirmPass) {
            cout << "Mật khẩu xác nhận không khớp!" << endl;
            return;
        }

        pass = newPass;
        cout << "Đổi mật khẩu thành công!" << endl;
    }
    static string inputPasswordWithAsterisks() {
        string password;
        char ch;
        while ((ch = _getch()) != '\r') { // '\r' là phím Enter
            if (ch == '\b') { // Xóa ký tự nếu nhấn Backspace
                if (!password.empty()) {
                    cout << "\b \b";
                    password.pop_back();
                }
            } else {
                password.push_back(ch);
                cout << '*';
            }
        }
        cout << endl;
        return password;
    }
    void printTable() const{
        setColor(31);
		 cout << left << setw(5) << "ID"
         << setw(20) << "Chuc vu" << endl;
    	 cout << "-----------------------" << endl;
        resetColor();
    }
    void printInfo() const {
    	cout << left << setw(5) << id
         << setw(20) << name << endl;
	}
    string generateID() {
        return "";
    }
    friend std::ostream& operator<<(ostream& out, const User& user) {
        out << user.id << ',' << user.name <<  ',' 
            << user.pass;
        return out;
    }
};
#endif