#ifndef Reader_H
#define Reader_H

#include "Element.h"
#include "Book.h"

using namespace std;

const int MAX_BORROWED_BOOKS = 5;

class Reader;

class Reader: public Element {
private:
    static int countReader;
    string gender;
    string className;
    string address;
    string phoneNumber;
    string borrowedBookIDs[MAX_BORROWED_BOOKS]; 
    int borrowedCount;
    Reader* next; 
public:
    static string generateID() {
        return "R" + toString(countReader++); 
    }
    Reader() : borrowedCount(0), next(nullptr) {}
    Reader(string Name, string Gender, string ClassName, string Address, string PhoneNumber)
    : Element(generateID(), Name), gender(Gender), className(ClassName), address(Address), phoneNumber(PhoneNumber), borrowedCount(0), next(nullptr) {}
    string getGender() const {return gender;}
    string getClassName() const {return className;}
    string getAddress() const {return address;}
    string getPhoneNumber() const {return phoneNumber;}
    int getBorrowedBooksCount() const {return borrowedCount;}
    Reader* getNext() const {return (next);}
    void borrowBook(string bookID);
    void returnBook(string bookID);
    static void printTable() {
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
         << setw(10) << gender
         << setw(15) << className
         << setw(30) << address
         << setw(15) << phoneNumber
         << setw(10) << borrowedCount << endl;
	}
    void listBorrowedBooks(Book* headBook) const;
    bool findBookInListBorrowedBooks(const string& bookID) const;
    void setGender(const string& newGender) {
        gender = newGender;
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
    void setNext(Reader* newReader) {
    	next = newReader;
	}
};

// Implementation of Reader class
void Reader::borrowBook(string bookID) { 
    if (borrowedCount < MAX_BORROWED_BOOKS) {
        borrowedBookIDs[borrowedCount] = bookID;
        borrowedCount++;
    }
}

void Reader::returnBook(string bookID) { 
    for (int i = 0; i < borrowedCount; i++) {
        if (borrowedBookIDs[i] == bookID) {
            for (int j = i; j < borrowedCount - 1; j++) {
                borrowedBookIDs[j] = borrowedBookIDs[j + 1];
            }
            borrowedCount--;
            break;
        }
    }
}

void Reader::listBorrowedBooks(Book* headBook) const {
    if (borrowedCount == 0) {
        cout << "Khong co sach nao dang muon." << endl;
        return;
    }
    for (int i = 0; i < borrowedCount; i++) {
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
    for (int i = 0; i < borrowedCount; i++) {
        if (borrowedBookIDs[i] == bookID) {
            return true; // Tìm thấy sách trong danh sách
        }
    }
    return false; // Không tìm thấy sách
}

int Reader::countReader = 1;

#endif
