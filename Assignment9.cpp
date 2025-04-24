#include <iostream>
#include <vector>
using namespace std;

const int MAX_COOKIES = 4;

struct LeafyGreens {
    vector<int> funkyKeys;
    vector<LeafyGreens*> sassyKids;
    bool isLeafy;
    LeafyGreens(bool leafy = true) : isLeafy(leafy), sassyKids(MAX_COOKIES + 1, nullptr) {}
};

struct BMinusTree {
    LeafyGreens* funkyRoot = new LeafyGreens();

    void insertBminusTree(int wildKey) {
        if (funkyRoot->funkyKeys.size() == MAX_COOKIES) {
            auto newMama = new LeafyGreens(false);
            newMama->sassyKids[0] = funkyRoot;
            splitMyChild(newMama, 0);
            funkyRoot = newMama;
        }
        insertNonFull(funkyRoot, wildKey);
    }

private:
    void insertNonFull(LeafyGreens* node, int wildKey) {
        int i = node->funkyKeys.size() - 1;
        if (node->isLeafy) {
            node->funkyKeys.push_back(0);
            while (i >= 0 && wildKey < node->funkyKeys[i])
                node->funkyKeys[i + 1] = node->funkyKeys[i--];
            node->funkyKeys[i + 1] = wildKey;
        } else {
            while (i >= 0 && wildKey < node->funkyKeys[i]) i--;
            i++;
            if (node->sassyKids[i]->funkyKeys.size() == MAX_COOKIES) {
                splitMyChild(node, i);
                if (wildKey > node->funkyKeys[i]) i++;
            }
            insertNonFull(node->sassyKids[i], wildKey);
        }
    }

    void splitMyChild(LeafyGreens* parent, int i) {
        auto child = parent->sassyKids[i];
        auto sibling = new LeafyGreens(child->isLeafy);
        int mid = MAX_COOKIES / 2;

        sibling->funkyKeys.assign(child->funkyKeys.begin() + mid + 1, child->funkyKeys.end());
        child->funkyKeys.resize(mid);
        if (!child->isLeafy)
            for (int j = 0; j <= mid; j++)
                sibling->sassyKids[j] = child->sassyKids[mid + 1 + j];

        parent->funkyKeys.insert(parent->funkyKeys.begin() + i, child->funkyKeys[mid]);
        parent->sassyKids.insert(parent->sassyKids.begin() + i + 1, sibling);
    }

public:
    void printFunkyTree(LeafyGreens* node = nullptr, int depth = 0) {
        if (!node) node = funkyRoot;
        for (int i = 0; i < depth; ++i) cout << "   ";
        for (int k : node->funkyKeys) cout << k << " ";
        cout << endl;
        if (!node->isLeafy)
            for (int i = 0; i <= node->funkyKeys.size(); i++)
                if (node->sassyKids[i]) printFunkyTree(node->sassyKids[i], depth + 1);
    }
};

int main() {
    BMinusTree groovyTree;
    for (int key : {10, 20, 5, 6, 12, 30, 7, 17})
        groovyTree.insertBminusTree(key);
    cout << "Here's your snazzy B-Tree:\n";
    groovyTree.printFunkyTree();
}

