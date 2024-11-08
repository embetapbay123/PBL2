#ifndef LM_H
#define LM_H

#include "Element.h"
#include "Book.h"
#include "Reader.h"
#include "Transaction.h"
#include "LinkList.h"
#include <fstream>
using namespace std;
class Library;

class Library {
private:
    LinkedList authorList; // HeadNode cua Author
    LinkedList bookList; // HeadNode cua book
    LinkedList readerList; // HeadNode cua reader
    LinkedList transactionList; // HeadNode cua transaction
public:
    Library(); 
    ~Library(); 
    void loadAuthors(); // Doc du lieu tu file authors.txt va them vao linklink cua author
    void loadBooks(); // Doc du lieu tu file books.txt va them vao linklist cua book
    void loadReaders(); // Doc du lieu tu file readers.txt va them vao linklist cua reader
    void loadTransaction(); // Doc du lieu tu file transactions.txt va them vao linklist cua transaction
    Book* createNewBook(string title, string authorID, string category, int year, int pages, int totalCopies) {
        Author* authorPtr = findAuthorbyID(authorID);
        if (authorPtr == nullptr) return nullptr;
	    Book* newBook = new Book(title, authorPtr, category, year, pages, totalCopies);
	    return newBook;
	}
    void addAuthorAtHead(Author* newAuthor);
    void addAuthorAtEnd(Author* newAuthor); 
	void addAuthorAtIndex(int index, Author* newAuthor); 

    void addBookAtHead(Book* newBook);
    void addBookAtEnd(Book* newBook); 
	void addBookAtIndex(int index, Book* newBook); 

    void addReaderAtHead(Reader* newReader);
    void addReaderAtEnd(Reader* newReader); 
	void addReaderAtIndex(int index, Reader* newReader); 

    void addTransactionAtHead(Transaction* newTransaction);
    void addTransactionAtEnd(Transaction* newTransaction); 
	void addTransactionAtIndex(int index, Transaction* newReader); 

	void deleteBook(const string& bookID); 
    void deleteReader(const string& readerID); 
    void deleteAuthor(const string& authorID);

    void listAuthors() const;
    void listBooks() const; 
    void listReaders() const;
    void listTransactions() const; 
    Book* findBookbyID(const string& bookID); 
    Reader* findReaderbyID(const string& readerID); 
    Author* findAuthorbyID(const string& authorID);
    Transaction* findTransactionbyBookReader(const string& readerID, const string& bookID, const bool& status = 0);
    void borrowBook(const string& readerID, const string& bookID); 
    void returnBook(const string& readerID, const string& bookID); 

    void searchBookByTitle(const string& title) const; 
    void searchReaderByName(const string& name) const; 
    void searchAuthorByName(const string& name) const;
    bool searchByName(const string &name, Element* Head) const;

    void infoBookbyID(const string& bookID);
    void infoReaderbyID(const string& readerID); 
    void infoAuthorbyID(const string& authorID);

    void overdueBooks() const; 
};

// Implementation of Library class
Library::Library() : authorList(), readerList(), bookList(), transactionList() {}

Library::~Library() {}
void Library::loadTransaction() {
    ifstream file("transactions.txt");
    if (!file.is_open()) {
        cout << "Khong the mo file transactions.txt" << endl;
        return;
    }

    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;
        
        string transactionID = extractField(line);
        string readerID = extractField(line);
        string bookID = extractField(line);
        string borrowDatestr = extractField(line);
        string returnDatestr = extractField(line);
        string statusstr = extractField(line);
        // Tao doi tuong Reader moi
        Transaction* newTransaction = new Transaction(transactionID, readerID, bookID, borrowDatestr);
        if (statusstr == "1") {
            newTransaction->setStatus(1);
            newTransaction->setReturnDate(returnDatestr);
        }
        else {
            findReaderbyID(readerID)->borrowBook();
            findBookbyID(bookID)->borrowBook();
        }
        // Them vao danh sach lien ket
        addTransactionAtEnd(newTransaction);
    }

    file.close();
}
void Library::loadAuthors() {
    ifstream file("authors.txt");
    if (!file.is_open()) {
        cout << "Khong the mo file authors.txt" << endl;
        return;
    }

    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;

        string AuthorID = extractField(line);
        string name = extractField(line);
        string genderString = extractField(line);
        string bornYearStr = extractField(line);
        // Tao doi tuong Author moi
        Author* newAuthor = new Author(AuthorID, name, toInt(genderString), toInt(bornYearStr));
        // Them vao danh sach lien ket
        addAuthorAtEnd(newAuthor);
    }

    file.close();
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
        string bookID = extractField(line);
        string title = extractField(line);
        string authorID = extractField(line);
        string category = extractField(line);
        string yearStr = extractField(line);
        string pagesStr = extractField(line);
        string totalCopiesStr = extractField(line);
        Author* author = findAuthorbyID(authorID);
        author->incresingBookCount();
        Book* newBook = new Book(bookID, title, author, category, toInt(yearStr, 0), toInt(pagesStr, 0), toInt(totalCopiesStr));
        // Them vao danh sach lien ket
        addBookAtEnd(newBook);
    }

    file.close();
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

        string readerID = extractField(line);
        string name = extractField(line);
        string genderString = extractField(line);
        string className = extractField(line);
        string address = extractField(line);
        string phoneNumber = extractField(line);

        // Tao doi tuong Reader moi
        Reader* newReader = new Reader(readerID, name, toInt(genderString, 0), className, address, phoneNumber);

        // Them vao danh sach lien ket
        addReaderAtEnd(newReader);
    }

    file.close();
}

