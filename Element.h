#ifndef Element_H
#define Element_H

#include <iostream>
#include <string>
#include <windows.h>
#include "dohoa.h"
using namespace std;

class Element;
// Ham tach chuoi dua tren vi tri dau phay va tra ve gia tri con lai
string extractField(string &line, char c = ',') {
    size_t pos = line.find(c);
    string field = (pos != string::npos) ? line.substr(0, pos) : line;
    line = (pos != string::npos) ? line.substr(pos + 1) : "";
    return field;
}
// Chuyen so thanh xau
string toString(int number, int maxsize = 3) {
	string result = "";
	while (number > 0) {
		result = static_cast<char>((number % 10) + '0') + result;
		number /= 10;
	}
	while (result.length() < maxsize) {
        result = '0' + result;
    }
    return result;
}
// Tach so ra tu xau bat dau tu start - so nguyen duong
int toInt(string s, int start = 0) {
	int result = 0;
	for (int i = start; i < s.size(); i++) {
		if (s[i] < '0' || s[i] > '9') return -1;
		result *= 10;
		result += s[i] - '0';
	}
	return result;
}
// A->a
char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 32;
    }
    return ch;
}
string convertUpper(const string& s) {
    string res = s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            res[i] -= 32;
        }
    }
    return res;
}
// Kiem tra sub co phai substr cua str khong?
bool isSubstring(const string& str, const string& sub) {
    if (sub.length() > str.length()) return false;

    for (size_t i = 0; i <= str.length() - sub.length(); ++i) {
        bool match = true;
        for (size_t j = 0; j < sub.length(); ++j) {
            if (toLower(str[i + j]) != toLower(sub[j])) {
                match = false;
                break; 
            }
        }
        if (match) return true;
    }
    return false;
}
class Element {
protected :
	string id;
	string name;
public :
	Element() {}
	virtual ~Element() {}
    Element(const string& ID, const string& Name) : id(ID), name(convertUpper(Name)) {}
	string getId() const {return id;}
    string getName() const {return name;}
    void setId(const string& newId) {
       	id = newId;
    }
	void setName(const string& newName) {
	   	name = newName;
	}
    virtual bool isAvailabletoDelete() const {return 0;}
	virtual void printTable() const = 0; 
	virtual string generateID() = 0;
    virtual void printInfo() const = 0;  
};
bool increasingID(Element*& e1, Element*& e2) {
    return (e1->getId()) < (e2->getId());
}
bool increasingName(Element*& e1, Element*& e2) {
    return (e1->getName()) < (e2->getName());
}
#endif