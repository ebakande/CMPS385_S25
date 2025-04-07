#include <iostream>
using namespace std;

// Size of our mighty hash kingdom
const int BANANA_TABLE_SIZE = 907;

// The sacred fruit basket (our hash table)
int bananaBasket[BANANA_TABLE_SIZE];

// Marker for the ghosts of deleted fruits
const int GHOST_BANANA = -2;

// Fill the basket with air (empty slots = -1)
void summonBananaSpirits() {
    for (int i = 0; i < BANANA_TABLE_SIZE; ++i) {
        bananaBasket[i] = -1;
    }
}

// Our top-secret banana hashing formula
int bananaMagic(int bananaCode) {
    return bananaCode % BANANA_TABLE_SIZE;
}

// Insert a banana into the basket using banana bounce (linear probing)
int tossBananaIn(int bananaCode) {
    int originalSpot = bananaMagic(bananaCode);

    for (int bananaBounce = 0; bananaBounce < BANANA_TABLE_SIZE; ++bananaBounce) {
        int currentSpot = (originalSpot + bananaBounce) % BANANA_TABLE_SIZE;

        // Found an empty spot or ghost banana — time to plant a fresh one
        if (bananaBasket[currentSpot] == -1 || bananaBasket[currentSpot] == GHOST_BANANA) {
            bananaBasket[currentSpot] = bananaCode;
            return currentSpot;  // Success! Banana landed
        }
    }

    // Basket is full of potassium — no room!
    return -1;
}

// Remove a rotten banana using banana bounce (linear probing)
int yeetBananaOut(int bananaCode) {
    int originalSpot = bananaMagic(bananaCode);

    for (int bananaBounce = 0; bananaBounce < BANANA_TABLE_SIZE; ++bananaBounce) {
        int currentSpot = (originalSpot + bananaBounce) % BANANA_TABLE_SIZE;

        // Empty spot — banana never made it here
        if (bananaBasket[currentSpot] == -1) {
            return -1;
        }

        // Found our victim — turn it into a ghost
        if (bananaBasket[currentSpot] == bananaCode) {
            bananaBasket[currentSpot] = GHOST_BANANA;
            return currentSpot;
        }
    }

    // Banana not found after bouncing all over
    return -1;
}

// Display the banana basket
void inspectBananaBasket() {
    cout << "🍌 Banana Basket Contents 🍌" << endl;
    for (int spot = 0; spot < BANANA_TABLE_SIZE; ++spot) {
        if (bananaBasket[spot] != -1 && bananaBasket[spot] != GHOST_BANANA) {
            cout << "[" << spot << "] -> " << bananaBasket[spot] << " 🍌" << endl;
        }
    }
}

// Test the banana madness
int main() {
    summonBananaSpirits();

    // Tossing bananas into the basket
    cout << "Tossed 1001 into spot: " << tossBananaIn(1001) << endl;
    cout << "Tossed 1908 into spot: " << tossBananaIn(1908) << endl;
    cout << "Tossed 2815 into spot: " << tossBananaIn(2815) << endl;

    cout << "\nBasket after banana bombardment:" << endl;
    inspectBananaBasket();

    // Yeet a banana
    cout << "\nYeeting 1908 from the basket: " << yeetBananaOut(1908) << endl;

    cout << "\nBasket after the great banana yeeting:" << endl;
    inspectBananaBasket();

    return 0;
}

