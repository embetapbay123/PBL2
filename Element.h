#ifndef Element_H
#define Element_H

#include <iostream>

using namespace std;

class Element;

class Element {
protected :
	string id;
	string name;
public :
	Element() {}
    Element(const string& id, const string& name) : id(id), name(name) {}
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

