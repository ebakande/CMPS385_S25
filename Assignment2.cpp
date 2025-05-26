#include <iostream>
#include <stack>  // Include stack library
using namespace std;
// creating class to create a stack stack name creates is called Plates and value type is integer.
class Stack {
private:
    stack<int> plates;

public:
    // Push an element onto the stack
    void push(int value) {
        plates.push(value);
    }

    // Return the top element of the stack (PLATES)
    int top() {
        if (!plates.empty()) {
            return plates.top();
        } else {
            cout << "Stack is empty!" << endl;
            return -1;  // Return -1 as an indicator of an empty stack
        }
    }

    // Pop the top element from the stack (PLATES)
    void pop() {
        if (!plates.empty()) {
            plates.pop();
        } else {
            cout << "Stack is already empty!" << endl;
        }
    }

    // Check if the stack (PLATES) is empty
    bool isEmpty() {
        return plates.empty();
    }

    // Print all elements and clear the stack (PLATES)
    void printAndEmpty() {
        while (!plates.empty()) {
            cout << plates.top() << " ";
            plates.pop();
        }
        cout << endl;
    }
};

int main() {
    // Create a object named stackObj of the Stack class
    Stack stackObj;

    // Pushing 3 elements onto the stack (PLATES)
    stackObj.push(0);
    stackObj.push(1);
    stackObj.push(2);

    // Displaying the top element of the stack (PLATES)
    cout << "Top element: " << stackObj.top() << endl;

    // Removing the top element of the stack (PLATES)
    stackObj.pop();
    cout << "Top element after pop: " << stackObj.top() << endl;

    // Print all remaining elements and empty the stack (PLATES)
    cout << "Stack elements: ";
    stackObj.printAndEmpty();

    return 0;
}

