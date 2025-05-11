#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// Funny-named graph as an adjacency list
const int MAX_FRIENDS = 6; // number of nodes
vector<int> sillyGraph[MAX_FRIENDS];

// BFS function: Breadth First Search with giggles
void doTheBreadthDance(int startingFriend) {
    vector<bool> hasMet(MAX_FRIENDS, false);
    queue<int> giggleLine;

    cout << "🎈 Breadth-First Traversal:\n";

    // Choose a Vertex
    hasMet[startingFriend] = true;
    giggleLine.push(startingFriend);

    // While queue is not empty
    while (!giggleLine.empty()) {
        int currentFriend = giggleLine.front();
        giggleLine.pop();

        cout << currentFriend << " ";

        // Enqueue all unvisited adjacent vertex
        for (int buddy : sillyGraph[currentFriend]) {
            if (!hasMet[buddy]) {
                hasMet[buddy] = true;
                giggleLine.push(buddy);
            }
        }
    }

    cout << "\n";
}

// DFS function: Depth First Search with spooky vibes
void doTheDepthCrawl(int startingFriend) {
    vector<bool> hasMet(MAX_FRIENDS, false);
    stack<int> spookyPile;

    cout << "🎃 Depth-First Traversal:\n";

    // Choose a Vertex
    hasMet[startingFriend] = true;
    spookyPile.push(startingFriend);

    while (!spookyPile.empty()) {
        int currentGhost = spookyPile.top();
        cout << currentGhost << " ";

        bool foundNewBuddy = false;

        // Look for an unvisited friend
        for (int buddy : sillyGraph[currentGhost]) {
            if (!hasMet[buddy]) {
                hasMet[buddy] = true;
                spookyPile.push(buddy);
                foundNewBuddy = true;
                break;
            }
        }

        // If no unvisited buddy found, pop
        if (!foundNewBuddy) {
            spookyPile.pop();
        }
    }

    cout << "\n";
}

int main() {
    // Connect the silly friends in the graph
    sillyGraph[0] = {1, 2};    // 🦄 has friends 🐸 and 🐶
    sillyGraph[1] = {0, 3, 4}; // 🐸 has 🦄, 🐔, and 🐱
    sillyGraph[2] = {0, 5};    // 🐶 has 🦄 and 🦊
    sillyGraph[3] = {1};       // 🐔 has 🐸
    sillyGraph[4] = {1};       // 🐱 has 🐸
    sillyGraph[5] = {2};       // 🦊 has 🐶

    int startingFriend = 0; // 🦄 is friend 0

    doTheBreadthDance(startingFriend);
    doTheDepthCrawl(startingFriend);

    return 0;
}

