#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode{
    void * data; 
    struct QueueNode * next; 
}

typedef struct Queue{
    QueueNode * front; 
    QueueNode * rear; 
} Queue; 

Queue * createQ();
int isQueueEmpty(Queue * queue); 
void enqueue(Queue * queue, void *data); 
void * dequeue(Queue* queue); 
void freeQueue(Queue*queue); 

#endif
