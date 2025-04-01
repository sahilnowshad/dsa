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

// Deletion at the beginning
void deleteAtBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    // If there's only one node
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;
    struct Node *last = *head;
    
    // Find the last node
    while (last->next != *head) {
        last = last->next;
    }

    *head = (*head)->next; // Update head to next node
    last->next = *head; // Last node points to the new head
    free(temp); // Delete the old head
}

// Deletion at the end
void deleteAtEnd(struct Node **head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    // If there's only one node
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;
    struct Node *last = *head;

    // Traverse to the second-to-last node
    while (last->next != *head) {
        temp = last;
        last = last->next;
    }

    temp->next = *head; // Second-to-last node points to head
    free(last); // Delete the last node
}

// Deletion at a given position
void deleteAtPosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    // If the node to be deleted is the head node
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }

    int count = 1;
    // Traverse to the (position-1)th node
    while (temp->next != *head && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    // If position exceeds the list length
    if (temp->next == *head && count < position) {
        printf("Position exceeds the list length.\n");
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);
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

    // Inserting nodes to test the deletion functions
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    printf("Original list:\n");
    printList(head);  // Expected Output: 20 -> 10 -> 30 -> 40 -> 50 -> (head)

    deleteAtBeginning(&head);
    printf("\nAfter deleting at the beginning:\n");
    printList(head);  // Expected Output: 10 -> 30 -> 40 -> 50 -> (head)

    deleteAtEnd(&head);
    printf("\nAfter deleting at the end:\n");
    printList(head);  // Expected Output: 10 -> 30 -> 40 -> (head)

    deleteAtPosition(&head, 2);
    printf("\nAfter deleting at position 2:\n");
    printList(head);  // Expected Output: 10 -> 40 -> (head)

    return 0;
}
