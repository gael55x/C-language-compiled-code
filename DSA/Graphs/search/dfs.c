#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

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


void bfs()