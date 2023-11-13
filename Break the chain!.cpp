#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* breakCycle(ListNode* head) {
    unordered_set<ListNode*> visited;

    ListNode* curr = head;
    ListNode* prev = nullptr;

    while (curr != nullptr) {
        if (visited.count(curr)) {
            prev->next = nullptr;  // Break the cycle
            break;
        }

        visited.insert(curr);
        prev = curr;
        curr = curr->next;
    }

    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next != nullptr) {
            cout << " -> ";
        }
        curr = curr->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    // Create a linked list with a cycle
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next;  // Create a cycle

    cout << "Original Linked List:" << endl;
    printLinkedList(head);

    head = breakCycle(head);

    cout << "Linked List after breaking the cycle:" << endl;
    printLinkedList(head);

    return 0;
}
