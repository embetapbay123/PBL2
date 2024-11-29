#ifndef Reader_H
#define Reader_H

#include "Person.h"
#include "Book.h"

using namespace std;

const int MAX_BORROWED_BOOKS = 5;

class Reader;

class Reader: public Person {
private:
    static int countReader;
    string className;
    string address;
    string phoneNumber;
public:
    string generateID() {
        return "R" + toString(countReader++); 
    }
    Reader() {}
    Reader(string ReaderID,string Name, bool Gender, string ClassName, string Address, string PhoneNumber)
    : Person(ReaderID, Name, Gender), className(convertUpper(ClassName)), address(convertUpper(Address)), phoneNumber(PhoneNumber) {
        if (countReader <= toInt(ReaderID, 1)) countReader = toInt(ReaderID, 1) + 1;
    }
    Reader(string Name, bool Gender, string ClassName, string Address, string PhoneNumber)
    : Person(generateID(), Name, Gender), className(convertUpper(ClassName)), address(convertUpper(Address)), phoneNumber(PhoneNumber) {}
    string getClassName() const {return className;}
    string getAddress() const {return address;}
    string getPhoneNumber() const {return phoneNumber;}
    bool isAvailabletoBorrow() const{
        return bookCount != MAX_BORROWED_BOOKS;
    }
    void borrowBook();
    void returnBook();
    void printTable() const{
        setColor(31);
		 cout << left << setw(5) << "ID"
         << setw(30) << "Ten"
         << setw(10) << "Gioi tinh"
         << setw(15) << "Lop"
         << setw(30) << "Dia chi"
         << setw(15) << "SDT"
         << setw(10) << "So sach muon" << endl;
    	 cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        resetColor();
    }
    void printInfo() const {
    	cout << left << setw(5) << id
         << setw(30) << name
         << setw(10) << (gender ? "Nam" : "Nu")
         << setw(15) << className
         << setw(30) << address
         << setw(15) << phoneNumber
         << setw(10) << bookCount << endl;
	}
    void setClassName(const string& newClassName) {
        className = newClassName;
    }
    void setAddress(const string& newAddress) {
        address = newAddress;
    }
    void setPhoneNumber(const string& newPhoneNumber) {
        phoneNumber = newPhoneNumber;
    }
    friend std::ostream& operator<<(ostream& out, const Reader& reader) {
        out << reader.id << ',' << reader.name <<  ',' 
            << reader.gender << ','
            << reader.className << ','
            << reader.address << ','
            << reader.phoneNumber;
        return out;
    }
};

// Implementation of Reader class
void Reader::borrowBook() { 
    if (bookCount < MAX_BORROWED_BOOKS) {
        bookCount++;
    }
}

void Reader::returnBook() { 
    if (bookCount > 0) bookCount--;
}

int Reader::countReader = 1;

#endif
