#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    if (root == nullptr) {
        return nullptr;
    }

    while (root != nullptr) {
        if (p < root->val && q < root->val) {
            root = root->left;
        }
        else if (p > root->val && q > root->val) {
            root = root->right;
        }
        else {
            return root;
        }
    }

    return nullptr;
}
int findDistance(TreeNode* root, int target) {
    if (root == nullptr) {
        return 0;
    }

    if (root->val == target) {
        return 0;
    }
    else if (target < root->val) {
        return 1 + findDistance(root->left, target);
    }
    else {
        return 1 + findDistance(root->right, target);
    }
}
int shortestPathLength(TreeNode* root, int p, int q) {
    // Find the Lowest Common Ancestor
    TreeNode* lca = lowestCommonAncestor(root, p, q);

    // Calculate the distance of each node from the LCA
    int distanceP = findDistance(lca, p);
    int distanceQ = findDistance(lca, q);

    // Calculate the shortest path length
    return distanceP + distanceQ;
}
int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(4);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(22);
    root->left->left->left = new TreeNode(1);
    root->right->left->right = new TreeNode(14);

    int p = 1;
    int q = 4;

    // Find the shortest path length
    int shortestPath = shortestPathLength(root, p, q);

    cout << "Shortest Distance between (" << p << "," << q << ") is " << shortestPath << endl;

    return 0;
}
