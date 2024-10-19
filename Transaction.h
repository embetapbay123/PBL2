#ifndef Transaction_H
#define Transaction_H

#include "Reader.h"

using namespace std;

class Transaction;

class Transaction {
private:
    string readerID;
    string bookID;
    time_t borrowDate;
    time_t returnDate;
    string status;
    Transaction* next;

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
    Transaction* getNext() const;
    void setNext(Transaction* nextTransaction);
};

// Implementation of Transaction class
Transaction::Transaction() : borrowDate(0), returnDate(0), status("Unreturned"), next(nullptr) {}

Transaction::Transaction(string ReaderID, string BookID, time_t BorrowDate)
    : readerID(ReaderID), bookID(BookID), borrowDate(BorrowDate), returnDate(0), status("Unreturned"), next(nullptr) {}

string Transaction::getReaderID() const { return readerID; }

string Transaction::getBookID() const { return bookID; }

string Transaction::getStatus() const { return status; }

void Transaction::setReturnDate(time_t ReturnDate) { this->returnDate = ReturnDate; }

void Transaction::setStatus(const string& Status) { this->status = Status; }

void Transaction::printTransaction() const {
    cout << "Reader ID: " << readerID << ", Book ID: " << bookID
         << ", Borrow Date: " << ctime(&borrowDate)
         << ", Status: " << status << endl;
}

bool Transaction::isOverdue() const {
    time_t now = time(0);
    double secondsDiff = difftime(now, borrowDate);
    int daysDiff = (int)secondsDiff / (60 * 60 * 24);
    return (daysDiff > 30 && status == "Unreturned");
}

Transaction* Transaction::getNext() const {
    return next;
}

void Transaction::setNext(Transaction* nextTransaction) {
    next = nextTransaction;
}
#endif

