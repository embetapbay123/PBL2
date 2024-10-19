#ifndef LM_H
#define LM_H

#include "Element.h"
#include "Book.h"
#include "Reader.h"
#include "Transaction.h"
#include <fstream>
using namespace std;

class Library;

class Library {
private:
    Book* bookHead; 
    Reader* readerHead;
    Transaction* transactionHead; 
    int currentBookID; 
    int currentReaderID; 

public:
    Library();
    ~Library(); 
    string newIDBook();
    string newIDReader();
    void loadBooks();
    void loadReaders();
    Book* createNewBook(string title, string author, string category, int year, int pages, int totalCopies) {
	    Book* newBook = new Book(this->newIDBook(), title, author, category, year, pages, totalCopies);
	    return newBook;
	}
	Reader* createNewReader(string name, string gender, string className, string address, string phoneNumber) {
	    Reader* newReader = new Reader(this->newIDReader(), name, gender, className, address, phoneNumber);
	    return newReader;
	}
    void addBookAtHead(Book* newBook);
    void addBookAtEnd(Book* newBook);
	void addBookAtIndex(int index, Book* newBook);
	void addReaderAtHead(Reader* newReader);
    void addReaderAtEnd(Reader* newReader);
	void addReaderAtIndex(int index, Reader* newReader);
	void deleteBook(const string& bookID);
	void deleteReader(const string& readerID);
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

// Implementation of Library class
Library::Library() : bookHead(nullptr), readerHead(nullptr), transactionHead(nullptr), currentBookID(1) ,currentReaderID(1) {}

Library::~Library() {
    Book* currentBook = bookHead;
    while (currentBook != nullptr) {
        Book* nextBook = currentBook->getNext();
        delete currentBook;
        currentBook = nextBook;
    }

    Reader* currentReader = readerHead;
    while (currentReader != nullptr) {
        Reader* nextReader = currentReader->getNext();
        delete currentReader;
        currentReader = nextReader;
    }

    Transaction* currentTransaction = transactionHead;
    while (currentTransaction != nullptr) {
        Transaction* nextTransaction = currentTransaction->getNext();
        delete currentTransaction;
        currentTransaction = nextTransaction;
    }
}

// Ham tach chuoi dua tren vi tri dau phay va tra ve gia tri con lai
string extractField(string &line) {
    size_t pos = line.find(',');
    string field = (pos != string::npos) ? line.substr(0, pos) : line;
    line = (pos != string::npos) ? line.substr(pos + 1) : "";
    return field;
}
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
string Library::newIDBook() {
	return ("S" + toString(currentBookID++));
}
void Library::loadBooks() {
    ifstream file("books.txt");
    if (!file.is_open()) {
        cout << "Khong the mo file books.txt" << endl;
        return;
    }

    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;

        string title = extractField(line);
        string author = extractField(line);
        string category = extractField(line);
        string yearStr = extractField(line);
        string pagesStr = extractField(line);
        string totalCopiesStr = extractField(line);

        if (title.empty()) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac thieu ten sach." << endl;
            continue;
        }
        if (author.empty()) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac thieu tac gia." << endl;
            continue;
        }
        if (category.empty()) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac thieu the loai." << endl;
            continue;
        }

        int year = stoi(yearStr);
        if (year <= 0) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac nam khong hop le." << endl;
            continue;
        }
        int pages = stoi(pagesStr);
        if (pages <= 0) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac so trang khong hop le." << endl;
            continue;
        }
        int totalCopies = stoi(totalCopiesStr);
        if (totalCopies <= 0) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac so luong khong hop le." << endl;
            continue;
        }

        Book* newBook = new Book(this->newIDBook(), title, author, category, year, pages, totalCopies);

        // Them vao danh sach lien ket
        newBook->setNext(bookHead);
        bookHead = newBook;
    }

    file.close();
}

string Library::newIDReader() {
	return ("R" + toString(currentReaderID++));
}

