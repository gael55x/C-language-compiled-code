/*Review: Program that genereates a queue*/
#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node{
    int val; 
    struct Node * next; 
} Node; 

typedef struct Queue {
    Node * front; 
    Node * rear; 
} Queue;

Queue * create(){
    Queue * q = malloc(sizeof(Queue)); 
    q->front = NULL; 
    q->rear = NULL; 
    return q; 
}

// add node to rear
void enqueue(Queue * q, int x){
    Node * n = malloc(sizeof(Node)); 
    n->val = x; 
    n->next = NULL; 

    if (q->rear == NULL) {
        q->front =q->rear = n; 
    } else {
        q->rear->next = n; 
        q->rear = n; 
    }
}

int dequeue(Queue * q){
    if (q->front == NULL) return -1; 

    Node * t = q->front; 
    int val = t->val; 
    q-> front = q->front ->next;    

    if (q->front == NULL) q->rear = NULL; 
    free(t); 
    return val; 
}

void display(Queue * q){
    Node * curr = q->front; 
    while (curr != NULL){
        printf("%d ", curr->val); 
        curr = curr->next; 
    }
    printf("\n"); 
}


int main(){

    Queue * q = create(); 
    int c, val; 
    
    while (1){
        printf("Menu: \n"); 
    
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(q, val);
                break;
            case 2:
                val = dequeue(q);
                if (val != -1)
                    printf("Dequeued: %d\n", val);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }


}