// Lab Task 8


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class DoublyNode {
public:
    int data;
    DoublyNode* prev;
    DoublyNode* next;
    DoublyNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void add(int val) {
        Node* newNode = new Node(val);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void merge(SinglyLinkedList& other) {
        if (!head) head = other.head;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = other.head;
        }
        other.head = nullptr;
    }

    void show() {
        for (Node* temp = head; temp; temp = temp->next) cout << temp->data << " ";
        cout << endl;
    }
};

class DoublyLinkedList {
private:
    DoublyNode* head;
    DoublyNode* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void add(int val) {
        DoublyNode* newNode = new DoublyNode(val);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void merge(DoublyLinkedList& other) {
        if (!head) head = other.head, tail = other.tail;
        else {
            tail->next = other.head;
            if (other.head) other.head->prev = tail;
            tail = other.tail;
        }
        other.head = other.tail = nullptr;
    }

    void show() {
        for (DoublyNode* temp = head; temp; temp = temp->next) cout << temp->data << " ";
        cout << endl;
    }
};

int main() {
    SinglyLinkedList s1, s2;
    s1.add(1); s1.add(2); s1.add(3);
    s2.add(4); s2.add(5); s2.add(6);
    s1.merge(s2);
    s1.show();

    DoublyLinkedList d1, d2;
    d1.add(10); d1.add(20); d1.add(30);
    d2.add(40); d2.add(50); d2.add(60);
    d1.merge(d2);
    d1.show();

    return 0;
}
