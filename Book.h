#ifndef Book_H
#define Book_H

#include <iostream>
#include <iomanip>
#include "Element.h"
#include "Author.h"
using namespace std;

class Book;

class Book : public Element {
private:
    static int countBook;
    Author* authorPtr;
    Category* categoryPtr;
    int year;
    int pages;
    int totalCopies;
    int availableCopies;
public:
    string generateID() {
        return "B" + toString(countBook++); 
    }
    Book() : year(0), pages(0), totalCopies(0), availableCopies(0){}
    Book(string bookID, string title, Author* AuthorPtr, Category* CategoryPtr, int Year, int Pages, int TotalCopies) : 
        Element(bookID, title), authorPtr(AuthorPtr), categoryPtr(CategoryPtr), year(Year), pages(Pages), 
            totalCopies(TotalCopies), availableCopies(TotalCopies) {
        if (authorPtr != nullptr) authorPtr->incresingBookCount();
        if (categoryPtr != nullptr) categoryPtr->incresingBookCount();
        if (countBook <= toInt(bookID, 1)) countBook = toInt(bookID, 1) + 1;
    }
    Book(string title, Author* AuthorPtr, Category* CategoryPtr, int Year, int Pages, int TotalCopies) : 
        Element(generateID(), title), authorPtr(AuthorPtr), categoryPtr(CategoryPtr), year(Year), pages(Pages),
            totalCopies(TotalCopies), availableCopies(TotalCopies) {}
    ~Book() {
        if (authorPtr != nullptr) authorPtr->decresingBookCount();
        if (categoryPtr != nullptr) categoryPtr->decresingBookCount();
    }
    Author* getAuthorPtr() const {return authorPtr;}
    string getAuthorID() const {return authorPtr->getId();}
    Category* getCategoryPtr() const {return categoryPtr;}
    string getCategoryID() const {return categoryPtr->getId();}
	int getYear() const {return year;}
	int getPages() const {return pages;}
	int getTotalCopies() const {return totalCopies;}
    int getAvailableCopies() const {return availableCopies;}
    bool isAvailabletoDelete() const{
        return totalCopies == availableCopies;
    }
    void borrowBook();
    void returnBook();
    void printTable() const{
        setColor(31);
		cout << left << setw(5) << "ID"
         << setw(35) << "Tieu de"
         << setw(20) << "Tac gia"
         << setw(15) << "The loai"
         << setw(5) << "Nam"
         << setw(10) << "Trang"
         << setw(15) << "Sach hien co"
         << "Toan bo" << endl;
    	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        resetColor();
	}
	void printInfo() const {
    	cout << left << setw(5) << id
         << setw(35) << name
         << setw(20) << authorPtr->getName()
         << setw(15) << categoryPtr->getName()
         << setw(5) << year
         << setw(10) << pages
         << setw(15) << availableCopies << "/" << totalCopies << endl;
	}
    void setAuthorPtr(Author* newAuthorPtr) {
        authorPtr = newAuthorPtr;
    }
    void setCategory(Category* newCategoryPtr) {
        categoryPtr = newCategoryPtr;
    }
    void setYear(int newYear) {
        year = newYear;
    }
    void setPages(int newPages) {
        pages = newPages;
    }
    void setTotalCopies(int newTotalCopies) {
        totalCopies = newTotalCopies;
        availableCopies = newTotalCopies;
    }
};

// Implementation of Book class

void Book::borrowBook() {
    if (availableCopies > 0) {
        availableCopies--;
    }
}

void Book::returnBook() {
    if (availableCopies < totalCopies) {
        availableCopies++;
    }
}

int Book::countBook = 1;

#endif

