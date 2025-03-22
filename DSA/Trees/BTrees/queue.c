#include <stdio.h> 
#include <stdlib.h> 
#include "queue.h"

Queue * createQ(){
    Queue * q = (Queue *)malloc(sizeof(Queue)); 
    if (q == NULL) exit(EXIT_FAILURE); 
    q->front = q->rear = NULL; 
    return q; 
}

int isQueueEmpty(Queue * queue){
    return(queue->front == NULL); 
}

void enqueue(Queue * queue, void *data){
    QueueNode * newN = (QueueNode*)malloc(sizeof(QueueNode)); 
    if (newN == NULL) exit(EXIT_FAILURE); 
    newN ->data = data; 
    newN->next= NULL; 
    if (queue->rear == NULL){
        queue->front = queue->rear = newN; 
        return; 
    }
    queue->rear->next = newN; 
    queue->rear = newN; 
}

void * dequeue(Queue * queue){
    if (isQueueEmpty(queue)) return NULL; 
    QueueNode * temp = queue->front;
    void * data = temp->data; 
    queue->front = temp->next; 
    if (queue->front == NULL) queue->rear = NULL; 
    free(temp); 
    return data;  
}

void freeQueue(Queue * queue){
    while (!isQueueEmpty(queue)){
        dequeue(queue); 
    }
    free(queue); 
}