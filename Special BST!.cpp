#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    Node* parent;

    Node(int data) {
        key = data;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};
Node* findNextInorderSuccessor(Node* target) {
    // Case 1: If the target has a right subtree
    if (target->right != nullptr) {
        Node* current = target->right;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    // Case 2: If the target does not have a right subtree
    Node* parent = target->parent;
    while (parent != nullptr && target == parent->right) {
        target = parent;
        parent = parent->parent;
    }
    return parent;
}
int main() {
    // Create the tree
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    Node* node9 = new Node(9);
    Node* node10 = new Node(10);
    Node* node11 = new Node(11);
    Node* node12 = new Node(12);
    Node* node13 = new Node(13);
    Node* node14 = new Node(14);
    Node* node15 = new Node(15);
    Node* node16 = new Node(16);
    Node* node17 = new Node(17);
    Node* node18 = new Node(18);
    Node* node19 = new Node(19);

    // Build the tree
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node2->parent = node1;
    node3->left = node6;
    node3->right = node7;
    node3->parent = node1;
    node4->left = node8;
    node4->right = node9;
    node4->parent = node2;
    node5->left = node10;
    node5->right = node11;
    node5->parent = node2;
    node6->left = node12;
    node6->right = node13;
    node6->parent = node3;
    node7->left = node14;
    node7->right = node15;
    node7->parent = node3;
    node8->left = node16;
    node8->right = node17;
    node8->parent = node4;
    node9->left = node18;
    node9->right = node19;
    node9->parent = node4;
    node10->parent = node5;
    node11->parent = node5;
    node12->parent = node6;
    node13->parent = node6;
    node14->parent = node7;
    node15->parent = node7;
    node16->parent = node8;
    node17->parent = node8;
    node18->parent = node9;
    node19->parent = node9;

    Node* targetNode = node12;
    // Find the inorder successor of the target node
    Node* inorderSuccessor = findNextInorderSuccessor(targetNode);

    // Print the result
    if (inorderSuccessor != nullptr) {
        cout << "Inorder successor of " << targetNode->key << " is " << inorderSuccessor->key << endl;
    }
    else 
    {
        cout << "Inorder successor of " << targetNode->key << " does not exist" << endl;
    }
    return 0;
}