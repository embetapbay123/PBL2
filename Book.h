#ifndef Book_H
#define Book_H

#include <iostream>
#include <iomanip>
#include "Element.h"
using namespace std;

class Book;

class Book : public Element {
private:
    string author;
    string category;
    int year;
    int pages;
    int totalCopies;
    int availableCopies;
    Book* next; 

public:
    Book();
    Book(string id, string title, string author, string category, int year, int pages, int totalCopies);
    string getAuthor() const {return author;}
	int getYear() const {return year;}
	int getPages() const {return pages;}
	int getTotalCopies() const {return totalCopies;}
    int getAvailableCopies() const {return availableCopies;}
    Book* getNext() const {
    	return (next); 
	}
    void borrowBook();
    void returnBook();
    static void printTable() {
		cout << left << setw(10) << "ID"
         << setw(35) << "Tieu de"
         << setw(20) << "Tac gia"
         << setw(15) << "The loai"
         << setw(10) << "Nam"
         << setw(10) << "Trang"
         << setw(15) << "Sach hien co/Toan bo" << endl;
    	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	}
	void printInfo() const {
    	cout << left << setw(10) << id
         << setw(35) << name
         << setw(20) << author
         << setw(15) << category
         << setw(10) << year
         << setw(10) << pages
         << setw(15) << availableCopies << "/" << totalCopies << endl;
	}
    void setAuthor(const string& newAuthor) {
        author = newAuthor;
    }
    void setCategory(const string& newCategory) {
        category = newCategory;
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
    void setNext(Book* newBook) {next = newBook;}
};

// Implementation of Book class
Book::Book() : year(0), pages(0), totalCopies(0), availableCopies(0), next(nullptr) {}

Book::Book(string ID, string title, string Author, string Category, int Year, int Pages, int TotalCopies)
    : Element(ID, title), author(Author), category(Category), year(Year), pages(Pages), totalCopies(TotalCopies), availableCopies(TotalCopies), next(nullptr) {}

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

#endif

