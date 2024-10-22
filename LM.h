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
    Book* bookHead; // HeadNode cua book
    Reader* readerHead; // HeadNode cua reader
    Transaction* transactionHead; // HeadNode cua transaction
public:
    Library(); // constructor mac dinh
    ~Library(); // destructor 
    void loadBooks(); // Doc du lieu tu file books.txt va them vao linklist cua book
    void loadReaders(); // Doc du lieu tu file readers.txt va them vao linklist cua reader
    void loadTransaction(); // Chua xac dinh
    // Tao moi mot doi tuong Book
    Book* createNewBook(string title, string author, string category, int year, int pages, int totalCopies) {
	    Book* newBook = new Book(title, author, category, year, pages, totalCopies);
	    return newBook;
	}
    // Tạo mới một đối tượng Reader 
	Reader* createNewReader(string name, bool gender, string className, string address, string phoneNumber) {
	    Reader* newReader = new Reader(name, gender, className, address, phoneNumber);
	    return newReader;
	}
   
    // Them newBook vao dau LinkList
    void addBookAtHead(Book* newBook);
    // Them newBook vao cuoi LinkList 
    void addBookAtEnd(Book* newBook); 
    // Them newBook vao LinkList theo index
	void addBookAtIndex(int index, Book* newBook); 

	// Them newReader vao dau LinkList
    void addReaderAtHead(Reader* newReader);
    // Thêm newReader vào cuối LinkList 
    void addReaderAtEnd(Reader* newReader); 
    // Thêm newReader vào LinkList theo index --- Nên sửa bool
	void addReaderAtIndex(int index, Reader* newReader); 

    // Xóa Book theo ID ra khỏi LinkList nếu có --- Nên sửa bool
	void deleteBook(const string& bookID); 
	// Xóa Reader theo ID ra khỏi LinkList nếu có -- nên sửa bool
    void deleteReader(const string& readerID); 

    // In ra danh sách book
    void listBooks() const; 
    // In ra danh sách reader
    void listReaders() const; 
    void list(Element* Head) const;
    // Tìm book theo ID, trả về con trỏ hoặc nullptr
    Book* findBookbyID(const string& bookID); 
    // Tìm reader theo ID, trả về con trỏ hoặc nullptr
    Reader* findReaderbyID(const string& readerID); 

    // Thao tác mượn sách cần ID reader và ID book -- nên sửa bool
    void borrowBook(const string& readerID, const string& bookID); 
    // Thao tác trả sách cần ID reader và ID book -- nên sửa bool
    void returnBook(const string& readerID, const string& bookID); 

    // Tìm sách có title 
    void searchBookByTitle(const string& title) const; 
    // Tìm reader có name
    void searchReaderByName(const string& name) const; 
    bool searchByName(const string &name, Element* Head) const;
    // In ra thông tin cuốn có ID
    void infoBookbyID(const string& bookID);
    // In ra những cuốn mà người có ID mượn
    void infoReaderbyID(const string& readerID); 
    
    // In ra những giao dịch hết hạn
    void overdueBooks() const; 
    // In ra những giao dịch
    void listTransactions() const; 
};