void Library::loadReaders() {
    ifstream file("readers.txt");
    if (!file.is_open()) {
        cout << "Khong the mo file readers.txt" << endl;
        return;
    }

    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;

        string name = extractField(line);
        string gender = extractField(line);
        string className = extractField(line);
        string address = extractField(line);
        string phoneNumber = extractField(line);

        if (name.empty()) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac thieu ten doc gia." << endl;
            continue;
        }
        if (gender.empty()) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac thieu gioi tinh." << endl;
            continue;
        }
        if (className.empty()) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac thieu lop." << endl;
            continue;
        }
        if (address.empty()) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac thieu dia chi." << endl;
            continue;
        }
        if (phoneNumber.empty()) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac thieu so dien thoai." << endl;
            continue;
        }

        // Tao doi tuong Reader moi
        Reader* newReader = new Reader(this->newIDReader(), name, gender, className, address, phoneNumber);

        // Them vao danh sach lien ket
        newReader->setNext(readerHead);
        readerHead = newReader;
    }

    file.close();
}

void Library::addBookAtHead(Book* newBook) {
    newBook->setNext(bookHead);
    bookHead = newBook;
}

void Library::addBookAtEnd(Book* newBook) {
    if (bookHead == nullptr) {
        bookHead = newBook;
    } else {
        Book* current = bookHead;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newBook);
    }
}

void Library::addBookAtIndex(int index, Book* newBook) {
    if (index < 0) {
        cout << "Chi so khong hop le!" << endl;
        return;
    }

    if (index == 0) {
        addBookAtHead(newBook);
        return;
    }

    Book* current = bookHead;
    for (int i = 0; i < index - 1; i++) {
        if (current == nullptr) {
            cout << "Chi so vuot qua so luong sach!" << endl;
            return;
        }
        current = current->getNext();
    }

    newBook->setNext(current->getNext());
    current->setNext(newBook);
}

void Library::addReaderAtHead(Reader* newReader) {
    newReader->setNext(readerHead); 
    readerHead = newReader; 
}

void Library::addReaderAtEnd(Reader* newReader) {
    if (readerHead == nullptr) { 
        readerHead = newReader; 
    } else {
        Reader* current = readerHead; 
        while (current->getNext() != nullptr) { 
            current = current->getNext();
        }
        current->setNext(newReader); 
    }
}


void Library::addReaderAtIndex(int index, Reader* newReader) {
    if (index < 0) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }
    if (index == 0) {
        addReaderAtHead(newReader); 
    } else {
        Reader* current = readerHead;
        for (int i = 0; i < index - 1; i++) { 
            if (current == nullptr) {
                cout << "Vi tri vuot qua danh sach!" << endl;
                return; 
            }
            current = current->getNext();
        }
        newReader->setNext(current->getNext()); 
        current->setNext(newReader);
    }
}

void Library::deleteBook(const string& bookID) {
    if (!bookHead) {
        cout << "Khong ton tai sach co id " << bookID << endl;
        return;
    }

    if (bookHead->getId() == bookID) {
        Book* temp = bookHead;
        bookHead = bookHead->getNext(); 
        delete temp; 
        cout << "Xoa thanh cong!" << endl;
        return;
    }

    Book* current = bookHead;

    while (current->getNext() && current->getNext()->getId() != bookID) {
        current = current->getNext();
    }

    if (!current->getNext()) {
        cout << "Khong ton tai sach co id " << bookID << endl;
        return;
    }

    Book* temp = current->getNext();
    current->setNext(current->getNext()->getNext()); 
    delete temp; 
    cout << "Xoa thanh cong!" << endl;
}

void Library::deleteReader(const string& readerID) {
    if (!readerHead) {
        cout << "Khong ton tai nguoi doc co id " << readerID << endl;
        return;
    }

    if (readerHead->getId() == readerID) {
        Reader* temp = readerHead;
        readerHead = readerHead->getNext(); 
        delete temp; 
        cout << "Xoa thanh cong!" << endl;
        return;
    }

    Reader* current = readerHead;

    while (current->getNext() && current->getNext()->getId() != readerID) {
        current = current->getNext();
    }

    if (!current->getNext()) {
        cout << "Khong ton tai sach co id " << readerID << endl;
        return;
    }

    Reader* temp = current->getNext();
    current->setNext(current->getNext()->getNext()); 
    delete temp; 
    cout << "Xoa thanh cong!" << endl;
}

void Library::listBooks() const {
    Book::printTable();
    Book* current = bookHead;
    while (current != nullptr) {
        current->printInfo();
        current = current->getNext();
    }
}

void Library::listReaders() const {
	Reader::printTable();
    Reader* current = readerHead;
    while (current != nullptr) {
        current->printInfo();
        current = current->getNext();
    }
}

