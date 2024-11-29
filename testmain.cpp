#include <iostream>
#include "Element.h"
#include "Book.h"
#include "Reader.h"
#include "Transaction.h"
#include "LM.h"
#include "dohoa.h"
using namespace std;
int displaySortBook() {
    string menu[] = {
        "1.ID",
        "2.Tieu de",
        "3.Tong so sach",
        "4.So sach hien co",
        "5.So lan duoc muon",
        "6.Quay ve"
    };
    return printMenu(menu, 6, "SORT BOOK MENU");
}

int displaySortReader() {
    string menu[] = {
        "1.ID",
        "2.Ten",
        "3.So sach dang muon",
        "4.Quay ve"
    };
    return printMenu(menu, 4, "SORT READER MENU");
}

int displaySortAuthor() {
    string menu[] = {
        "1.ID",
        "2.Ten",
        "3.So sach dang co",
        "4.Quay ve"
    };
    return printMenu(menu, 4, "SORT AUTHOR MENU");
}

int displaySortCategory() {
    string menu[] = {
        "1.ID",
        "2.Ten",
        "3.So sach dang co",
        "4.Quay ve"
    };
    return printMenu(menu, 4, "SORT CATEGORY MENU");
}

int displayFixBook() {
    string menu[] = {
        "1.Tieu de",
        "2.Tac gia",
        "3.The loai",
        "4.Nam",
        "5.Trang",
        "6.Tong so sach",
        "7.Quay ve" 
    };
    return printMenu(menu, 7, "FIX BOOK MENU");
}

int displayFixReader() {
    string menu[] = {
        "1.Ten",
        "2.Gioi tinh",
        "3.Lop",
        "4.Dia chi",
        "5.SDT",
        "6.Quay ve"
    };
    return printMenu(menu, 6, "FIX READER MENU");
}

int displayFixAuthor() {
    string menu[] = {
        "1.Ten",
        "2.Gioi tinh",
        "3.Nam sinh",
        "4.Quay ve"
    };
    return printMenu(menu, 4, "FIX AUTHOR MENU");
}

int displayFixCategory() {
    string menu[] = {
        "1.Ten",
        "2.Quay ve"
    };
    return printMenu(menu, 2, "FIX CATEGORY MENU");
}

int displayMenuFix() {
    string menu[] = {
        "1.Sach",
        "2.Doc gia",
        "3.Tac gia",
        "4.The loai",
        "5.Quay ve"
    };
    return printMenu(menu, 5, "FIX MENU");
}
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
        "7. Chinh sua",
        "8. Thoat"
    };
    return printMenu(menuu, 8, "QUAN LY THU VIEN");
    return 0;
}
int displayCategoryMenu() {
    string menu[] = {
        "1. Danh sach the loai", 
        "2. Tim kiem the loai", 
        "3. Tra cuu the loai", 
        "4. Them moi the loai", 
        "5. Xoa the loai",
        "6. Sap xep", 
        "7. Quay lai menu chinh"
    };
    return printMenu(menu, 7, "QUAN LY THE LOAI");
}

int displayAuthorMenu() {
    string menu[] = {
        "1. Danh sach tac gia", 
        "2. Tim kiem tac gia", 
        "3. Tra cuu tac gia", 
        "4. Them moi tac gia", 
        "5. Xoa tac gia", 
        "6. Sap xep",
        "7. Quay lai menu chinh"
    };
    return printMenu(menu, 7, "QUAN LY TAC GIA");
}

int displayBookMenu() {
    string menu[] = {
        "1. Danh sach sach", 
        "2. Tim kiem sach", 
        "3. Tra cuu sach", 
        "4. Them moi sach", 
        "5. Xoa sach", 
        "6. Sap xep",
        "7. Quay lai menu chinh"
    };
    return printMenu(menu, 7, "QUAN LY SACH");
}

int displayReaderMenu() {
    string menu[] = {
        "1. Danh sach doc gia", 
        "2. Tim kiem doc gia", 
        "3. Tra cuu doc gia", 
        "4. Them moi doc gia", 
        "5. Xoa doc gia",
        "6. Sap xep", 
        "7. Quay lai menu chinh"
    };
    return printMenu(menu, 7, "QUAN LY DOC GIA");
}

