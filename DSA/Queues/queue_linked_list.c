#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node{
    int val; 
    struct Node * next; 
} Node; 

typedef struct Queue{
    Node * front;
    Node * rear;  
} Queue; 


void init(Queue * q){
    q->front = q->rear = NULL; 
}

void enqueue(Queue *q, int x){
    Node * t = (Node*)malloc(sizeof(Node)); 
    if (t == NULL) {
        printf("Queue is full\n");
        return; 
    } 

    t->val = x; 
    t->next = NULL; 
    if (q->front==NULL) q->front = q->rear = t; 
    else {
        q->rear->next = t; 
        q->rear = t; 
    }
}   

int dequeue(Queue * q){
    int x;

    if (q->front == NULL){
        printf("Queue is empty\n"); return -1; 
    }

    Node * t = q->front; 
    x = t->val; 
    q->front = q->front->next; 
    if (q->front == NULL) q->rear = NULL;
    free(t); 
    return x; 
}

void display(Queue *q){
    Node * p = q->front; 
    while (p!= NULL){
        printf("%d ", p->val); 
        p=p->next; 
    }
    printf("\n");
}

int main(){
    Queue q;
    init(&q); 
    
    enqueue(&q, 10); 
    enqueue(&q, 20); 
    enqueue(&q, 30); 
    enqueue(&q, 40); 
    enqueue(&q, 50); 

    display(&q); 

    printf("Dequeued: %d \n", dequeue(&q)); 
    display(&q); 
}
