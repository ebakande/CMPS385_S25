#include <iostream>
using namespace std;

// Created class named Node to create nodes with data and pointers for doubly linked list
class Node {
public:
    int data;
    Node *next;
    Node *prev;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    // Parameterized Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Created a doubly linked list class
class DoublyLinkedList {
    Node *head;
public:
    // Default constructor
    DoublyLinkedList() {
        head = NULL;
    }

    // Function to insert a node at the start of the doubly linked list
    void insertAtHead(int data) {
        // Create the new Node
        Node *newNode = new Node(data);

        // Assign to head if the list is empty
        if (head == NULL) {
            head = newNode;
            return;
        }

        // Insert the new node at the head
        newNode->next = head;
        head->prev = newNode; // Set previous pointer of existing head
        head = newNode;
    }

    // Function to print the doubly linked list
    void print() {
        Node *temp = head;

        // Check for empty list
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        // Traverse and print the list
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to delete the entire linked list
    void deleteList() {
        Node *current = head;
        Node *nextNode;

        while (current != NULL) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = NULL;
        cout << "Doubly linked list deleted." << endl;
    }
};

int main() {
    // Creating a DoublyLinkedList object
    DoublyLinkedList list;

    // Inserting nodes
    list.insertAtHead(4);
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);

    cout << "Elements of the list: ";
    list.print(); // Print the list

    // Deleting the list
    list.deleteList();

    return 0;
}

