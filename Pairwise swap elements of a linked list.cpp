#include <iostream>

// Define a singly linked list node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to swap nodes pairwise in the linked list
Node* pairwiseSwap(Node* head) {
    // If the list is empty or has only one node, no need to swap
    if (!head || !head->next) {
        return head;
    }

    // Initialize pointers
    Node* newHead = head->next; // New head will be the second node
    Node* prev = nullptr;
    Node* current = head;

    while (current && current->next) {
        Node* firstNode = current;
        Node* secondNode = current->next;

        // Swap nodes
        firstNode->next = secondNode->next;
        secondNode->next = firstNode;

        // Link the previous pair to the current pair
        if (prev) {
            prev->next = secondNode;
        }

        // Update prev to the current node (firstNode after swap)
        prev = firstNode;
        // Move to the next pair
        current = firstNode->next;
    }

    return newHead;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to create a new linked list from an array
Node* createList(const int* arr, int size) {
    if (size == 0) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* current = head;
    
    for (int i = 1; i < size; ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    
    return head;
}

// Cleanup function to free allocated memory
void deleteList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    Node* head = createList(arr, 4);

    std::cout << "Original List: ";
    printList(head);

    head = pairwiseSwap(head);

    std::cout << "List after Pairwise Swapping: ";
    printList(head);

    // Cleanup
    deleteList(head);

    return 0;
}
