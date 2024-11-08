#ifndef Person_H
#define Person_H

#include "Category.h"
using namespace std;

class Person;

class Person: public Category {
protected:
    bool gender; 
public:
    Person() {}
    Person(string personID, string Name, bool Gender)
    : Category(personID, Name), gender(Gender) {}
    bool getGender() const {return gender;}
    void setGender(const bool& newGender) {
        gender = newGender;
    }
};
#endif