int displayTransactionMenu() {
    string menu[] = {
        "1. Muon sach", 
        "2. Tra sach", 
        "3. Danh sach giao dich", 
        "4. Giao dich qua han",
        "5. Giao dich gan day", 
        "6. Quay lai menu chinh"
    };
    return printMenu(menu, 6, "QUAN LY GIAO DICH");
}
// Xu ly
void fixBook(Library& library, Book* needFixBook) {
    printNoti();
    int choice;
    do
    {
        choice = displayFixBook() + 1;
        system("cls");
        switch (choice) {
            case 1: {
                string newName;
                cout << "Nhap tieu de moi: ";
                getline(cin, newName);
                needFixBook->setName(newName);
                cout << "Chinh sua thanh cong" << endl;
                break;
            }
            case 2: {
                string newAuthorID;
                cout << "Nhap ID tac gia moi: ";
                getline(cin, newAuthorID);
                Author* newAuthorPtr = library.findAuthorbyID(newAuthorID);
                if (newAuthorPtr == nullptr) {
                    cout << "Khong ton tai tac gia co ID " << newAuthorID << endl;
                    break;
                }
                needFixBook->setAuthorPtr(newAuthorPtr);
                cout << "Chinh sua thanh cong" << endl;
                break;
            }
            case 3: {
                string newCategoryID;
                cout << "Nhap ID the loai moi: ";
                getline(cin, newCategoryID);
                Category* newCategoryPtr = library.findCategorybyID(newCategoryID);
                if (newCategoryPtr == nullptr) {
                    cout << "Khong ton tai the loai co ID " << newCategoryID << endl;
                    break;
                }
                needFixBook->setCategory(newCategoryPtr);
                cout << "Chinh sua thanh cong" << endl;
                break;
            }
            case 4: {
                string newYearStr;
                int newYear;
                cout << "Nhap nam xuat ban moi: ";
                getline(cin, newYearStr);
                newYear = toInt(newYearStr);
                if (newYear < 0) {
                    cout << "Nam xuat ban khong hop le" << endl;
                    break;
                }
                needFixBook->setYear(newYear);
                cout << "Chinh sua thanh cong" << endl;
                break;
            }
            case 5: {
                string newPagesStr;
                int newPages;
                cout << "Nhap so trang moi: ";
                getline(cin, newPagesStr);
                newPages = toInt(newPagesStr);
                if (newPages <= 0) {
                    cout << "So trang khong hop le" << endl;
                    break;
                }
                needFixBook->setPages(newPages);
                cout << "Chinh sua thanh cong" << endl;
                break;
            }
            case 6: {
                string newTotalCopiesStr;
                int newTotalCopies;
                cout << "Nhap tong so sach moi: ";
                getline(cin, newTotalCopiesStr);
                newTotalCopies = toInt(newTotalCopiesStr);
                int diff = needFixBook->getTotalCopies() - newTotalCopies;
                if (diff > needFixBook->getAvailableCopies() || newTotalCopies <= 0) {
                    cout << "Tong so sach khong hop le" << endl;
                }
                needFixBook->setTotalCopies(needFixBook->getTotalCopies() - diff);
                cout << "Chinh sua thanh cong" << endl;
                break;
            }
            case 7: 
                return;
            default:
                cout << "Lua chon khong hop le" << endl;
        }
        printNoti();
    } while (choice != 7);
}

void fixReader(Library& library, Reader* needFixReader) {
    printNoti();
    int choice;
    do
    {
        choice = displayFixReader() + 1;
        system("cls");
        switch (choice) {
            case 1: {
                string newName;
                cout << "Nhap ten: ";
                getline(cin, newName);
                needFixReader->setName(newName);
                cout << "Chinh sua thanh cong" << endl;
                break;
            }
            case 2: {
                string genderStr;
                int gender;
                cout << "Nhap gioi tinh (0: Nu, 1: Nam): ";
                getline(cin, genderStr);
                gender = toInt(genderStr);
                if (gender < 0 || gender > 1) {
                    cout << "Gioi tinh khong hop le!" << endl;
                    break;
                }
                needFixReader->setGender(gender);
                cout << "Chinh sua thanh cong" << endl;
                break;
            }
            case 3: {
                string className;
                cout << "Nhap lop: ";
                getline(cin, className);
                needFixReader->setClassName(className);
                cout << "Chinh sua thanh cong" << endl;
                break;
            }
            case 4: {
                string address;
                cout << "Nhap dia chi: ";
                getline(cin, address);
                needFixReader->setAddress(address);
                cout << "Chinh sua thanh cong" << endl;
                break;
            }
            case 5: {
                string phone;
                cout << "Nhap so dien thoai: ";
                getline(cin, phone);
                needFixReader->setPhoneNumber(phone);
                cout << "Chinh sua thanh cong" << endl;
                break;
            }
            case 6: {
                return;
            }
            default:
                cout << "Lua chon khong hop le" << endl;
        }
        printNoti();
    } while (choice != 6);
}

