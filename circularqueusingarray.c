#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the Circular Queue

typedef struct {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

// Function to initialize the Circular Queue
void initializeQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(CircularQueue *q) {
    return (q->front == (q->rear + 1) % MAX);
}

// Function to check if the queue is empty
int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

// Function to insert an element into the Circular Queue
void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // First element to be added
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

// Function to delete an element from the Circular Queue
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Return -1 to indicate the queue is empty
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1; // Queue is now empty
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued %d\n", value);
    return value;
}

// Function to display the Circular Queue
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Circular Queue: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function to demonstrate the Circular Queue
int main() {
    CircularQueue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    dequeue(&q);
    display(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);

    enqueue(&q, 60); // This should indicate that the queue is full
    dequeue(&q);
    enqueue(&q, 60); // Now it should work
    display(&q);

    return 0;
}