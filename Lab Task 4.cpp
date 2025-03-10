// Lab Task 4

//----- - Singly Linked List (Insert at Specific Location) ------

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList() : head(nullptr) {}

    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        display();
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        display();
    }

    void insertAtPosition(int val, int pos) {
        if (pos < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* newNode = new Node(val);
        if (pos == 1 || !head) {
            insertAtStart(val);
            return;
        }
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        display();
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtStart(3);
    list.insertAtStart(1);
    list.insertAtEnd(5);
    list.insertAtEnd(7);
    list.insertAtPosition(4, 2);
    list.insertAtPosition(6, 5);
    return 0;
}
