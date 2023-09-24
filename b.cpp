#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    
    void insertSortedIterative(int value) {
        Node* newNode = new Node(value);
        newNode->data = value;
        newNode->next = NULL;

        if (head==NULL || head->data >= value) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* curr = head;
        while (curr->next && curr->next->data < value) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void display() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout <<endl;
    }

    void deleteElement(int value) {
        Node* current = head;
        Node* prev = NULL;

        while (current && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current==NULL) {
            cout << "Element not found in the list." <<endl;
            return;
        }

        if (prev==NULL) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        free (current);
        cout << "Element deleted from the list." <<endl;
    }
};

int main() {
    LinkedList list;

    list.insertSortedIterative(5);
    list.insertSortedIterative(2);
    list.insertSortedIterative(8);
    list.insertSortedIterative(1);
    list.insertSortedIterative(7);

    cout << "Sorted Linked List (Iterative): ";
    list.display();

    list.deleteElement(2);
    cout << "After deleting 2: ";
    list.display();

    list.deleteElement(8);
    cout << "After deleting 8: ";
    list.display();

    return 0;
}