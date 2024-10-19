#ifndef BookReader_H
#define BookReader_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

const int MAX_BORROWED_BOOKS = 5;

class Element;
class Book;
class Reader;

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

class Reader: public Element {
private:
    string gender;
    string className;
    string address;
    string phoneNumber;
    string borrowedBookIDs[MAX_BORROWED_BOOKS]; 
    int borrowedCount;
    Reader* next; 
public:
    Reader();
    Reader(string readerID, string name, string gender, string className, string address, string phoneNumber);
    string getGender() const {return gender;}
    string getClassName() const {return className;}
    string getAddress() const {return address;}
    string getPhoneNumber() const {return phoneNumber;}
    int getBorrowedBooksCount() const {return borrowedCount;}
    Reader* getNext() const {return (next);}
    void borrowBook(string bookID);
    void returnBook(string bookID);
    static void printTable() {
		 cout << left << setw(10) << "ID"
         << setw(30) << "Ten"
         << setw(10) << "Gioi tinh"
         << setw(15) << "Lop"
         << setw(30) << "Dia chi"
         << setw(15) << "SDT"
         << setw(10) << "So sach muon" << endl;
    	 cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	}
    void printInfo() const {
    	cout << left << setw(10) << id
         << setw(30) << name
         << setw(10) << gender
         << setw(15) << className
         << setw(30) << address
         << setw(15) << phoneNumber
         << setw(10) << borrowedCount << endl;
	}
    void listBorrowedBooks(Book* headBook) const;
    void setGender(const string& newGender) {
        gender = newGender;
    }
    void setClassName(const string& newClassName) {
        className = newClassName;
    }
    void setAddress(const string& newAddress) {
        address = newAddress;
    }
    void setPhoneNumber(const string& newPhoneNumber) {
        phoneNumber = newPhoneNumber;
    }
    void setNext(Reader* newReader) {
    	next = newReader;
	}
};

// Implementation of Book class
Book::Book() : year(0), pages(0), totalCopies(0), availableCopies(0), next(nullptr) {}

Book::Book(string id, string title, string author, string category, int year, int pages, int totalCopies)
    : Element(id, title), author(author), category(category), year(year), pages(pages), totalCopies(totalCopies), availableCopies(totalCopies), next(nullptr) {}

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

// Implementation of Reader class
Reader::Reader() : borrowedCount(0), next(nullptr) {}

Reader::Reader(string readerID, string name, string gender, string className, string address, string phoneNumber)
    : Element(readerID, name), gender(gender), className(className), address(address), phoneNumber(phoneNumber), borrowedCount(0), next(nullptr) {}

void Reader::borrowBook(string bookID) { 
    if (borrowedCount < MAX_BORROWED_BOOKS) {
        borrowedBookIDs[borrowedCount] = bookID;
        borrowedCount++;
    }
}

void Reader::returnBook(string bookID) { 
    for (int i = 0; i < borrowedCount; i++) {
        if (borrowedBookIDs[i] == bookID) {
            for (int j = i; j < borrowedCount - 1; j++) {
                borrowedBookIDs[j] = borrowedBookIDs[j + 1];
            }
            borrowedCount--;
            break;
        }
    }
}

void Reader::listBorrowedBooks(Book* headBook) const {
    cout << "Danh sach sach dang muon cua doc gia " << name << " (ID: " << id << "):" << endl;
    if (borrowedCount == 0) {
        cout << "Khong co sach nao dang muon." << endl;
        return;
    }
    for (int i = 0; i < borrowedCount; i++) {
        Book* current = headBook;
        while (current != nullptr) {
            if (current->getId() == borrowedBookIDs[i]) {
                current->printInfo();
            }
            current = current->getNext();
        }
    }
}

#endif

