#include <iostream>
using namespace std;

// Binary search function
int findCarPrice(int carPrices[], int size, int targetPrice) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (carPrices[mid] == targetPrice)
            return mid; // Found the car
        else if (carPrices[mid] < targetPrice)
            left = mid + 1; // Search right half
        else
            right = mid - 1; // Search left half
    }
    return -1; // Not found
}

int main() {
    int carPrices[] = {15, 20, 25, 30, 35, 40}; // Sorted car prices in thousands
    int totalCars = sizeof(carPrices) / sizeof(carPrices[0]);
    int priceToFind = 30; // Price to search for

    int result = findCarPrice(carPrices, totalCars, priceToFind);

    if (result != -1)
        cout << "Car with price $" << priceToFind << "k found at index " << result << ".\n";
    else
        cout << "Car with price $" << priceToFind << "k not found.\n";

    return 0;
}

