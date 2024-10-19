#ifndef LIBRARY_MANAGEMENT_H
#define LIBRARY_MANAGEMENT_H

#include <iostream>
//#include <string>
#include <ctime>

using namespace std;

const int MAX_BOOKS = 100;
const int MAX_READERS = 100;
const int MAX_TRANSACTIONS = 100;
const int MAX_BORROWED_BOOKS = 5;

// Class declarations
class Book;
class Reader;
class Library;
class Transaction;

// Class definitions
class Book {
private:
    string id;
    string title;
    string author;
    string category;
    int year;
    int pages;
    int totalCopies;
    int availableCopies;

public:
    Book();
    Book(string id, string title, string author, string category, int year, int pages, int totalCopies);
    string getId() const;
    string getTitle() const;
    int getAvailableCopies() const;
    void borrowBook();
    void returnBook();
    void printInfo() const;
};

class Reader {
private:
    string readerID;
    string name;
    string gender;
    string className;
    string address;
    string phoneNumber;
    string borrowedBookIDs[MAX_BORROWED_BOOKS]; 
    int borrowedCount;

public:
    Reader();
    Reader(string readerID, string name, string gender, string className, string address, string phoneNumber);
    string getReaderID() const;
    string getName() const;
    int getBorrowedBooksCount() const; 
    void borrowBook(string bookID);
    void returnBook(string bookID);
    void printInfo() const;
    void listBorrowedBooks(const Book books[], int totalBooks) const;
};

class Transaction {
private:
    string readerID;
    string bookID;
    time_t borrowDate;
    time_t returnDate;
    string status;

public:
    Transaction();
    Transaction(string readerID, string bookID, time_t borrowDate);
    string getReaderID() const;
    string getBookID() const;
    string getStatus() const;
    void setReturnDate(time_t returnDate);
    void setStatus(const string& status); 
    void printTransaction() const;
    bool isOverdue() const;
};

class Library {
private:
    Book books[MAX_BOOKS];
    Reader readers[MAX_READERS];
    Transaction transactions[MAX_TRANSACTIONS];
    int totalBooks;
    int totalReaders;
    int totalTransactions;

public:
    Library();
    void loadBooks();
    void loadReaders();
    void listBooks() const;
    void listReaders() const;
    Book* findBookbyID(const string& bookID);
    Reader* findReaderbyID(const string& readerID);
    void borrowBook(const string& readerID, const string& bookID);
    void returnBook(const string& readerID, const string& bookID);
    void searchBookByTitle(const string& title) const;
    void searchReaderByName(const string& name) const;
    void infoBookbyID(const string& bookID);
    void infoReaderbyID(const string& readerID);
    void overdueBooks() const;
    void listTransactions() const;
};

// Implementation of Book class
Book::Book() : year(0), pages(0), totalCopies(0), availableCopies(0) {}

Book::Book(string id, string title, string author, string category, int year, int pages, int totalCopies)
    : id(id), title(title), author(author), category(category), year(year), pages(pages), totalCopies(totalCopies), availableCopies(totalCopies) {}

string Book::getId() const { return id; }

string Book::getTitle() const { return title; }

int Book::getAvailableCopies() const { return availableCopies; }

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

void Book::printInfo() const {
    cout << "ID: " << id << ", Tieu de: " << title << ", Tac gia: " << author
         << ", The loai: " << category << ", Nam xuat ban: " << year << ", So trang: " << pages
         << ", So luong sach hien co: " << availableCopies << "/" << totalCopies << endl;
}

// Implementation of Reader class
Reader::Reader() : borrowedCount(0) {}

Reader::Reader(string readerID, string name, string gender, string className, string address, string phoneNumber)
    : readerID(readerID), name(name), gender(gender), className(className), address(address), phoneNumber(phoneNumber), borrowedCount(0) {}

string Reader::getReaderID() const { return readerID; }

string Reader::getName() const { return name; }

int Reader::getBorrowedBooksCount() const {
    return borrowedCount; 
}

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

void Reader::printInfo() const {
    cout << "Reader ID: " << readerID << ", Ten: " << name << ", Gioi tinh: " << gender
         << ", Lop: " << className << ", Dia chi: " << address << ", SDT: " << phoneNumber
         << ", So sach dang muon: " << borrowedCount << endl; 
}

void Reader::listBorrowedBooks(const Book books[], int totalBooks) const {
    cout << "Danh sach sach dang muon cua doc gia " << name << " (ID: " << readerID << "):" << endl;
    if (borrowedCount == 0) {
        cout << "Khong co sach nao dang muon." << endl;
        return;
    }
    for (int i = 0; i < borrowedCount; i++) {
        for (int j = 0; j < totalBooks; j++) {
            if (books[j].getId() == borrowedBookIDs[i]) {
                books[j].printInfo();
            }
        }
    }
}

// Implementation of Transaction class
Transaction::Transaction() : borrowDate(0), returnDate(0), status("Unreturned") {}

Transaction::Transaction(string readerID, string bookID, time_t borrowDate)
    : readerID(readerID), bookID(bookID), borrowDate(borrowDate), returnDate(0), status("Unreturned") {}

string Transaction::getReaderID() const { return readerID; }

string Transaction::getBookID() const { return bookID; }

