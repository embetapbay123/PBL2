#include <iostream>
#include "Element.h"
#include "Book.h"
#include "Reader.h"
#include "Transaction.h"
#include "LM.h"
#include "dohoa.h"
using namespace std;

int displayAddMenu() {
    string menu[] = {
        "1. Them vao dau",
        "2. Them vao cuoi",
        "3. Them theo chi so"
    };
    return printMenu(menu, 3, "ADD MENU");
}
// Hiển thị menu chính
int displayMainMenu() {
    string menuu[] = {
        "1. Quan ly Sach", 
        "2. Quan ly Doc gia", 
        "3. Quan ly Giao dich", 
        "4. Quan ly Tac gia", 
        "5. Quan ly The loai", 
        "6. Thong ke",
        "7. Thoat"
    };
    return printMenu(menuu, 7, "QUAN LY THU VIEN");
    return 0;
}
int displayCategoryMenu() {
    string menu[] = {
        "1. Danh sach the loai", 
        "2. Tim kiem the loai", 
        "3. Tra cuu the loai", 
        "4. Them moi the loai", 
        "5. Xoa the loai", 
        "6. Quay lai menu chinh"
    };
    return printMenu(menu, 6, "QUAN LY THE LOAI");
}

int displayAuthorMenu() {
    string menu[] = {
        "1. Danh sach tac gia", 
        "2. Tim kiem tac gia", 
        "3. Tra cuu tac gia", 
        "4. Them moi tac gia", 
        "5. Xoa tac gia", 
        "6. Quay lai menu chinh"
    };
    return printMenu(menu, 6, "QUAN LY TAC GIA");
}

int displayBookMenu() {
    string menu[] = {
        "1. Danh sach sach", 
        "2. Tim kiem sach", 
        "3. Tra cuu sach", 
        "4. Them moi sach", 
        "5. Xoa sach", 
        "6. Quay lai menu chinh"
    };
    return printMenu(menu, 6, "QUAN LY SACH");
}

int displayReaderMenu() {
    string menu[] = {
        "1. Danh sach doc gia", 
        "2. Tim kiem doc gia", 
        "3. Tra cuu doc gia", 
        "4. Them moi doc gia", 
        "5. Xoa doc gia", 
        "6. Quay lai menu chinh"
    };
    return printMenu(menu, 6, "QUAN LY DOC GIA");
}

int displayTransactionMenu() {
    string menu[] = {
        "1. Muon sach", 
        "2. Tra sach", 
        "3. Danh sach giao dich", 
        "4. Giao dich qua han",
        "5. Giao dich trong thang", 
        "6. Quay lai menu chinh"
    };
    return printMenu(menu, 6, "QUAN LY GIAO DICH");
}
void addNewCategory(Library& library) {
    string name;
    cout << "Nhap ten the loai: ";
    getline(cin, name);
    Category* newCategory = new Category(name);
    int addChoice = displayAddMenu() + 1;
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
        categoryChoice = displayCategoryMenu() + 1;
        system("cls");
        switch (categoryChoice) {
            case 1:
                library.listCategorys();
                break;
            case 2: {
                string name;
                cout << "Nhap ten the loai: ";
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
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
        }
        printNoti();
        system("cls");
    } while (categoryChoice != 6);
}
void addNewAuthor(Library& library) {
    string name;
    bool gender;
    int bornYear;
    cout << "Nhap ten tac gia: ";
    getline(cin, name);
    cout << "Nhap gioi tinh (0: Nu, 1: Nam): ";
    cin >> gender;
    cout << "Nhap nam sinh: ";
    cin >> bornYear;
    Author* newAuthor = new Author(name, gender, bornYear);
    int addChoice = displayAddMenu() + 1;
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
        authorChoice = displayAuthorMenu() + 1;
        system("cls");
        switch (authorChoice) {
            case 1:
                library.listAuthors();
                break;
            case 2: {
                string name;
                cout << "Nhap ten tac gia: ";
                // cin.ignore();
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
    int addChoice = displayAddMenu() + 1;
    system("cls");
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
        bookChoice = displayBookMenu() + 1;
        system("cls");
        switch (bookChoice) {
            case 1:
                library.listBooks();
                break;
            case 2: {
                string title;
                cout << "Nhap ten sach: ";
                // cin.ignore();
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
                // cin.ignore();
                getline(cin, bookID);
                library.deleteBook(bookID);
                break;
            }
            case 6:
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
    // cin.ignore();
    getline(cin, name);
    cout << "Nhap gioi tinh (0: Nu, 1: Nam): ";
    cin >> gender;
    cout << "Nhap lop: ";
    getline(cin, className);
    cout << "Nhap dia chi: ";
    getline(cin, address);
    cout << "Nhap so dien thoai: ";
    getline(cin, phone);
    Reader* newReader = new Reader(name, gender, className, address, phone);
    int addChoice = displayAddMenu() + 1;
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
        readerChoice = displayReaderMenu() + 1;
        system("cls");
        switch (readerChoice) {
            case 1:
                library.listReaders();
                break;
            case 2: {
                string name;
                cout << "Nhap ten doc gia: ";
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
        transactionChoice = displayTransactionMenu() + 1;
        system("cls");
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
                library.overdueTransactions();
                break;
            case 5:
                library.inMonthTransaction();
                break;
            case 6:
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
        }
        printNoti();
    } while (transactionChoice != 6);
}

int main() {
    Library library;
    library.loadCategorys();
    library.loadAuthors();
    library.loadBooks();
    library.loadReaders();
    library.loadTransaction();
    int choice = 0;

    do {
        choice = displayMainMenu() + 1;
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
                system("cls");
                library.statistical();
                system("pause");
                break;
            case 7:
                cout << "Thoat chuong trinh...\n";
                break;
            default: {
                cout << "Lua chon khong hop le." << endl;
                printNoti();
            }
        }
    } while (choice != 7);

    return 0;
}
