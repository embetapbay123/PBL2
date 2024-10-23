#ifndef Author_H
#define Author_H

#include "Element.h"
#include <iomanip>
using namespace std;

class Author;

class Author: public Element {
private:
    static int countAuthor;
    bool gender; // 0 là nam, 1 là nữ
    int bornYear;
    int countBook;
    Author* next; 
public:
    static string generateID() {
        return "A" + toString(countAuthor++); 
    }
    Author() : next(nullptr) {}
    Author(string Name, bool Gender, int BornYear)
    : Element(generateID(), Name), gender(Gender), bornYear(BornYear), countBook(0), next(nullptr) {}
    bool getGender() {return gender;}
    int getBornYear() {return bornYear;}
    int getCountBook() {return countBook;}
    Author* getNext() const {return (next);}
    void printTable() {
		 cout << left << setw(5) << "ID"
         << setw(30) << "Ten"
         << setw(10) << "Gioi tinh"
         << setw(10) << "Nam sinh" << endl;
    	 cout << "---------------------------------------------------" << endl;
	}
    void printInfo() const {
    	cout << left << setw(5) << id
         << setw(30) << name
         << setw(10) << (gender ? "Nam" : "Nu")
         << setw(10) << bornYear << endl;
	}
    void setGender(const bool& newGender) {
        gender = newGender;
    }
    void setBornYear(const int& newBornYear) {
        bornYear = newBornYear;
    }
    void setCountBook(const int& newCountBook) {
        countBook = newCountBook;
    }
    void setNext(Author* newAuthor) {
    	next = newAuthor;
	}
};

// Implementation of Reader class

int Author::countAuthor = 1;

#endif
