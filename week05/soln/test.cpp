#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) { }
};

// This function recursively updates each node's next pointer
// to point to the node two steps ahead (if it exists).
void recursivePointerJump(Node* head) {
    if (!head) return;              // Base case: reached the end of the list.
    if (head->next) {
        head->next = head->next->next;  // Skip one node ahead.
    }
    recursivePointerJump(head->next);   // Recurse on the updated next pointer.
}

void printList(Node* head) {
    while (head) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original list:" << std::endl;
    printList(head);

    // Apply recursive pointer jumping.
    recursivePointerJump(head);

    std::cout << "After recursive pointer jumping:" << std::endl;
    printList(head);

    // Clean up allocated memory.
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
