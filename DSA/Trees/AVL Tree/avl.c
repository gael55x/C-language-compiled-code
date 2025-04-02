#include <stdio.h> 
#include <stdlib.h> 
#define MAX(a > b) ((a>b) ? a : b) 

typedef struct Node {
    int key;
    struct Node * left;  
    struct Node * right;
    int height;  
} Node; 

int height(Node * n){
    if (n == NULL){
        return 0; 
    }
    return n->height; 
}

Node * newNode(int key){
    Node * node = malloc(sizeof(Node)); 
    node->key =key; 
    node->left = node->right = NULL; 
    node ->height = 1; 
    return node; 
}

// b factor
int getB(Node * n){
    if (!n) return 0; 
    return height(n->left) - height(n->right); 
}

Node * RR(Node *y){
    Node * x = y ->left; 
    Node * t = x->right; 

    x->right = y; 
    y->left = t; 

    y->height = max(height(y->left), height(y->right)) + 1; 
    x->height = max(height(x->left), height(x->right)) + 1; 

    return x; 
}


Node * LR(Node * y){
    Node * y = x->right; 
    Node * t = y->left; 

    y->left = x; 
    x->right = t; 

    x->height = max(height(x->left), height(x->right)) + 1; 
    y->height = max(height(y->left), height(y->right)) + 1;
    
    return y; 
}