void Library::addAuthorAtHead(Author* newAuthor) {
    authorList.addAtFirst(newAuthor);
}

void Library::addAuthorAtEnd(Author* newAuthor) {
   authorList.addAtEnd(newAuthor);
}

void Library::addAuthorAtIndex(int index, Author* newAuthor) {
    authorList.addAtIndex(index, newAuthor);
}

void Library::addBookAtHead(Book* newBook) {
    bookList.addAtFirst(newBook);
}

void Library::addBookAtEnd(Book* newBook) {
    bookList.addAtEnd(newBook);
}

void Library::addBookAtIndex(int index, Book* newBook) {
    bookList.addAtIndex(index, newBook);
}

void Library::addReaderAtHead(Reader* newReader) {
    readerList.addAtFirst(newReader);
}

void Library::addReaderAtEnd(Reader* newReader) {
    readerList.addAtEnd(newReader);
}

void Library::addReaderAtIndex(int index, Reader* newReader) {
    readerList.addAtIndex(index, newReader);
}

void Library::addTransactionAtHead(Transaction* newTransaction) {
   transactionList.addAtFirst(newTransaction);
}

void Library::addTransactionAtEnd(Transaction* newTransaction) {
    transactionList.addAtEnd(newTransaction);
}

void Library::addTransactionAtIndex(int index, Transaction* newTransaction) {
    transactionList.addAtIndex(index, newTransaction);
}

void Library::deleteAuthor(const string& authorID) {
    try {
        authorList.deleteNodebyID(authorID);
    }
    catch (int& bug){
        if (bug == 0) cout << "Khong the xoa tac gia, tac gia van con sach!" << endl;
        else if (bug == 1) cout << "Khong ton tai tac gia co ID da nhap!" << endl;
        else cout << "UNKNOW BUG AT DELETE AUTHOR" << endl;
        return;
    }
}

void Library::deleteBook(const string& bookID) {
    try {
        bookList.deleteNodebyID(bookID);
    }
    catch (int& bug){
        if (bug == 0) cout << "Khong the xoa sach, sach chua duoc tra het!" << endl;
        else if (bug == 1) cout << "Khong ton tai sach co ID da nhap!" << endl;
        else cout << "UNKNOW BUG AT DELETE BOOk" << endl;
        return;
    }
}

void Library::deleteReader(const string& readerID) {
    try {
        readerList.deleteNodebyID(readerID);
    }
    catch (int& bug){
        if (bug == 0) cout << "Khong the xoa doc gia, chua tra het sach!" << endl;
        else if (bug == 1) cout << "Khong ton tai doc gia co ID da nhap!" << endl;
        else cout << "UNKNOW BUG AT DELETE READER" << endl;
        return;
    }
}
  
void Library::listAuthors() const {
    try {
        authorList.print();
    }
    catch (int& bug) {
        if (bug == 0) cout << "Khong ton tai du lieu!" << endl;
        else cout << "UNKNOW BUG AT LIST AUTHOR!" << endl;
    }
}

void Library::listBooks() const {
    try {
        bookList.print();
    }
    catch (int& bug) {
        if (bug == 0) cout << "Khong ton tai du lieu!" << endl;
        else cout << "UNKNOW BUG AT LIST BOOK!" << endl;
    }
}

void Library::listReaders() const {
	try {
        readerList.print();
    }
    catch (int& bug) {
        if (bug == 0) cout << "Khong ton tai du lieu!" << endl;
        else cout << "UNKNOW BUG AT LIST READER!" << endl;
    }
}

void Library::listTransactions() const {
    try {
        transactionList.print();
    }
    catch (int& bug) {
        if (bug == 0) cout << "Khong ton tai du lieu!" << endl;
        else cout << "UNKNOW BUG AT LIST TRANSACTION!" << endl;
    }
}

Book* Library::findBookbyID(const string& bookID) {
    return static_cast<Book*>(bookList.findbyID(bookID));
}

Reader* Library::findReaderbyID(const string& readerID) {
    return static_cast<Reader*>(readerList.findbyID(readerID));
}

Author* Library::findAuthorbyID(const string& authorID) {
    return static_cast<Author*>(authorList.findbyID(authorID));
}

Transaction* Library::findTransactionbyBookReader(const string& readerID, const string& bookID, const bool& status) {
    Node* current = transactionList.getHead();
    while (current != nullptr) {
        Transaction* transactionPtr = dynamic_cast<Transaction*> (current->data);
        if (transactionPtr->getReaderID() == readerID && transactionPtr->getBookID() == bookID) {
            return transactionPtr;
        }
        current = current->next;
    }
    return nullptr;
}

