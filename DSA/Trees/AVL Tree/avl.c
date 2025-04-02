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

// for insert
Node * insert(Node * node, int key){
    if(!node){
        return newNode(key); 
    }

    if (key < node->key) node->left = insert(node->left, key); 
    else if (key > node->key) node->right = insert(node->right, key); 
    else return node; 

    node ->height = 1 + max(height(node->left), height(node->right)); 

    int b = getB(node); 
    //LL
    if (b > 1 && key < node->left->key) return RR(node); 
    //RR
    if (b < -1 && key > node->right->key) return  LR(node); 

    // TODO: LR & RL

    return node; 

}

// for verification 
void inorder(Node * root){
    if (root){
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    }
}


