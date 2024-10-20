#ifndef Element_H
#define Element_H

#include <iostream>
#include <string>

using namespace std;

class Element;

string toString(int number) {
	string result = "";
	while (number > 0) {
		result = static_cast<char>((number % 10) + '0') + result;
		number /= 10;
	}
	while (result.length() < 3) {
        result = '0' + result;
    }
    return result;
}

class Element {
protected :
	string id;
	string name;
public :
	Element() {}
	virtual ~Element() {}
    Element(const string& ID, const string& Name) : id(ID), name(Name) {}
	string getId() const {return id;}
    string getName() const {return name;}
    void setId(const string& newId) {
       	id = newId;
    }
	void setName(const string& newName) {
	   	name = newName;
	}
	static void printTable(); 
	static string generateID();
    virtual void printInfo() const = 0;  
    virtual Element* getNext() const = 0;
};

#endif