void Library::borrowBook(const string& readerID, const string& bookID) {
    Reader* reader = findReaderbyID(readerID);
    Book* book = findBookbyID(bookID);
    if (reader == nullptr) {
        cout << "Doc gia khong ton tai!" << endl;
        return;
    }
    if (book == nullptr) {
        cout << "Sach khong ton tai!" << endl;
        return;
    }
    if (book->getAvailableCopies() == 0) {
        cout << "Khong con sach co the muon." << endl;
        return;
    }
    if (reader->getbookCount() == MAX_BORROWED_BOOKS) {
        cout << "So sach muon cua doc gia dat toi da." << endl;
        return;
    }
    if (findTransactionbyBookReader(readerID, bookID) == nullptr) {
            book->borrowBook();
            reader->borrowBook();
            time_t now = time(0);
            Transaction* newTransaction = new Transaction(readerID, bookID, Date(now));
            transactionList.addAtEnd(newTransaction);
            cout << "Muon sach thanh cong!" << endl;
        } 
    else {
        cout << "Khong the muon sach da muon!" << endl;
    }   
}

void Library::returnBook(const string& readerID, const string& bookID) {
    Reader* reader = findReaderbyID(readerID);
    Book* book = findBookbyID(bookID);
    if (reader == nullptr) {
        cout << "Doc gia khong ton tai." << endl;
        return;
    }
    if (book == nullptr) {
        cout << "Sach khong ton tai." << endl;
        return;
    }
    Transaction* current = findTransactionbyBookReader(readerID, bookID);
    if (current != nullptr) {
        book->returnBook();
        reader->returnBook();
        current->setStatus(1);
        current->setReturnDate(time(0));
        cout << "Tra sach thanh cong!" << endl;
    }
    else {
        cout << "Khong ton tai giao dich muon sach!" << endl;
        return;
    }
}

void Library::searchBookByTitle(const string& title) const {
    bookList.printbyName(title);
}

void Library::searchReaderByName(const string& name) const {
    readerList.printbyName(name);
}

void Library::searchAuthorByName(const string& name) const {
    authorList.printbyName(name);
}

void Library::infoAuthorbyID(const string& authorID) {
    Author* author = findAuthorbyID(authorID);
    if (author != nullptr) {
        if (author->getbookCount() == 0) {
            cout << "Doc gia chua muon cuon nao!" << endl;
        }
        Node* current = bookList.getHead();
        current->data->printTable();
        while (current != nullptr) {
            Book* bookPtr = dynamic_cast<Book*> (current->data);
            if (bookPtr->getAuthorID() == authorID) {
                bookPtr->printInfo();
            }
            current = current->next;
        }
    }
    else {
        cout << "Khong tim thay tac gia co ID: " << authorID << endl;
    }
}

void Library::infoBookbyID(const string& bookID) {
    Book* book = findBookbyID(bookID);
    if (book != nullptr) {
        if (book->getAvailableCopies() == book->getTotalCopies()) {
            cout << "Sach chua duoc ai muon!" << endl;
        }
        Node* current = transactionList.getHead();
        readerList.getHead()->data->printTable();
        while (current != nullptr) {
            Transaction* transactionPtr = dynamic_cast<Transaction*> (current->data);
            if (transactionPtr->getBookID() == bookID && transactionPtr->getStatus() == 0) {
                findReaderbyID(transactionPtr->getReaderID())->printInfo();
            }
            current = current->next;
        }
    }
    else {
        cout << "Khong tim thay sach co ID: " << bookID << endl;
    }
}

void Library::infoReaderbyID(const string& readerID) {
    Reader* reader = findReaderbyID(readerID);
    if (reader != nullptr) {
        if (reader->getbookCount() == 0) {
            cout << "Doc gia chua muon cuon nao!" << endl;
        }
        Node* current = transactionList.getHead();
        bookList.getHead()->data->printTable();
        while (current != nullptr) {
            Transaction* transactionPtr = dynamic_cast<Transaction*> (current->data);
            if (transactionPtr->getReaderID() == readerID && transactionPtr->getStatus() == 0) {
                findBookbyID(transactionPtr->getBookID())->printInfo();
            }
            current = current->next;
        }
    }
    else {
        cout << "Khong tim thay doc gia co ID: " << readerID << endl;
    }
}

void Library::overdueBooks() const {
    Node* current = transactionList.getHead();
    bool found = 0;
    while (current != nullptr) {
        Transaction* transactionPtr = dynamic_cast<Transaction*> (current->data);
        if (transactionPtr->getStatus() == 0 && transactionPtr->isOverdue()) {
            if (!found) transactionPtr->printTable();
            found = true;
            transactionPtr->printInfo();
        }
        current = current->next;
    }
    if (!found) {
        cout << "Khong co giao dich qua han." << endl;
    }
}

#endif