// LAb Task 9


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* tail;
    int size;

public:
    CircularLinkedList() : tail(nullptr), size(0) {}

    void add(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void addFirst(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
        size++;
    }

    void addAt(int pos, int val) {
        if (pos < 1 || pos > size + 1) return;
        if (pos == 1) return addFirst(val);
        if (pos == size + 1) return add(val);

        Node* newNode = new Node(val);
        Node* temp = tail->next;
        for (int i = 1; i < pos - 1; i++) temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    void addCenter(int val) {
        addAt((size / 2) + (size % 2), val);
    }

    void show() {
        if (!tail) return;
        Node* temp = tail->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }

    void showReverse() {
        if (!tail) return;
        for (int i = 0; i < size; i++) {
            Node* prev = tail->next;
            while (prev->next != tail) prev = prev->next;
            cout << tail->data << " ";
            tail = prev;
        }
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.add(10);
    cll.add(20);
    cll.add(30);
    cll.add(40);
    cll.addCenter(25);
    cll.addAt(2, 15);
    
    cll.show();
    cll.showReverse();

    return 0;
}
