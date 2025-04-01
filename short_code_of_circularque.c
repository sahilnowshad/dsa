#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the Circular Queue

typedef struct {
    int items[MAX];
    int front, rear;
} CircularQueue;

void initializeQueue(CircularQueue *q) {
    q->front = q->rear = -1;
}

int isFull(CircularQueue *q) {
    return (q->front == (q->rear + 1) % MAX);
}

int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front = (q->front + 1) % MAX;
    printf("Dequeued %d\n", value);
    return value;
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Circular Queue: ");
    for (int i = q->front; ; i = (i + 1) % MAX) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
    }
    printf("\n");
}

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

    enqueue(&q, 60); // Queue is full
    dequeue(&q);
    enqueue(&q, 60); // Now it should work
    display(&q);

    return 0;
}