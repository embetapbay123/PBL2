#ifndef Transaction_H
#define Transaction_H

#include "Reader.h"
#include "Date.h"

using namespace std;

class Transaction;

class Transaction : public Element {
private:
    static int countTransaction;
    string id;
    string readerID;
    string bookID;
    Date borrowDate;
    Date returnDate;
    bool status; 
    /*0 is Unreturned
      1 is Returned
    */
    Transaction* next;

public:
    static string generateID() {
        return "T" + toString(countTransaction++); 
    }
    Transaction() : next(nullptr) {}
    Transaction(string ReaderID, string BookID, Date BorrowDate): 
        id(generateID()),readerID(ReaderID), bookID(BookID), borrowDate(BorrowDate), status(0), next(nullptr) {}
    Transaction(string TransactionID, string ReaderID, string BookID, Date BorrowDate): 
        id(TransactionID),readerID(ReaderID), bookID(BookID), borrowDate(BorrowDate), status(0), next(nullptr) {
            if (countTransaction <= toInt(TransactionID, 1)) countTransaction = toInt(TransactionID, 1) + 1;
        }
    string getId() const {return id;}
    string getReaderID() const {return readerID;}
    string getBookID() const {return bookID;}
    Date getBorrowDate() const {return borrowDate;}
    Date getReturnDate() const {return returnDate;}
    bool getStatus() const {return status;}
    Transaction* getNext() const {return next;}

    void setReturnDate(const Date& newReturnDate) {returnDate = newReturnDate;}
    void setStatus(const bool& newStatus) {status = newStatus;}
    void setNext(Element* newNext) {next = static_cast<Transaction*> (newNext);}

    void printTable() {
		 cout << left << setw(5) << "ID"
         << setw(15) << "Reader ID"
         << setw(15) << "Book ID"
         << setw(15) << "Ngay muon"
         << setw(30) << "Ngay tra"
         << setw(15) << "Trang thai" << endl;
    	 cout << "------------------------------------------------------------------------------------------" << endl;
	}
    void printInfo() const {
        cout << left << setw(5) << id
         << setw(15) << readerID
         << setw(15) << bookID
         << setw(15) << borrowDate.info()
         << setw(30) << (status ? returnDate.info() : "NULL")
         << setw(15) << (status ? "Da tra" : "Chua tra") << endl;
    }
    bool isOverdue() const;
};

// Implementation of Transaction class
bool Transaction::isOverdue() const {
    time_t now = time(0);
    int daysDiff = borrowDate.diff(Date(now));
    return daysDiff >= 30;
}

int Transaction::countTransaction = 1;

#endif