Book* Library::findBookbyID(const string& bookID) {
    Book* current = bookHead;
    while (current != nullptr) {
        if (current->getId() == bookID) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

Reader* Library::findReaderbyID(const string& readerID) {
    Reader* current = readerHead;
    while (current != nullptr) {
        if (current->getId() == readerID) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

void Library::borrowBook(const string& readerID, const string& bookID) {
    Reader* reader = findReaderbyID(readerID);
    Book* book = findBookbyID(bookID);

    if (reader != nullptr && book != nullptr) {
        if (book->getAvailableCopies() > 0 && reader->getBorrowedBooksCount() < MAX_BORROWED_BOOKS) {
            book->borrowBook();
            reader->borrowBook(bookID);
            time_t now = time(0);
            Transaction* newTransaction = new Transaction(readerID, bookID, now);
            newTransaction->setNext(transactionHead);
            transactionHead = newTransaction;
            cout << "Muon sach thanh cong!" << endl;
        } else {
            cout << "Muon sach that bai. Kiem tra so luong sach hoac so sach doc gia da muon." << endl;
        }
    } else {
        cout << "Doc gia hoac sach khong ton tai." << endl;
    }
}

void Library::returnBook(const string& readerID, const string& bookID) {
    Reader* reader = findReaderbyID(readerID);
    Book* book = findBookbyID(bookID);

    if (reader != nullptr && book != nullptr) {
        book->returnBook();
        reader->returnBook(bookID);
		bool found = 0;
        Transaction* current = transactionHead;
        while (current != nullptr) {
            if (current->getReaderID() == readerID && current->getBookID() == bookID && current->getStatus() == "Unreturned") {
                current->setReturnDate(time(0));
                current->setStatus("Returned");
                cout << "Tra sach thanh cong!" << endl;
                found = 1;
                break;
            }
            current = current->getNext();
        }
		if (!found) cout << "Khong tim thay giao dich" << endl;
    } else {
        cout << "Doc gia hoac sach khong ton tai." << endl;
    }
}
char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 32;
    }
    return ch;
}
bool isSubstring(const string& str, const string& sub) {
    if (sub.length() > str.length()) return false;

    for (size_t i = 0; i <= str.length() - sub.length(); ++i) {
        bool match = true;
        for (size_t j = 0; j < sub.length(); ++j) {
            if (toLower(str[i + j]) != toLower(sub[j])) {
                match = false;
                break; 
            }
        }
        if (match) return true;
    }
    return false;
}

void Library::searchBookByTitle(const string& title) const {
    Book* current = bookHead;
    bool found = false;
    while (current != nullptr) {
        if (isSubstring(current->getName(), title)) {
        	if (!found) Book::printTable();
            current->printInfo();
            found = true;
        }
        current = current->getNext();
    }
    if (!found) {
        cout << "Khong tim thay sach co tieu de: " << title << endl;
    }
}

void Library::searchReaderByName(const string& name) const {
    Reader* current = readerHead;
    bool found = false;
    while (current != nullptr) {
        if (isSubstring(current->getName(), name)) {
        	if (!found) Reader::printTable();
            current->printInfo();
            found = true;
        }
        current = current->getNext();
    }
    if (!found) {
        cout << "Khong tim thay doc gia ten: " << name << endl;
    }
}

void Library::infoBookbyID(const string& bookID) {
    Book* book = findBookbyID(bookID);
    if (book != nullptr) {
    	Book::printTable();
        book->printInfo();
    } else {
        cout << "Khong tim thay sach co ID: " << bookID << endl;
    }
}

void Library::infoReaderbyID(const string& readerID) {
    Reader* reader = findReaderbyID(readerID);
    if (reader != nullptr) {
    	Book::printTable();
        reader->listBorrowedBooks(bookHead);
    } else {
        cout << "Khong tim thay doc gia co ID: " << readerID << endl;
    }
}

void Library::overdueBooks() const {
    Transaction* current = transactionHead;
    bool found = false;
    while (current != nullptr) {
        if (current->isOverdue()) {
            current->printTransaction();
            found = true;
        }
        current = current->getNext();
    }
    if (!found) {
        cout << "Khong co giao dich qua han." << endl;
    }
}

void Library::listTransactions() const {
    Transaction* current = transactionHead;
    while (current != nullptr) {
        current->printTransaction();
        current = current->getNext();
    }
}

#endif

