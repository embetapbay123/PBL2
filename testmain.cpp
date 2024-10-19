#include <iostream>
#include <limits> 
#include "LM.h" 
void printNoti(){
	cin.ignore();
	cout << "Press any key to continue..";
	getchar();
}
using namespace std;

int main() {
    Library library;
    library.loadBooks();
    library.loadReaders();

    int choice;
    do {
        cout << "\n=== MENU QUAN LY THU VIEN ===\n";
        cout << "1. Danh sach sach\n";
        cout << "2. Danh sach doc gia\n";
        cout << "3. Muon sach\n";
        cout << "4. Tra sach\n";
        cout << "5. Tim kiem sach theo ten\n";
        cout << "6. Tim kiem doc gia theo ten\n";
        cout << "7. Danh sach giao dich\n";
        cout << "8. Danh sach giao dich qua han\n";
        cout << "9. Tra cuu doc gia\n";
        cout << "10. Tra cuu sach\n";
        cout << "11. Them moi sach\n";
        cout << "12. Them moi nguoi doc\n";
        cout << "13. Xoa nguoi doc\n";
        cout << "14. Xoa sach\n";
        cout << "15. Thong ke, sap xep\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";

        cin >> choice;

        while (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Vui long nhap mot so nguyen: ";
            cin >> choice;
        }
        switch (choice) {
            case 1:
                library.listBooks();
                printNoti();
                break;
            case 2:
                library.listReaders();
                printNoti();
                break;
            case 3: {
                string readerID, bookID;
                cout << "Nhap ID doc gia: ";
                cin >> readerID;
                cout << "Nhap ID sach: ";
                cin >> bookID;
                library.borrowBook(readerID, bookID);
                printNoti();
                break;
            }
            case 4: {
                string readerID, bookID;
                cout << "Nhap ID doc gia: ";
                cin >> readerID;
                cout << "Nhap ID sach: ";
                cin >> bookID;
                library.returnBook(readerID, bookID);
                printNoti();
                break;
            }
            case 5: {
                string title;
                cout << "Nhap ten sach: ";
                cin.ignore();
                getline(cin, title);
                library.searchBookByTitle(title);
                printNoti();
                break;
            }
            case 6: {
                string name;
                cout << "Nhap ten doc gia: ";
                cin.ignore();
                getline(cin, name);
                library.searchReaderByName(name);
                printNoti();
                break;
            }
            case 7:
                library.listTransactions();
                printNoti();
                break;
            case 8:
                library.overdueBooks();
                printNoti();
                break;
            case 9: {
                string readerID;
                cout << "Nhap ID doc gia: ";
                cin >> readerID;
                library.infoReaderbyID(readerID);
                printNoti();
                break;
            }
            case 10: {
                string bookID;
                cout << "Nhap ID sach: ";
                cin >> bookID;
                library.infoBookbyID(bookID);
                printNoti();
                break;
            }
            case 11: {
                string title, author, category;
                int year, pages, totalCopies;

                cout << "Nhap tieu de sach: ";
                cin.ignore(); // B? qua ký t? newline còn sót l?i
                getline(cin, title);
                
                cout << "Nhap tac gia: ";
                getline(cin, author);
                
                cout << "Nhap the loai: ";
                getline(cin, category);
                
                cout << "Nhap nam xuat ban: ";
                cin >> year;
                
                cout << "Nhap so trang: ";
                cin >> pages;
                
                cout << "Nhap tong so ban sao: ";
                cin >> totalCopies;

                Book* newBook = library.createNewBook(title, author, category, year, pages, totalCopies);

                // Ch?n v? trí d? thêm sách
                int addChoice;
                cout << "1. Them vao dau danh sach\n";
                cout << "2. Them vao cuoi danh sach\n";
                cout << "3. Them theo index\n";
                cout << "Nhap lua chon cua ban: ";
                cin >> addChoice;

                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Vui long nhap mot so nguyen: ";
                    cin >> addChoice;
                }

                switch (addChoice) {
                    case 1:
                        library.addBookAtHead(newBook);
                        cout << "Sach da duoc them vao dau danh sach." << endl;
                        break;
                    case 2:
                        library.addBookAtEnd(newBook);
                        cout << "Sach da duoc them vao cuoi danh sach." << endl;
                        break;
                    case 3: {
                        int index;
                        cout << "Nhap chi so de them sach: ";
                        cin >> index;
                        library.addBookAtIndex(index, newBook);
                        cout << "Sach da duoc them vao chi so " << index << "." << endl;
                        break;
                    }
                    default:
                        cout << "Lua chon khong hop le, vui long thu lai." << endl;
                }
                printNoti();
                break;
            }
            case 12: {
			    string name, gender, className, address, phone;
			    cout << "Nhap ten doc gia: ";
			    cin.ignore(); 
			    getline(cin, name);
			    cout << "Nhap gioi tinh: ";
			    getline(cin, gender);
			    cout << "Nhap lop: ";
			    getline(cin, className);
			    cout << "Nhap dia chi: ";
			    getline(cin, address);
			    cout << "Nhap so dien thoai: ";
			    getline(cin, phone);
			    Reader* newReader = library.createNewReader(name, gender, className, address, phone);

                int addChoice;
                cout << "1. Them vao dau danh sach\n";
                cout << "2. Them vao cuoi danh sach\n";
                cout << "3. Them theo index\n";
                cout << "Nhap lua chon cua ban: ";
                cin >> addChoice;

                // Ki?m tra n?u ngu?i dùng nh?p không ph?i s?
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Vui long nhap mot so nguyen: ";
                    cin >> addChoice;
                }

                switch (addChoice) {
                    case 1:
                        library.addReaderAtHead(newReader);
                        cout << "Nguoi doc da duoc them vao dau danh sach." << endl;
                        break;
                    case 2:
                        library.addReaderAtEnd(newReader);
                        cout << "Nguoi doc da duoc them vao cuoi danh sach." << endl;
                        break;
                    case 3: {
                        int index;
                        cout << "Nhap chi so de them sach: ";
                        cin >> index;
                        library.addReaderAtIndex(index, newReader);
                        cout << "Nguoi doc da duoc them vao chi so " << index << "." << endl;
                        break;
                    }
                    default:
                        cout << "Lua chon khong hop le, vui long thu lai." << endl;
                }
                printNoti();
				break;
			}
            case 13: {
                string readerID;
                cout << "Nhap ID doc gia: ";
                cin >> readerID;
                library.deleteReader(readerID);
                printNoti();
                break;
            }
            case 14: {
                string bookID;
                cout << "Nhap ID sach: ";
                cin >> bookID;
                library.deleteBook(bookID);
                printNoti();
                break;
            }
			case 15: {
				cout << "Chua cap nhat" << endl;
				printNoti();
				break;
			}
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le, vui long thu lai." << endl;
                printNoti();
        }
    } while (choice != 0);

    return 0;
}

