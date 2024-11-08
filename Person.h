#ifndef Person_H
#define Person_H

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
    bool getGender() const {return gender;}
    int getbookCount() const {return bookCount;}
    bool isAvailabletoDelete() const{
        return bookCount == 0;
    }
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
