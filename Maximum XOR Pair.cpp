#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

void insert(TrieNode* root, int num) {
    TrieNode* curr = root;

    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;

        if (curr->children[bit] == nullptr) {
            curr->children[bit] = new TrieNode();
        }

        curr = curr->children[bit];
    }
}

int findMaxXOR(TrieNode* root, vector<int>& nums) {
    int maxXOR = 0;

    for (int num : nums) {
        TrieNode* curr = root;
        int currXOR = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;

            if (curr->children[oppositeBit] != nullptr) {
                currXOR |= (1 << i);
                curr = curr->children[oppositeBit];
            }
            else {
                curr = curr->children[bit];
            }
        }

        maxXOR = max(maxXOR, currXOR);
    }

    return maxXOR;
}

int main() {
    vector<int> nums = { 25, 10, 2, 8, 5, 3 };

    TrieNode* root = new TrieNode();

    for (int num : nums) {
        insert(root, num);
    }

    int maxXOR = findMaxXOR(root, nums);

    cout << "Maximum XOR: " << maxXOR << endl;

    return 0;
}
