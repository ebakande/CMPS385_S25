#include <iostream>
#include <vector>

using namespace std;

// MaxHeap class to implement a max-heap data structure
class MaxHeap {
private:
    vector<int> heap;  // Vector to store heap elements

    // Moves a newly inserted element up to maintain the heap property
    void heapifyUp(int index) {
        int parentIndex = (index - 1) / 2; // Find parent node index

        // If the current node is greater than its parent, swap them
        if (index > 0 && heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);  // Recursively check for heap property
        }
    }

    // Moves a root element down to restore heap order after deletion
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;  // Assume current index holds the largest value

        // Check if left child exists and is greater than the current largest
        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        // Check if right child exists and is greater than the current largest
        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        // If the largest element is not the current index, swap and continue
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);  // Recursively check for heap property
        }
    }

public:
    // Inserts a new value into the heap
    void insert(int value) {
        heap.push_back(value);  // Add value at the end
        heapifyUp(heap.size() - 1);  // Restore heap property
    }

    // Removes and returns the root (maximum) element from the heap
    int deleteRoot() {
        if (heap.empty()) {
            cout << "Heap is empty! Nothing to remove." << endl;
            return -1;
        }

        if (heap.size() == 1) {
            int root = heap[0];
            heap.pop_back();
            return root;
        }

        int root = heap[0];  // Store root element
        heap[0] = heap.back();  // Move last element to root
        heap.pop_back();  // Remove last element
        heapifyDown(0);  // Restore heap property
        return root;
    }

    // Displays the heap as an array
    void display() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return;
        }
        cout << "Heap: ";
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

// --- TESTING THE HEAP ---
int main() {
    MaxHeap heap;

    // Sample values to insert into the heap
    int testValues[] = {10, 20, 5, 30, 25, 40, 15};

    // Insert values into the heap and display after each insertion
    for (int val : testValues) {
        cout << "Inserting " << val << "..." << endl;
        heap.insert(val);
        heap.display();
    }

    // Display final heap state
    cout << "\nFinal Heap after insertions:" << endl;
    heap.display();

    // Perform deletion and display updated heap
    cout << "\nRemoving the root element..." << endl;
    int removedElement = heap.deleteRoot();
    cout << "Removed element: " << removedElement << endl;
    
    cout << "Heap after deletion:" << endl;
    heap.display();

    return 0;
}

