#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void leftViewUtil(TreeNode* root, int level, int& maxLevel, vector<int>& result) {
    if (root == nullptr) {
        return;
    }

    if (level > maxLevel) {
        result.push_back(root->val);
        maxLevel = level;
    }

    leftViewUtil(root->left, level + 1, maxLevel, result);
    leftViewUtil(root->right, level + 1, maxLevel, result);
}

vector<int> leftView(TreeNode* root) {
    vector<int> result;
    int maxLevel = -1;

    leftViewUtil(root, 0, maxLevel, result);

    return result;
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Print the left view of the binary tree
    vector<int> leftViewNodes = leftView(root);

    cout << "Left View: ";
    for (int node : leftViewNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