void fixAuthor(Library& library, Author* needFixAuthor) {
    printNoti();
    int choice;
    do
    {
        choice = displayFixAuthor() + 1;
        system("cls");
        switch (choice) {
            case 1: {
                string newName;
                cout << "Nhap ten: ";
                getline(cin, newName);
                needFixAuthor->setName(newName);
                cout << "Chinh sua thanh cong" << endl;
                break;
            }
            case 2: {
                string genderStr;
                int gender;
                cout << "Nhap gioi tinh (0: Nu, 1: Nam): ";
                getline(cin, genderStr);
                gender = toInt(genderStr);
                if (gender < 0 || gender > 1) {
                    cout << "Gioi tinh khong hop le!" << endl;
                    break;
                }
                needFixAuthor->setGender(gender);
                cout << "Chinh sua thanh cong" << endl;
                break;
            }
            case 3: {
                string bornYearStr;
                int bornYear;
                cout << "Nhap nam sinh: ";
                getline(cin, bornYearStr);
                bornYear = toInt(bornYearStr);
                if (bornYear < 0) {
                    cout << "Nam sinh khong hop le!" << endl;
                    break;
                }
                needFixAuthor->setBornYear(bornYear);
                cout << "Chinh sua thanh cong" << endl;
                break;
            }
            case 4: {
                return;
            }
            default:
                cout << "Lua chon khong hop le" << endl;
        }
        printNoti();
    } while (choice != 4);
}

void fixCategory(Library& library, Category* needFixCategory) {
    printNoti();
    int choice;
    do
    {
        choice = displayFixCategory() + 1;
        system("cls");
        switch (choice) {
            case 1: {
                string newName;
                cout << "Nhap ten: ";
                getline(cin, newName);
                needFixCategory->setName(newName);
                cout << "Chinh sua thanh cong" << endl;
                break;
            }
            case 2: {
                return;
            }
            default:
                cout << "Lua chon khong hop le" << endl;
        }
        printNoti();
    } while (choice != 2);
}

void manageFix(Library& library) {
    int choice;
    do
    {
        choice = displayMenuFix() + 1;
        system("cls");
        switch (choice) {
            case 1: {
                string bookID;
                cout << "Nhap ID cua sach can sua: ";
                getline(cin, bookID);
                Book* book = library.findBookbyID(bookID);
                if (book == nullptr) {
                    cout << "Khong ton tai sach co ID " << bookID << endl;
                    break;
                }
                fixBook(library, book);
                break;
            }
            case 2: {
                string readerID;
                cout << "Nhap ID cua doc gia can sua: ";
                getline(cin, readerID);
                Reader* reader = library.findReaderbyID(readerID);
                if (reader == nullptr) {
                    cout << "Khong ton tai doc gia co ID " << readerID << endl;
                    break;
                }
                fixReader(library, reader);
                break;
            }
            case 3: {
                string authorID;
                cout << "Nhap ID cua tac gia can sua: ";
                getline(cin, authorID);
                Author* author = library.findAuthorbyID(authorID);
                if (author == nullptr) {
                    cout << "Khong ton tai tac gia co ID " << authorID << endl;
                    break;
                }
                fixAuthor(library, author);
                break;
            }
            case 4: {
                string categoryID;
                cout << "Nhap ID cua the loai can sua: ";
                getline(cin, categoryID);
                Category* category = library.findCategorybyID(categoryID);
                if (category == nullptr) {
                    cout << "Khong ton tai the loai co ID " << categoryID << endl;
                    break;
                }
                fixCategory(library, category);
                break;
            }
            case 5: 
                return;
            default : 
                cout << "Lua chon khong hop le" << endl;
        }
        printNoti();
    } while (choice != 5);
}

void sortCategory(Library& library) {
    int sortChoice;
    do
    {
        sortChoice = displaySortCategory() + 1;
        switch (sortChoice) {
            case 1:
                library.sortCategoryByID();
                break;
            case 2:
                library.sortCategoryByName();
                break;
            case 3: {
                library.sortCategoryByBookCount();
                break;
            }
            case 4:
                return;
            default:
                cout << "Lua chon khong hop le." << endl;
        }
        printNoti();   
    } while (sortChoice != 4);
    
}
void addNewCategory(Library& library) {
    string name;
    cout << "Nhap ten the loai: ";
    getline(cin, name);
    Category* newCategory = new Category(name);
    printNoti();
    int addChoice = displayAddMenu() + 1;
    system("cls");
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
            cin.ignore();
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
                getline(cin, CategoryID);
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
                getline(cin, CategoryID);
                library.deleteCategory(CategoryID);
                break;
            }
            case 6:
                sortCategory(library);
                break;
            case 7:
                return;
            default:
                cout << "Lua chon khong hop le." << endl;
        }
        if (categoryChoice != 6) printNoti();
        system("cls");
    } while (categoryChoice != 7);
}

