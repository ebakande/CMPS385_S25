#include <iostream>
#include <vector>

// Function to perform insertion sort on a vector of leopard spots (integers)
void sortLeopardSpots(std::vector<int>& leopardSpots) {
    int totalSpots = leopardSpots.size();

    // Traverse from the second element to the end
    for (int i = 1; i < totalSpots; ++i) {
        // Store the current spot value that needs to be inserted in the sorted section
        int currentSpot = leopardSpots[i];
        int spotIndex = i - 1;

        // Shift larger spots one position to the right to make room for currentSpot
        while (spotIndex >= 0 && leopardSpots[spotIndex] > currentSpot) {
            leopardSpots[spotIndex + 1] = leopardSpots[spotIndex];
            --spotIndex;
        }

        // Insert the current spot at the correct sorted position
        leopardSpots[spotIndex + 1] = currentSpot;
    }
}

int main() {
    // Vector representing sizes or patterns of leopard spots (unsorted)
    std::vector<int> leopardSpots = {29, 10, 14, 37, 13};

    std::cout << "Unsorted leopard spots: ";
    for (int spot : leopardSpots) {
        std::cout << spot << " ";
    }
    std::cout << std::endl;

    // Sort the leopard spots using insertion sort
    sortLeopardSpots(leopardSpots);

    std::cout << "Sorted leopard spots: ";
    for (int spot : leopardSpots) {
        std::cout << spot << " ";
    }
    std::cout << std::endl;

    return 0;
}