// Implementation of Library class
Library::Library() : bookHead(nullptr), readerHead(nullptr), transactionHead(nullptr) {}

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
        string author = extractField(line);
        string category = extractField(line);
        string yearStr = extractField(line);
        string pagesStr = extractField(line);
        string totalCopiesStr = extractField(line);

        if (bookID.empty()) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac thieu ID sach." << endl;
            continue;
        }
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

        int year = toInt(yearStr);
        if (year <= 0) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac nam khong hop le." << endl;
            continue;
        }
        int pages = toInt(pagesStr);
        if (pages <= 0) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac so trang khong hop le." << endl;
            continue;
        }
        int totalCopies = toInt(totalCopiesStr);
        if (totalCopies <= 0) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac so luong khong hop le." << endl;
            continue;
        }

        Book* newBook = new Book(bookID,title, author, category, year, pages, totalCopies);

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

        if (readerID.empty()) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac thieu ID doc gia." << endl;
            continue;
        }
        if (name.empty()) {
            cout << "Dong " << lineNumber << ": Loi dinh dang hoac thieu ten doc gia." << endl;
            continue;
        }
        if (genderString.empty()) {
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
        Reader* newReader = new Reader(readerID, name, toInt(genderString, 0), className, address, phoneNumber);

        // Them vao danh sach lien ket
        addReaderAtEnd(newReader);
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
        if (bookHead->getAvailableCopies() != bookHead->getTotalCopies()) {
            cout << "Sach hien chua duoc tra het, khong the xoa" << endl;
            return;
        }
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

    if (current->getNext()->getAvailableCopies() != current->getNext()->getTotalCopies()) {
        cout << "Sach hien chua duoc tra het, khong the xoa." << endl;
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
        if (readerHead->getBorrowedBooksCount() != 0) {
            cout << "Nguoi doc chua tra het sach, khong the xoa." << endl;
            return;
        }
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
    if (current->getNext()->getBorrowedBooksCount() != 0) {
        cout << "Nguoi doc chua tra het sach, khong the xoa." << endl;
        return;
    }
    Reader* temp = current->getNext();
    current->setNext(current->getNext()->getNext()); 
    delete temp; 
    cout << "Xoa thanh cong!" << endl;
}

void Library::listBooks() const {
    list(bookHead);
}

void Library::listReaders() const {
	list(readerHead);
}

void Library::list(Element* Head) const{
    Head->printTable();
    Element* current = Head;
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
    if (reader == nullptr) {
        cout << "Doc gia khong ton tai." << endl;
        return;
    }
    if (book == nullptr) {
        cout << "Sach khong ton tai." << endl;
        return;
    }
    if (book->getAvailableCopies() == 0) {
        cout << "Khong con sach co the muon." << endl;
        return;
    }
    if (reader->getBorrowedBooksCount() == MAX_BORROWED_BOOKS) {
        cout << "So sach muon cua doc gia dat toi da." << endl;
        return;
    }
    if (reader->findBookInListBorrowedBooks(bookID) == false) {
            book->borrowBook();
            reader->borrowBook(bookID);
            time_t now = time(0);
            Transaction* newTransaction = new Transaction(readerID, bookID, Date(now));
            newTransaction->setNext(transactionHead);
            transactionHead = newTransaction;
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
    if (reader->findBookInListBorrowedBooks(bookID) == true) {
        book->returnBook();
        reader->returnBook(bookID);
        bool found = 0;
        Transaction* current = transactionHead;
        while (current != nullptr) {
            if (current->getReaderID() == readerID && current->getBookID() == bookID && current->getStatus() == 0) {
                current->setReturnDate(time(0));
                current->setStatus("Returned");
                cout << "Tra sach thanh cong!" << endl;
                found = 1;
                break;
            }
            current = current->getNext();
        }
    }
    else {
        cout << "Khong ton tai giao dich muon sach!" << endl;
        return;
    }
}

void Library::searchBookByTitle(const string& title) const {
    // Book* current = bookHead;
    bool found = searchByName(title, bookHead);
    // while (current != nullptr) {
    //     if (isSubstring(current->getName(), title)) {
    //     	if (!found) printTable();
    //         current->printInfo();
    //         found = true;
    //     }
    //     current = current->getNext();
    // }
    if (!found) {
        cout << "Khong tim thay sach co tieu de: " << title << endl;
    }
}

void Library::searchReaderByName(const string& name) const {
    // Reader* current = readerHead;
    bool found = searchByName(name, readerHead);
    // while (current != nullptr) {
    //     if (isSubstring(current->getName(), name)) {
    //     	// if (!found) Reader::printTable();
    //         current->printInfo();
    //         found = true;
    //     }
    //     current = current->getNext();
    // }
    if (!found) {
        cout << "Khong tim thay doc gia ten: " << name << endl;
    }
}

bool Library::searchByName(const string &name, Element* Head) const {
    Element* current = Head;
    bool found = false;
    while (current != nullptr) {
        if (isSubstring(current->getName(), name)) {
        	if (!found) current->printTable();
            current->printInfo();
            found = true;
        }
        current = current->getNext();
    }
    return found;
}

void Library::infoBookbyID(const string& bookID) {
    Book* book = findBookbyID(bookID);
    if (book != nullptr) {
    	// Book::printTable();
        book->printInfo();
    } else {
        cout << "Khong tim thay sach co ID: " << bookID << endl;
    }
}

void Library::infoReaderbyID(const string& readerID) {
    Reader* reader = findReaderbyID(readerID);
    if (reader != nullptr) {
    	// Book::printTable();
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
            if (!found) Transaction::printTable();
            current->printInfo();
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
    bool found = false;
    while (current != nullptr) {
        if (!found) Transaction::printTable();
        current->printInfo();
        found = true;
        current = current->getNext();
    }
    if (!found) {
        cout << "Khong co giao dich." << endl;
    }
}

#endif