string Transaction::getStatus() const { return status; }

void Transaction::setReturnDate(time_t returnDate) { this->returnDate = returnDate; }

void Transaction::setStatus(const string& status) { this->status = status; }

void Transaction::printTransaction() const {
    cout << "Reader ID: " << readerID << ", Book ID: " << bookID
         << ", Borrow Date: " << ctime(&borrowDate)
         << ", Status: " << status << endl;
}

bool Transaction::isOverdue() const {
    time_t now = time(0);
    double secondsDiff = difftime(now, borrowDate);
    int daysDiff = secondsDiff / (60 * 60 * 24);
    return (daysDiff > 30 && status == "Unreturned");
}

// Implementation of Library class
Library::Library() : totalBooks(0), totalReaders(0), totalTransactions(0) {}

void Library::loadBooks() {
    books[totalBooks++] = Book("B001", "Programming in C++", "Bjarne Stroustrup", "Tech", 2013, 1376, 5);
    books[totalBooks++] = Book("B002", "Effective Java", "Joshua Bloch", "Tech", 2018, 412, 3);
}

void Library::loadReaders() {
    readers[totalReaders++] = Reader("R001", "Nguyen Van A", "Male", "12A1", "HCMC", "0901234567");
    readers[totalReaders++] = Reader("R002", "Tran Thi B", "Female", "12A2", "Hanoi", "0987654321");
}

void Library::listBooks() const {
    for (int i = 0; i < totalBooks; i++) {
        books[i].printInfo();
    }
}

void Library::listReaders() const {
    for (int i = 0; i < totalReaders; i++) {
        readers[i].printInfo();
    }
}

Book* Library::findBookbyID(const string& bookID) {
    for (int i = 0; i < totalBooks; i++) {
        if (books[i].getId() == bookID) {
            return &books[i];
        }
    }
    return nullptr;
}

Reader* Library::findReaderbyID(const string& readerID) {
    for (int i = 0; i < totalReaders; i++) {
        if (readers[i].getReaderID() == readerID) {
            return &readers[i];
        }
    }
    return nullptr;
}

void Library::borrowBook(const string& readerID, const string& bookID) {
    Book* book = findBookbyID(bookID);
    Reader* reader = findReaderbyID(readerID);
	
	 if (reader && book) {
        if (book->getAvailableCopies() == 0) {
            cout << "Sach da het!" << endl;
        } else if (reader->getBorrowedBooksCount() == MAX_BORROWED_BOOKS){
            cout << "So sach muon toi da!" << endl;
        } else {
        	book->borrowBook();
            reader->borrowBook(bookID);
            transactions[totalTransactions++] = Transaction(readerID, bookID, time(0));
            cout << "Muon sach thanh cong!" << endl;
		}
    } else {
        cout << "Doc gia hoac sach khong ton tai!" << endl;
    }
	
}

void Library::returnBook(const string& readerID, const string& bookID) {
    for (int i = 0; i < totalTransactions; i++) {
        if (transactions[i].getReaderID() == readerID && transactions[i].getBookID() == bookID && transactions[i].getStatus() == "Unreturned") {
        	Book* book = findBookbyID(bookID);
    		Reader* reader = findReaderbyID(readerID);
    		if (reader) {
           		reader->returnBook(bookID);
			}
			if (book) {
				book->returnBook();
			}
            time_t now = time(0);
            transactions[i].setReturnDate(now);
            transactions[i].setStatus("Returned");
            cout << "Tra sach thanh cong" << endl;
            return;
       }
    }
    cout << "Khong tim thay giao dich muon sach" << endl;
}

void Library::searchBookByTitle(const string& title) const {
    bool found = false;
    for (int i = 0; i < totalBooks; i++) {
        bool match = true;
        for (int j = 0; j < title.size(); j++) {
            if (tolower(books[i].getTitle()[j]) != tolower(title[j])) {
                match = false;
                break;
            }
        }
        if (match) {
            books[i].printInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay sach." << endl;
    }
}

void Library::searchReaderByName(const string& name) const {
    bool found = false;
    for (int i = 0; i < totalReaders; i++) {
        bool match = true;
        for (int j = 0; j < name.size(); j++) {
            if (tolower(readers[i].getName()[j]) != tolower(name[j])) {
                match = false;
                break;
            }
        }
        if (match) {
            readers[i].printInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay doc gia." << endl;
    }
}

void Library::infoBookbyID(const string& bookID) {
    Book* book = findBookbyID(bookID);
    if (book) {
        book->printInfo();
    } else {
        cout << "Khong tim thay sach." << endl;
    }
}

void Library::infoReaderbyID(const string& readerID) {
    Reader* reader = findReaderbyID(readerID);
    if (reader) {
        reader->printInfo();
    } else {
        cout << "Khong tim thay doc gia." << endl;
    }
}

void Library::overdueBooks() const {
    cout << "Danh sach cac giao dich qua han:" << endl;
    bool found = false;
    for (int i = 0; i < totalTransactions; i++) {
        if (transactions[i].isOverdue()) {
            transactions[i].printTransaction();
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co giao dich qua han." << endl;
    }
}

void Library::listTransactions() const {
    for (int i = 0; i < totalTransactions; i++) {
        transactions[i].printTransaction();
    }
}

#endif

