#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define QUEUE_SIZE 100

typedef struct {
    int data[QUEUE_SIZE];
    int front;
    int rear;
} queue;

void initQueue(queue* q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(queue* q, int value) {
    if (q->rear < QUEUE_SIZE - 1) {
        q->rear = -1;
        q->data[++q->rear] = value;
    }
}
int dequeue(queue* q) {
    return q->data[q->front++];
}

bool isEmpty(queue* q) {
    return q->front > q->rear;
}

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node * adjList[MAX_NODES];
bool visited[MAX_NODES];

void addEdge(int src, int dest) {
    Node * newNode = malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

void bfs(int start) {
    queue q;
    initQueue(&q);
    visited[start] = true;
    enqueue(&q, start);

    while (!isEmpty(&q)) {
        int curr = dequeue(&q);
        printf("%d ", curr);
        
        Node * temp = adjList[curr];
        while (temp != NULL) {
        }
    }
}