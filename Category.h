#ifndef Category_H
#define Category_H

#include "Element.h"
#include <iomanip>
using namespace std;

class Category;

class Category: public Element {
protected:
    static int countCategory;
    int bookCount;
public:
    string generateID() {
        return "C" + toString(countCategory++); 
    }
    Category() {}
    Category(string CategoryID, string Name) : Element(CategoryID, Name), bookCount(0) {
        if (countCategory <= toInt(CategoryID, 1)) countCategory = toInt(CategoryID, 1) + 1;
    }
    Category(string Name) : Element(generateID(), Name), bookCount(0) {}
    int getbookCount() const {return bookCount;}
    bool isAvailabletoDelete() const{
        return bookCount == 0;
    }
    void printTable() const {
        setColor(31);
		 cout << left << setw(5) << "ID"
         << setw(30) << "Ten the loai"
         << setw(10) << "So sach" << endl;
    	 cout << "--------------------------------------------" << endl;
        resetColor();
	}
    void printInfo() const {
    	cout << left << setw(5) << id
         << setw(30) << name
         << setw(10) << bookCount << endl;
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
    friend std::ostream& operator<<(ostream& out, const Category &category) {
        out << category.id << ',' << category.name;
        return out;
    }
};
int Category::countCategory = 0;

bool increasingBookCount(Element*& e1, Element*& e2) {
    Category* category1Ptr = dynamic_cast<Category*> (e1);
    Category* category2Ptr = dynamic_cast<Category*> (e2);
    return (category1Ptr->getbookCount()) < (category2Ptr->getbookCount());
}
#endif
