#ifndef Element_H
#define Element_H

#include <iostream>
#include <string>

using namespace std;

class Element;

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
    virtual void printInfo() const = 0;  
    virtual Element* getNext() const = 0;
};

#endif
