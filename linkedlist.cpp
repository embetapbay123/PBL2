#include <bits/stdc++.h>
using namespace std;

class Node {  
public:  
	int data;  
	Node *next;  
	  
	Node(int data) {  
		this->data = data;  
	    this->next = nullptr;  
	}  
};  
    
class LinkedList {  
private:  
  	Node *head;  
  
public:  
  	LinkedList() {  
    	this->head = nullptr;  
  	}  
  	void insertAtEnd(int data) {  
    	Node *newNode = new Node(data);  
    	if (head == nullptr) {  
      	head = newNode;  
      	return;  
    	}  
		Node *temp = head;  
	    while (temp->next != nullptr) {  
	      temp = temp->next;  
	    }  
	    temp->next = newNode;  
  	}  
	void deleteAtBeginning() {  
	    if (head == nullptr) {  
	      return;  
	    }  
	    Node *temp = head;  
	    head = head->next;  
	    delete temp;  
	}  
	void printList() {  
	  Node *temp = head;  
	  while (temp != nullptr) {  
	    cout << temp->data << " ";  
	    temp = temp->next;  
	  }  
	  cout << endl;  
	}  
};  
  

int main(){
	
}



