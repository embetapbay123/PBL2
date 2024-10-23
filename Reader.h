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
    string borrowedBookIDs[MAX_BORROWED_BOOKS]; 
    Reader* next; 
public:
    static string generateID() {
        return "R" + toString(countReader++); 
    }
    Reader() : next(nullptr) {}
    Reader(string ReaderID,string Name, bool Gender, string ClassName, string Address, string PhoneNumber)
    : Person(ReaderID, Name, Gender), className(ClassName), address(Address), phoneNumber(PhoneNumber), next(nullptr) {
        if (countReader <= toInt(ReaderID, 1)) countReader = toInt(ReaderID, 1) + 1;
    }
    Reader(string Name, bool Gender, string ClassName, string Address, string PhoneNumber)
    : Person(generateID(), Name, Gender), className(ClassName), address(Address), phoneNumber(PhoneNumber), next(nullptr) {}
    string getClassName() const {return className;}
    string getAddress() const {return address;}
    string getPhoneNumber() const {return phoneNumber;}
    Reader* getNext() const {return (next);}
    void borrowBook(string bookID);
    void returnBook(string bookID);
    virtual void printTable() {
		 cout << left << setw(5) << "ID"
         << setw(30) << "Ten"
         << setw(10) << "Gioi tinh"
         << setw(15) << "Lop"
         << setw(30) << "Dia chi"
         << setw(15) << "SDT"
         << setw(10) << "So sach muon" << endl;
    	 cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
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
    void listBorrowedBooks(Book* headBook) const;
    bool findBookInListBorrowedBooks(const string& bookID) const;
    void setClassName(const string& newClassName) {
        className = newClassName;
    }
    void setAddress(const string& newAddress) {
        address = newAddress;
    }
    void setPhoneNumber(const string& newPhoneNumber) {
        phoneNumber = newPhoneNumber;
    }
    void setNext(Reader* newReader) {
    	next = newReader;
	}
};

// Implementation of Reader class
void Reader::borrowBook(string bookID) { 
    if (bookCount < MAX_BORROWED_BOOKS) {
        borrowedBookIDs[bookCount] = bookID;
        bookCount++;
    }
}

void Reader::returnBook(string bookID) { 
    for (int i = 0; i < bookCount; i++) {
        if (borrowedBookIDs[i] == bookID) {
            for (int j = i; j < bookCount - 1; j++) {
                borrowedBookIDs[j] = borrowedBookIDs[j + 1];
            }
            bookCount--;
            break;
        }
    }
}

void Reader::listBorrowedBooks(Book* headBook) const {
    if (bookCount == 0) {
        cout << "Khong co sach nao dang muon." << endl;
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        Book* current = headBook;
        while (current != nullptr) {
            if (current->getId() == borrowedBookIDs[i]) {
                current->printInfo();
            }
            current = current->getNext();
        }
    }
}

bool Reader::findBookInListBorrowedBooks(const string& bookID) const {
    for (int i = 0; i < bookCount; i++) {
        if (borrowedBookIDs[i] == bookID) {
            return true; // Tìm thấy sách trong danh sách
        }
    }
    return false; // Không tìm thấy sách
}

int Reader::countReader = 1;

#endif
