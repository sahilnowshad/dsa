#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to delete duplicate elements from the linked list
void deleteDuplicates(struct Node* head) {
    struct Node *current = head, *prev = NULL, *temp;

    while (current != NULL) {
        prev = current;
        temp = current->next;

        // Check for duplicates
        while (temp != NULL && temp->data == current->data) {
            prev->next = temp->next; // Remove duplicate
            free(temp);              // Free memory
            temp = prev->next;       // Move to next node
        }
        current = prev->next; // Move to the next distinct element
    }
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the functionality
int main() {
    struct Node* head = NULL;

    // Creating a linked list with duplicate values
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 30);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);
    insertEnd(&head, 50);

    printf("Original Linked List: \n");
    printList(head);

    deleteDuplicates(head);

    printf("Linked List after removing duplicates: \n");
    printList(head);

    // Free the linked list memory
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}


