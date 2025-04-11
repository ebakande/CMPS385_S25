#include <iostream>
using namespace std;

// A wacky node for our funky tree
typedef struct SillyNode {
    int banana; // This is the actual value
    SillyNode* leftPumpkin; // Left child
    SillyNode* rightMango; // Right child
} GoofyTree;

// Function to create a new node with a silly value
GoofyTree* makeNewFruit(int fruityNum) {
    GoofyTree* newFruit = new GoofyTree();
    newFruit->banana = fruityNum;
    newFruit->leftPumpkin = nullptr;
    newFruit->rightMango = nullptr;
    return newFruit;
}

// Insert a new fruityNum into the GoofyTree
GoofyTree* InsertBST(int fruityNum, GoofyTree* jungle) {
    if (jungle == nullptr) {
        return makeNewFruit(fruityNum); // Tree was empty, plant a new fruit
    }
    if (fruityNum < jungle->banana) {
        jungle->leftPumpkin = InsertBST(fruityNum, jungle->leftPumpkin);
    } else if (fruityNum > jungle->banana) {
        jungle->rightMango = InsertBST(fruityNum, jungle->rightMango);
    }
    // If the fruityNum is already there, we do nothing (no duplicates)
    return jungle;
}

// Helper function to find the smallest banana in a subtree
GoofyTree* findTinyBanana(GoofyTree* root) {
    while (root->leftPumpkin != nullptr) {
        root = root->leftPumpkin;
    }
    return root;
}

// Delete a fruityNum from the GoofyTree
GoofyTree* DeleteBST(int fruityNum, GoofyTree* jungle) {
    if (jungle == nullptr) {
        return nullptr; // Nothing to delete
    }

    if (fruityNum < jungle->banana) {
        jungle->leftPumpkin = DeleteBST(fruityNum, jungle->leftPumpkin);
    } else if (fruityNum > jungle->banana) {
        jungle->rightMango = DeleteBST(fruityNum, jungle->rightMango);
    } else {
        // Found the node to delete
        if (jungle->leftPumpkin == nullptr) {
            GoofyTree* temp = jungle->rightMango;
            delete jungle;
            return temp;
        } else if (jungle->rightMango == nullptr) {
            GoofyTree* temp = jungle->leftPumpkin;
            delete jungle;
            return temp;
        } else {
            // Node with two children: Get the smallest banana in the right subtree
            GoofyTree* temp = findTinyBanana(jungle->rightMango);
            jungle->banana = temp->banana; // Copy the banana
            jungle->rightMango = DeleteBST(temp->banana, jungle->rightMango); // Delete duplicate
        }
    }
    return jungle;
}

// A helpful function to print the tree in-order (sorted)
void showMeTheFruits(GoofyTree* root) {
    if (root != nullptr) {
        showMeTheFruits(root->leftPumpkin);
        cout << root->banana << " ";
        showMeTheFruits(root->rightMango);
    }
}

// Main function to test our wacky tree
int main() {
    GoofyTree* fruityJungle = nullptr;

    // Insert fruits
    fruityJungle = InsertBST(5, fruityJungle);
    fruityJungle = InsertBST(3, fruityJungle);
    fruityJungle = InsertBST(8, fruityJungle);
    fruityJungle = InsertBST(1, fruityJungle);
    fruityJungle = InsertBST(4, fruityJungle);

    cout << "Fruits in order before deletion: ";
    showMeTheFruits(fruityJungle);
    cout << endl;

    // Delete a fruit
    fruityJungle = DeleteBST(3, fruityJungle);

    cout << "Fruits in order after deleting 3: ";
    showMeTheFruits(fruityJungle);
    cout << endl;

    return 0;
}

