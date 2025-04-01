#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insertion at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Insertion at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Insertion at a specific position in the list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    int count = 1;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position exceeds the list length\n");
        return;
    }

    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Deletion from the beginning of the list
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    if ((*head)->next == NULL) {
        *head = NULL;
    } else {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
    free(temp);
}

// Deletion from the end of the list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    if ((*head)->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// Deletion at a specific position in the list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    struct Node* temp = *head;
    int count = 1;

    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position exceeds list length\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

// Function to print the list from the beginning
void printListForward(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to print the list from the end
void printListBackward(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Inserting nodes at the beginning and end
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Forward Traversal:\n");
    printListForward(head);  // Expected Output: 20 <-> 10 <-> 30 <-> 40 <-> NULL

    printf("Backward Traversal:\n");
    printListBackward(head);  // Expected Output: 40 <-> 30 <-> 10 <-> 20 <-> NULL

    insertAtPosition(&head, 25, 3);  // Insert 25 at position 3
    printf("\nAfter inserting 25 at position 3:\n");
    printListForward(head);  // Expected Output: 20 <-> 10 <-> 25 <-> 30 <-> 40 <-> NULL

    deleteAtBeginning(&head);
    printf("\nAfter deleting at the beginning:\n");
    printListForward(head);  // Expected Output: 10 <-> 25 <-> 30 <-> 40 <-> NULL

    deleteAtEnd(&head);
    printf("\nAfter deleting at the end:\n");
    printListForward(head);  // Expected Output: 10 <-> 25 <-> 30 <-> NULL

    deleteAtPosition(&head, 2);  // Delete node at position 2
    printf("\nAfter deleting at position 2:\n");
    printListForward(head);  // Expected Output: 10 <-> 30 <-> NULL

    return 0;
}
