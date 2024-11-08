#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>
#include "Element.h"

struct Node {
    Element* data;
    Node* next;
    Node* prev;  

    Node(Element* valueptr) : data(valueptr), next(nullptr), prev(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    void addAtFirst(Element* item) {
        if (item == nullptr) {
            throw 0; // 0 là lỗi không tồn tại item
        }
        Node* newNode = new Node(item);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;  
        }
        head = newNode;
        size++;
        cout << "Them thanh cong!" << endl;
    }

    void addAtEnd(Element* item) {
        if (item == nullptr) {
            throw 0; // 0 là lỗi không tồn tại item
        }
        Node* newNode = new Node(item);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;  
        }
        size++;
    }

    void addAtIndex(int index, Element* item) {
        if (item == nullptr) {
            throw 0; // 0 là lỗi không tồn tại item
        }
        if (index < 0 || index > size) {
            cout << "NOT INVALID INDEX!" << endl;
            return;
        }

        if (index == 0) {
            addAtFirst(item);
        } else {
            Node* newNode = new Node(item);
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = newNode;  
            }
            current->next = newNode;
            newNode->prev = current;  
            size++;
        }
        cout << "Them thanh cong!" << endl;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }

    int getSize() const {
        return size;
    }

    Node* getHead() const {
        return head;
    }

    void print() const {
        if (head == nullptr) {
            throw 0; // khong co du lieu
            return;
        }
        head->data->printTable();
        Node* current = head;
        while (current) {
            current->data->printInfo();
            current = current->next;
        }
    }

    void printbyName(const string& name) const {
        if (head == nullptr) {
            throw 0; // khong co du lieu
            return;
        }
        head->data->printTable();
        Node* current = head;
        while (current) {
            if (isSubstring(current->data->getName(), name)) current->data->printInfo();
            current = current->next;
        }
    }

    void sortIncreasing(bool (*compare)(const Element&, const Element&)) {
        if (!head || !head->next) return;
        for (Node* i = head; i != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (!compare(*(i->data), *(j->data))) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    void deleteNode(Node* node) {
        if (head == nullptr || node == nullptr) {
            throw 1; // Khong ton tai du lieu node
            return;
        }
        if (head == node) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr; 
            }
            delete node->data;
            delete node;
            size--;
            return;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;  
        }
        if (node->prev != nullptr) {
            node->prev->next = node->next;  
        }
        delete node->data;
        delete node;
        size--;
    }
    void deleteNodebyID(const string& ID) {
        Node* target = findNodebyID(ID);
        if (target == nullptr) {
            throw 1; // khong ton tai du lieu
            return;
        }
        if (target->data->isAvailabletoDelete() == 0) throw 0; // Không thể xóa
        deleteNode(findNodebyID(ID));
        cout << "Xoa thanh cong!" << endl;
    }
    Element* findbyID(const string& ID) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data->getId() == ID) {
                return current->data;
            }
            current = current->next;
        }
        return nullptr;
    }
    Node* findNodebyID(const string& ID) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data->getId() == ID) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};

#endif
