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


void dfs(int start){
    if (visited[start]) return;

    visited[start] = true;
    printf("%d ", start); 
    Node * temp = adjList[start];
    while (temp != NULL){
        int neighbor = temp -> vertex; 
        dfs(neighbor);; 
        temp = temp -> next; 
    }
}

int main(){
    for (int i = 0; i < MAX_NODES; i++){
        adjList[i] = NULL; 
        visited[i] = false; 
    }

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(2, 6);

    dfs(0); 
    return 0; 
}