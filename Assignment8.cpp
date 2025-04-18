#include <iostream>

using namespace std;

// Tree node with silly names
struct Treenode {
    int banana;               // Value stored in the node
    Treenode* lefty;          // Left child
    Treenode* righty;         // Right child

    // Constructor to easily make new nodes
    Treenode(int yum) {
        banana = yum;
        lefty = nullptr;
        righty = nullptr;
    }
};

// Left rotation – weeeeee!
Treenode* leftrotation(Treenode* wiggly) {
    if (wiggly == nullptr || wiggly->righty == nullptr) {
        return wiggly; // Nothing to rotate
    }

    Treenode* spinMaster = wiggly->righty;
    wiggly->righty = spinMaster->lefty;
    spinMaster->lefty = wiggly;

    return spinMaster;
}

// Right rotation – spin it the other way!
Treenode* rightrotation(Treenode* wiggly) {
    if (wiggly == nullptr || wiggly->lefty == nullptr) {
        return wiggly; // Nothing to rotate
    }

    Treenode* spinMaster = wiggly->lefty;
    wiggly->lefty = spinMaster->righty;
    spinMaster->righty = wiggly;

    return spinMaster;
}

// A super chill way to print the tree (in-order)
void printInOrder(Treenode* root) {
    if (root != nullptr) {
        printInOrder(root->lefty);
        cout << root->banana << " ";
        printInOrder(root->righty);
    }
}

int main() {
    // Build a tiny tree to test
    Treenode* root = new Treenode(10);
    root->righty = new Treenode(20);
    root->righty->righty = new Treenode(30);

    cout << "Before left rotation: ";
    printInOrder(root);
    cout << endl;

    // Perform left rotation
    root = leftrotation(root);

    cout << "After left rotation: ";
    printInOrder(root);
    cout << endl;

    // Let's spin it back the other way!
    root = rightrotation(root);

    cout << "After right rotation: ";
    printInOrder(root);
    cout << endl;

    return 0;
}

