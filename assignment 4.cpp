#include <iostream>
using namespace std;
//creating a class for the construction of a Node
class Node {
public:
    //assinging data to the string data type
    string data;
    Node* next;

    Node(string value) {
        data = value;
        next = nullptr;
    }
};
//creating the CircularQueue
class CircularQueue {
private:
    Node* rear;

public:
    CircularQueue() {
        rear = nullptr;
    }
//implemented the is empty operation to determine if the rear portion of the node is empty then return back null
    bool isEmpty() {
        return rear == nullptr;
    }
//creating the enqueue function to add a element ot the queue
    void enqueue(string value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            rear = newNode;
            rear->next = rear;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued\n";
    }
// creating the dequeue function to delete an element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* front = rear->next;
        if (rear == front) {
            rear = nullptr;
        } else {
            rear->next = front->next;
        }
        cout << front->data << " dequeued\n";
        delete front;
    }
// creating the GetFront function to get the front item from the queue
    void getFront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front element: " << rear->next->data << "\n";
    }
};

int main() {
    //creating a object called restaurants
    CircularQueue restaurants;
    restaurants.enqueue("in-n-out");
    restaurants.enqueue("five-guys");
    restaurants.enqueue("shake-shack");
    restaurants.getFront();
    restaurants.dequeue();
    restaurants.getFront();
    restaurants.dequeue();
    restaurants.dequeue();
    restaurants.dequeue();
    return 0;
}

