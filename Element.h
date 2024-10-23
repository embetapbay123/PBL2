#ifndef Element_H
#define Element_H

#include <iostream>
#include <string>

using namespace std;

class Element;
// Chueyn so thanh xau
// Ham tach chuoi dua tren vi tri dau phay va tra ve gia tri con lai
string extractField(string &line, char c = ',') {
    size_t pos = line.find(c);
    string field = (pos != string::npos) ? line.substr(0, pos) : line;
    line = (pos != string::npos) ? line.substr(pos + 1) : "";
    return field;
}

string toString(int number) {
	string result = "";
	while (number > 0) {
		result = static_cast<char>((number % 10) + '0') + result;
		number /= 10;
	}
	while (result.length() < 3) {
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
    Element(const string& ID, const string& Name) : id(ID), name(Name) {}
	string getId() const {return id;}
    string getName() const {return name;}
    virtual Element* getNext() const = 0;
    virtual void setNext(Element* newElement) = 0;
    void setId(const string& newId) {
       	id = newId;
    }
	void setName(const string& newName) {
	   	name = newName;
	}
	virtual void printTable() = 0; 
	static string generateID();
    virtual void printInfo() const = 0;  
    virtual Element* getNext() const = 0;
};

#endif