void sortAuthor(Library& library) {
    int sortChoice;
    do
    {
        sortChoice = displaySortAuthor() + 1;
        switch (sortChoice) {
            case 1:
                library.sortAuthorByID();
                break;
            case 2:
                library.sortAuthorByName();
                break;
            case 3: {
                library.sortAuthorByBookCount();
                break;
            }
            case 4:
                return;
            default:
                cout << "Lua chon khong hop le." << endl;
        }    
    } while (sortChoice != 4);
    
}
void addNewAuthor(Library& library) {
    string name, genderStr, bornYearStr;
    int gender;
    int bornYear;
    cout << "Nhap ten tac gia: ";
    getline(cin, name);
    cout << "Nhap gioi tinh (0: Nu, 1: Nam): ";
    // cin >> gender;
    getline(cin, genderStr);
    gender = toInt(genderStr);
    if (gender < 0 || gender > 1) {
        cout << "Gioi tinh khong hop le!" << endl;
        return;
    }
    cout << "Nhap nam sinh: ";
    // cin >> bornYear;
    getline(cin, bornYearStr);
    bornYear = toInt(bornYearStr);
    if (bornYear < 0) {
        cout << "Nam sinh khong hop le!" << endl;
        return;
    }
    // cin.ignore();
    Author* newAuthor = new Author(name, gender, bornYear);
    printNoti();
    int addChoice = displayAddMenu() + 1;
    system("cls");
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
            cin.ignore();
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
                getline(cin, name);
                library.searchAuthorByName(name);
                break;
            }
            case 3: {
                string AuthorID;
                cout << "Nhap ID tac gia: ";
                getline(cin, AuthorID);
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
                getline(cin, AuthorID);
                library.deleteAuthor(AuthorID);
                break;
            }
            case 6:
                sortAuthor(library);
                break;
            case 7:
                return;
            default:
                cout << "Lua chon khong hop le." << endl;
        }
        if (authorChoice != 6) printNoti();
    } while (authorChoice != 7);
}
// Chức năng quản lý sách
void sortBook(Library& library) {
    int sortChoice;
    do
    {
        sortChoice = displaySortBook() + 1;
        switch (sortChoice) {
            case 1:
                library.sortBookByID();
                break;
            case 2:
                library.sortBookByName();
                break;
            case 3: {
                library.sortBookByTotalCopies();
                break;
            }
            case 4:
                library.sortBookByAvaiableCopies();
                break;
            case 5:
                library.sortBookByCountBorrow();
            case 6:
                return;
            default:
                cout << "Lua chon khong hop le." << endl;
        }   
        printNoti();
    } while (sortChoice != 6);
    
}
void addNewBook(Library& library) {
    string title, authorID, categoryID, yearStr, pagesStr, totalCopiesStr;
    int year, pages, totalCopies;
    cout << "Nhap tieu de sach: ";
    getline(cin, title);
    cout << "Nhap ID tac gia: ";
    getline(cin, authorID);
    if (library.findAuthorbyID(authorID) == nullptr) {
        cout << "Khong ton tai tac gia co ID " << authorID << endl;
        return;
    }
    cout << "Nhap ID the loai: ";
    getline(cin, categoryID);
    if (library.findCategorybyID(categoryID) == nullptr) {
        cout << "Khong ton tai the loai co ID " << categoryID << endl;
        return;
    }
    cout << "Nhap nam xuat ban: ";
    // cin >> year;
    getline(cin, yearStr);
    year = toInt(yearStr);
    if (year < 0) {
        cout << "Nam xuat ban khong hop le" << endl;
        return;
    }
    cout << "Nhap so trang: ";
    // cin >> pages;
    getline(cin, pagesStr);
    pages = toInt(pagesStr);
    if (pages <= 0) {
        cout << "So trang khong hop le" << endl;
        return;
    }
    cout << "Nhap tong so ban sao: ";
    // cin >> totalCopies;
    getline(cin, totalCopiesStr);
    totalCopies = toInt(totalCopiesStr);
    if (totalCopies <= 0) {
        cout << "So ban sao khong hop le" << endl;
        return;
    }
    // cin.ignore();
    Book* newBook = library.createNewBook(title, authorID, categoryID, year, pages, totalCopies);
    if (newBook == nullptr) {
        cout << "Khong the tao sach!" << endl;
        return;
    }
    printNoti();
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
            cin.ignore();
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
                cin.ignore();
                getline(cin, title);
                library.searchBookByTitle(title);
                break;
            }
            case 3: {
                string bookID;
                cout << "Nhap ID sach: ";
                getline(cin, bookID);
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
                sortBook(library);
                break;
            case 7:
                return;
            default:
                cout << "Lua chon khong hop le." << endl;
        }
        if (bookChoice != 6) printNoti();
    } while (bookChoice != 7);
}
// Chức năng quản lý độc giả
void sortReader(Library& library) {
    int sortChoice;
    do
    {
        sortChoice = displaySortReader() + 1;
        switch (sortChoice) {
            case 1:
                library.sortReaderByID();
                break;
            case 2:
                library.sortReaderByName();
                break;
            case 3: {
                library.sortReaderByBookCount();
                break;
            }
            case 4:
                return;
            default:
                cout << "Lua chon khong hop le." << endl;
        }    
    } while (sortChoice != 4);
    
}
void addNewReader(Library& library) {
    string name, className, address, phone, genderStr;
    int gender;
    cout << "Nhap ten doc gia: ";
    getline(cin, name);
    cout << "Nhap gioi tinh (0: Nu, 1: Nam): ";
    // cin >> gender;
    getline(cin, genderStr);
    gender = toInt(genderStr);
    if (gender < 0 || gender > 1) {
        cout << "Gioi tinh khong hop le!" << endl;
        return;
    }
    cout << "Nhap lop: ";
    getline(cin, className);
    cout << "Nhap dia chi: ";
    getline(cin, address);
    cout << "Nhap so dien thoai: ";
    getline(cin, phone);
    Reader* newReader = new Reader(name, gender, className, address, phone);
    printNoti();
    int addChoice = displayAddMenu() + 1;
    system("cls");
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
            cin.ignore();
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
                getline(cin, readerID);
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
                getline(cin, readerID);
                library.deleteReader(readerID);
                break;
            }
            case 6:
                sortReader(library);
                break;
            case 7:
                return;
            default:
                cout << "Lua chon khong hop le." << endl;
        }
        if(readerChoice != 6) printNoti();
    } while (readerChoice != 7);
}
// Chức năng quản lý giao dịch
void manageTransactions(Library& library) {
    int transactionChoice;
    do {
        transactionChoice = displayTransactionMenu() + 1;
        system("cls");
        switch (transactionChoice) {
            case 1: {
                string readerID, bookID, numberStr;
                int number;
                cout << "Nhap ID doc gia: ";
                getline(cin, readerID);
                if (library.findReaderbyID(readerID) == nullptr) {
                    cout << "Khong ton tai doc gia co ID " << readerID << endl;
                    break;
                }
                cout << "Nhap so sach can muon: "; 
                getline(cin, numberStr);
                number = toInt(numberStr);
                while (number > 0) {
                    cout << "Nhap ID sach: ";
                    getline(cin, bookID);
                    if (library.findBookbyID(bookID) == nullptr) {
                        cout << "Khong ton tai sach co ID " << bookID << endl;
                        break;
                    }
                    library.borrowBook(readerID, bookID);
                    number--;
                }
                break;
            }
            case 2: {
                string readerID, bookID, numberStr;
                int number;
                cout << "Nhap ID doc gia: ";
                getline(cin, readerID);
                if (library.findReaderbyID(readerID) == nullptr) {
                    cout << "Khong ton tai doc gia co ID " << readerID << endl;
                    break;
                }
                cout << "Nhap so sach can tra: "; 
                getline(cin, numberStr);
                number = toInt(numberStr);
                while (number > 0) {
                    cout << "Nhap ID sach: ";
                    getline(cin, bookID);
                    if (library.findBookbyID(bookID) == nullptr) {
                        cout << "Khong ton tai sach co ID " << bookID << endl;
                        break;
                    }
                    library.returnBook(readerID, bookID);
                    number--;
                }
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
                return;
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
                manageFix(library);
                break;
            case 8:
                cout << "Thoat chuong trinh...\n";
                break;
            default: {
                cout << "Lua chon khong hop le." << endl;
                printNoti();
            }
        }
    } while (choice != 8);
    library.writeReaders();
    library.writeBooks();
    library.writeTransaction();
    library.writeAuthors();
    library.writeCategorys();
    return 0;
}
