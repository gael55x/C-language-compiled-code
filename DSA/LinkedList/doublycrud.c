#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node {
    struct Node * prev; 
    int data; 
    struct Node * next; 
} Node; 

Node * create(int A[], int n){
    Node *first, * t, * last; 
    // initialize first node
    first = (struct Node *)malloc(sizeof(struct Node)); 
    first->data = A[0]; 
    first->prev = first->next= NULL; 
    last = first;
    
    // adding new node in linkedlist
    for (int i = 1; i < n; i++){
        t = (struct Node *)malloc(sizeof(struct Node)); 
        // update new node
        t->data = A[i]; 
        t->next = last->next; 
        t->prev = last;
        
        // update last
        last->next = t; 
        last = t; 
    } 

    // return head node
    return first; 
}

// insert 

// display
void display(struct Node *p){
    while(p){
        printf("%d ", p->data); 
        p = p->next;
    }
    printf("\n"); 
}

// find length of linkedlist
int length(struct Node *p){
    int l = 0; 
    while (p){
        l++; 
        p=p->next; 
    }
    return l; 
}

int main(){
    int A[] = {10,20,30,40,50,60}; 
    create(A, 6); 
    printf("\nLength is: %d\n", length(first)); 
    display(first); 
    return 0;
}