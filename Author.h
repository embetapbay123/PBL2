#ifndef Author_H
#define Author_H

#include "Person.h"
#include <iomanip>
using namespace std;

class Author;

class Author: public Person {
private:
    static int countAuthor;
    int bornYear;
    Author* next; 
public:
    static string generateID() {
        return "A" + toString(countAuthor++); 
    }
    Author() : next(nullptr) {}
    Author(string AuthorID,string Name, bool Gender, int BornYear)
    : Person(AuthorID, Name, Gender), bornYear(BornYear), next(nullptr) {
        if (countAuthor <= toInt(AuthorID, 1)) countAuthor = toInt(AuthorID, 1) + 1;
    }
    Author(string Name, bool Gender, int BornYear)
    : Person(generateID(), Name, Gender), bornYear(BornYear), next(nullptr) {}
    int getBornYear() {return bornYear;}
    Author* getNext() const {return (next);}
    void printTable() {
		 cout << left << setw(5) << "ID"
         << setw(30) << "Ten"
         << setw(10) << "Gioi tinh"
         << setw(10) << "Nam sinh"
         << setw(10) << "So sach" << endl;
    	 cout << "---------------------------------------------------" << endl;
	}
    void printInfo() const {
    	cout << left << setw(5) << id
         << setw(30) << name
         << setw(10) << (gender ? "Nam" : "Nu")
         << setw(10) << bornYear
         << setw(10) << bookCount << endl;
	}
    void setBornYear(const int& newBornYear) {
        bornYear = newBornYear;
    }
    void setNext(Element* newElement) {
    	next = static_cast<Author*> (newElement);
	}
};

// Implementation of Reader class

int Author::countAuthor = 1;

#endif
