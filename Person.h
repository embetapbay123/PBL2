#ifndef Person_H
#define Persom_H

#include "Element.h"
#include "Date.h"
#include <iomanip>
using namespace std;

class Person;

class Person: public Element {
protected:
    bool gender; 
    int bookCount;
public:
    Person() {}
    Person(string personID, string Name, bool Gender)
    : Element(personID, Name), gender(Gender), bookCount(0) {}
    bool getGender() {return gender;}
    int getbookCount() {return bookCount;}
    void setGender(const bool& newGender) {
        gender = newGender;
    }
    void setCountBook(const int& newCountBook) {
        bookCount = newCountBook;
    }
    void incresingBookCount () {
        bookCount++;
    }
    void decresingBookCount () {
        bookCount--;
    }
};

#endif
