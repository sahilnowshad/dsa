#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Points to itself initially
    return newNode;
}

// Insertion at the beginning
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) { // If the list is empty
        *head = newNode;
    } else {
        struct Node *temp = *head;
        // Find the last node to update its next pointer
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode; // Last node points to the new node
        newNode->next = *head; // New node points to the original head
        *head = newNode; // Head is now the new node
    }
}

// Insertion at the end
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) { // If the list is empty
        *head = newNode;
    } else {
        struct Node *temp = *head;
        // Traverse until the last node
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode; // Last node points to new node
        newNode->next = *head; // New node points to head
    }
}

// Insertion at a given position
void insertAtPosition(struct Node **head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    struct Node *newNode = createNode(data);

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node *temp = *head;
    int count = 1;
    
    // Traverse until the (position-1)th node
    while (count < position - 1 && temp->next != *head) {
        temp = temp->next;
        count++;
    }

    if (count == position - 1) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Position exceeds list length!\n");
    }
}

// Function to print the circular linked list
void printList(struct Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node *head = NULL;
    
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtPosition(&head, 25, 2); // Insert 25 at position 2
    
    printList(head);  // Expected Output: 20 -> 25 -> 10 -> 30 -> (head)
    
    return 0;
}
