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
public:
    string generateID() {
        return "A" + toString(countAuthor++); 
    }
    Author() {}
    Author(string AuthorID, string Name, bool Gender, int BornYear)
    : Person(AuthorID, Name, Gender), bornYear(BornYear){
        if (countAuthor <= toInt(AuthorID, 1)) countAuthor = toInt(AuthorID, 1) + 1;
    }
    Author(string Name, bool Gender, int BornYear)
    : Person(generateID(), Name, Gender), bornYear(BornYear){}
    int getBornYear() {return bornYear;}
    void printTable() const {
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
};

int Author::countAuthor = 1;

#endif
