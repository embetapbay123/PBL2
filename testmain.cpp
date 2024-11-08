#include <iostream>
#include "Element.h"
#include "Book.h"
#include "Reader.h"
#include "Transaction.h"
#include "limits"
#include "LM.h"
using namespace std;

void printNoti() {
    cout << "Press Enter to continue... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bỏ bộ đệm cũ
    cin.get();
}

// Hiển thị menu chính
void displayMainMenu() {
    cout << "\n=========================================\n";
    cout << "=== QUAN LY THU VIEN ===\n";
    cout << "1. Quan ly Sach\n";
    cout << "2. Quan ly Doc gia\n";
    cout << "3. Quan ly Giao dich\n";
    cout << "4. Quan ly Tac gia\n";
    cout << "5. Quan ly The loai\n";
    cout << "6. Thong ke, sap  xep\n";
    cout << "0. Thoat\n";
    cout << "=========================================\n";
}
// Hiển thị menu quản lý thể loại
void displayCategoryMenu() {
    cout << "\n=== QUAN LY THE LOAI ===\n";
    cout << "1. Danh sach the loai\n";
    cout << "2. Tim kiem the loai theo ten\n";
    cout << "3. Tra cuu thong tin the loai theo ID\n";
    cout << "4. Them moi the loai\n";
    cout << "5. Xoa the loai\n";
    cout << "6. Quay lai menu chinh\n";
}
// Hiển thị menu quản lý tác giả
void displayAuthorMenu() {
    cout << "\n=== QUAN LY TAC GIA ===\n";
    cout << "1. Danh sach tac gia\n";
    cout << "2. Tim kiem tac gia theo ten\n";
    cout << "3. Tra cuu thong tin tac gia theo ID\n";
    cout << "4. Them moi tac gia\n";
    cout << "5. Xoa tac gia\n";
    cout << "6. Quay lai menu chinh\n";
}
// Hiển thị menu quản lý sách
void displayBookMenu() {
    cout << "\n=== QUAN LY SACH ===\n";
    cout << "1. Danh sach sach\n";
    cout << "2. Tim kiem sach theo ten\n";
    cout << "3. Tra cuu thong tin sach theo ID\n";
    cout << "4. Them moi sach\n";
    cout << "5. Xoa sach\n";
    cout << "6. Quay lai menu chinh\n";
}
// Hiển thị menu quản lý độc giả
void displayReaderMenu() {
    cout << "\n=== QUAN LY DOC GIA ===\n";
    cout << "1. Danh sach doc gia\n";
    cout << "2. Tim kiem doc gia theo ten\n";
    cout << "3. Tra cuu thong tin doc gia theo ID\n";
    cout << "4. Them moi doc gia\n";
    cout << "5. Xoa doc gia\n";
    cout << "6. Quay lai menu chinh\n";
}
// Hiển thị menu quản lý giao dịch
void displayTransactionMenu() {
    cout << "\n=== QUAN LY GIAO DICH ===\n";
    cout << "1. Muon sach\n";
    cout << "2. Tra sach\n";
    cout << "3. Danh sach giao dich\n";
    cout << "4. Giao dich qua han\n";
    cout << "5. Quay lai menu chinh\n";
}
// Chức năng quản lý thể loại
void addNewCategory(Library& library) {
    string name;
    cout << "Nhap ten the loai: ";
    cin.ignore();
    getline(cin, name);
    Category* newCategory = new Category(name);
    int addChoice;
    cout << "1. Them vao dau danh sach\n";
    cout << "2. Them vao cuoi danh sach\n";
    cout << "3. Them theo chi so\n";
    cout << "Nhap lua chon cua ban: ";
    cin >> addChoice;
    switch (addChoice) {
        case 1:
            library.addCategoryAtHead(newCategory);
            break;
        case 2:
            library.addCategoryAtEnd(newCategory);
            break;
        case 3: {
            int index;
            cout << "Nhap chi so de them the loai: ";
            cin >> index;
            library.addCategoryAtIndex(index, newCategory);
            break;
        }
        default:
            cout << "Lua chon khong hop le." << endl;
    }
}
void manageCategorys(Library& library) {
    int categoryChoice;
    do {
        displayCategoryMenu();
        cout << "Nhap lua chon cua ban: ";
        cin >> categoryChoice;

        switch (categoryChoice) {
            case 1:
                library.listCategorys();
                break;
            case 2: {
                string name;
                cout << "Nhap ten the loai: ";
                cin.ignore();
                getline(cin, name);
                library.searchCategoryByName(name);
                break;
            }
            case 3: {
                string CategoryID;
                cout << "Nhap ID the loai: ";
                cin >> CategoryID;
                library.infoCategorybyID(CategoryID);
                break;
            }
            case 4: {
                addNewCategory(library);
                break;
            }
            case 5: {
                string CategoryID;
                cout << "Nhap ID the loai: ";
                cin >> CategoryID;
                library.deleteCategory(CategoryID);
                break;
            }
            case 6:
                cout << "Tro lai menu chinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
        }
        printNoti();
    } while (categoryChoice != 6);
}
// Chức năng quản lý tác giả
void addNewAuthor(Library& library) {
    string name;
    bool gender;
    int bornYear;
    cout << "Nhap ten tac gia: ";
    cin.ignore();
    getline(cin, name);
    cout << "Nhap gioi tinh (0: Nu, 1: Nam): ";
    cin >> gender;
    cout << "Nhap nam sinh: ";
    cin.ignore();
    cin >> bornYear;
    Author* newAuthor = new Author(name, gender, bornYear);
    int addChoice;
    cout << "1. Them vao dau danh sach\n";
    cout << "2. Them vao cuoi danh sach\n";
    cout << "3. Them theo chi so\n";
    cout << "Nhap lua chon cua ban: ";
    cin >> addChoice;
    switch (addChoice) {
        case 1:
            library.addAuthorAtHead(newAuthor);
            break;
        case 2:
            library.addAuthorAtEnd(newAuthor);
            break;
        case 3: {
            int index;
            cout << "Nhap chi so de them tac gia: ";
            cin >> index;
            library.addAuthorAtIndex(index, newAuthor);
            break;
        }
        default:
            cout << "Lua chon khong hop le." << endl;
    }
}
void manageAuthors(Library& library) {
    int authorChoice;
    do {
        displayAuthorMenu();
        cout << "Nhap lua chon cua ban: ";
        cin >> authorChoice;

        switch (authorChoice) {
            case 1:
                library.listAuthors();
                break;
            case 2: {
                string name;
                cout << "Nhap ten tac gia: ";
                cin.ignore();
                getline(cin, name);
                library.searchAuthorByName(name);
                break;
            }
            case 3: {
                string AuthorID;
                cout << "Nhap ID tac gia: ";
                cin >> AuthorID;
                library.infoAuthorbyID(AuthorID);
                break;
            }
            case 4: {
                addNewAuthor(library);
                break;
            }
            case 5: {
                string AuthorID;
                cout << "Nhap ID tac gia: ";
                cin >> AuthorID;
                library.deleteAuthor(AuthorID);
                break;
            }
            case 6:
                cout << "Tro lai menu chinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
        }
        printNoti();
    } while (authorChoice != 6);
}
// Chức năng quản lý sách
void addNewBook(Library& library) {
    string title, authorID, categoryID;
    int year, pages, totalCopies;
    cout << "Nhap tieu de sach: ";
    cin.ignore();
    getline(cin, title);
    cout << "Nhap ID tac gia: ";
    getline(cin, authorID);
    cout << "Nhap ID the loai: ";
    getline(cin, categoryID);
    cout << "Nhap nam xuat ban: ";
    cin >> year;
    cout << "Nhap so trang: ";
    cin >> pages;
    cout << "Nhap tong so ban sao: ";
    cin >> totalCopies;
    Book* newBook = library.createNewBook(title, authorID, categoryID, year, pages, totalCopies);
    if (newBook == nullptr) {
        cout << "Khong the tao boi vi tac gia hoac the loai khong ton tai!" << endl;
        return;
    }
    int addChoice;
    cout << "1. Them vao dau danh sach\n";
    cout << "2. Them vao cuoi danh sach\n";
    cout << "3. Them theo chi so\n";
    cout << "Nhap lua chon cua ban: ";
    cin >> addChoice;
    switch (addChoice) {
        case 1:
            library.addBookAtHead(newBook);
            break;
        case 2:
            library.addBookAtEnd(newBook);
            break;
        case 3: {
            int index;
            cout << "Nhap chi so de them sach: ";
            cin >> index;
            library.addBookAtIndex(index, newBook);
            break;
        }
        default:
            cout << "Lua chon khong hop le." << endl;
    }
}
void manageBooks(Library& library) {
    int bookChoice;
    do {
        displayBookMenu();
        cout << "Nhap lua chon cua ban: ";
        cin >> bookChoice;

        switch (bookChoice) {
            case 1:
                library.listBooks();
                break;
            case 2: {
                string title;
                cout << "Nhap ten sach: ";
                cin.ignore();
                getline(cin, title);
                library.searchBookByTitle(title);
                break;
            }
            case 3: {
                string bookID;
                cout << "Nhap ID sach: ";
                cin >> bookID;
                library.infoBookbyID(bookID);
                break;
            }
            case 4: {
                addNewBook(library);
                break;
            }
            case 5: {
                string bookID;
                cout << "Nhap ID sach: ";
                cin >> bookID;
                library.deleteBook(bookID);
                break;
            }
            case 6:
                cout << "Tro lai menu chinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
        }
        printNoti();
    } while (bookChoice != 6);
}
// Chức năng quản lý độc giả
void addNewReader(Library& library) {
    string name, className, address, phone;
    bool gender;
    cout << "Nhap ten doc gia: ";
    cin.ignore();
    getline(cin, name);
    cout << "Nhap gioi tinh (0: Nu, 1: Nam): ";
    cin >> gender;
    cout << "Nhap lop: ";
    cin.ignore();
    getline(cin, className);
    cout << "Nhap dia chi: ";
    getline(cin, address);
    cout << "Nhap so dien thoai: ";
    getline(cin, phone);
    Reader* newReader = new Reader(name, gender, className, address, phone);

    int addChoice;
    cout << "1. Them vao dau danh sach\n";
    cout << "2. Them vao cuoi danh sach\n";
    cout << "3. Them theo chi so\n";
    cout << "Nhap lua chon cua ban: ";
    cin >> addChoice;

    switch (addChoice) {
        case 1:
            library.addReaderAtHead(newReader);
            break;
        case 2:
            library.addReaderAtEnd(newReader);
            break;
        case 3: {
            int index;
            cout << "Nhap chi so de them doc gia: ";
            cin >> index;
            library.addReaderAtIndex(index, newReader);
            break;
        }
        default:
            cout << "Lua chon khong hop le." << endl;
    }
}
void manageReaders(Library& library) {
    int readerChoice;
    do {
        displayReaderMenu();
        cout << "Nhap lua chon cua ban: ";
        cin >> readerChoice;

        switch (readerChoice) {
            case 1:
                library.listReaders();
                break;
            case 2: {
                string name;
                cout << "Nhap ten doc gia: ";
                cin.ignore();
                getline(cin, name);
                library.searchReaderByName(name);
                break;
            }
            case 3: {
                string readerID;
                cout << "Nhap ID doc gia: ";
                cin >> readerID;
                library.infoReaderbyID(readerID);
                break;
            }
            case 4: {
                addNewReader(library);
                break;
            }
            case 5: {
                string readerID;
                cout << "Nhap ID doc gia: ";
                cin >> readerID;
                library.deleteReader(readerID);
                break;
            }
            case 6:
                cout << "Tro lai menu chinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
        }
        printNoti();
    } while (readerChoice != 6);
}
// Chức năng quản lý giao dịch
void manageTransactions(Library& library) {
    int transactionChoice;
    do {
        displayTransactionMenu();
        cout << "Nhap lua chon cua ban: ";
        cin >> transactionChoice;

        switch (transactionChoice) {
            case 1: {
                string readerID, bookID;
                cout << "Nhap ID doc gia: ";
                cin >> readerID;
                cout << "Nhap ID sach: ";
                cin >> bookID;
                library.borrowBook(readerID, bookID);
                break;
            }
            case 2: {
                string readerID, bookID;
                cout << "Nhap ID doc gia: ";
                cin >> readerID;
                cout << "Nhap ID sach: ";
                cin >> bookID;
                library.returnBook(readerID, bookID);
                break;
            }
            case 3:
                library.listTransactions();
                break;
            case 4:
                library.overdueBooks();
                break;
            case 5:
                cout << "Tro lai menu chinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
        }
        printNoti();
    } while (transactionChoice != 5);
}

// Hàm chính
int main() {
    Library library;
    library.loadCategorys();
    library.loadAuthors();
    library.loadBooks();
    library.loadReaders();
    library.loadTransaction();
    int choice;

    do {
        displayMainMenu();
        cout << "Nhap lua chon cua ban (1-6): ";
        cin >> choice;

        while (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Vui long nhap mot so nguyen: ";
            cin >> choice;
        }
        switch (choice) {
            case 1:
                manageBooks(library);
                break;
            case 2:
                manageReaders(library);
                break;
            case 3:
                manageTransactions(library);
                break;
            case 4:
                manageAuthors(library);
                break;
            case 5:
                manageCategorys(library);
                break;
            case 6:
                cout << "Chuc nang thong ke dang duoc phat trien...\n";
                break;
            case 0:
                cout << "Thoat chuong trinh...\n";
                break;
            default: {
                cout << "Lua chon khong hop le." << endl;
                printNoti();
            }
        }
    } while (choice != 6);

    return 0;
}
