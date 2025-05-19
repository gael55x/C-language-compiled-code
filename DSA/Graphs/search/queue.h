#ifndef QUEUE_H
#define QUEUE_H

#define MAX_NODES 100
#include <stdbool.h>
#define QUEUE_SIZE 100

typedef struct {
    int data[QUEUE_SIZE];
    int front;
    int rear;
} queue;

bool isEmpty(queue* q) {
    return q->front > q->rear;
}

int isFull(queue* q) {
    return q->rear == QUEUE_SIZE - 1;
}

void initQueue(queue* q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(queue* q, int value) {
    if (!isFull(q)){
        q->data[++q->rear] = value; 
    }
}
int dequeue(queue* q) {
    if (!isEmpty(q)){
        return q->data[q->front++];
    }
    return -1; 
}


#endif