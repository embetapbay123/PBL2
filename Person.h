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
    Date birthDay;
    int bookCount;
public:
    Person() {}
    Person(string personID, string Name, bool Gender, Date BirthDay)
    : Element(personID, Name), gender(Gender), birthDay(BirthDay), bookCount(0) {}
    bool getGender() {return gender;}
    int getCountBook() {return bookCount;}
   
    void setGender(const bool& newGender) {
        gender = newGender;
    }
    void setBirthDay(const int& newBirthDay) {
        birthDay = newBirthDay;
    }
    void setCountBook(const int& newCountBook) {
        bookCount = newCountBook;
    }
};

#endif
