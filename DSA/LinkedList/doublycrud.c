#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node {
    struct Node * prev; 
    int data; 
    struct Node * next; 
} Node; 

// find length of linkedlist
int length(struct Node *p){
    int l = 0; 
    while (p){
        l++; 
        p=p->next; 
    }
    return l; 
}


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
Node * Insert(struct Node * first, int idx, int x){
    struct Node *t, *p=first; 
    if (idx < 0 || idx > length(first))return first; 
    if (idx == 0){
        t = (struct Node *)malloc(sizeof(struct Node)); 
        t->data = x; 
        t->prev = NULL; 
        t->next = first;
        
        // update old head node if it exist
        if (first) first->prev = t; 
        
        return t; 
    } else {
        for (int i = 0; i < idx -1; i++) p = p->next; 
        t = (struct Node *)malloc(sizeof(struct Node)); 
        t->data = x; 
        t->prev = p; 
        t->next = p->next; 
        if (p->next) p->next->prev = t; 
        p->next = t; 

        return first; 
    }
}

// display
void display(struct Node *p){
    while(p){
        printf("%d ", p->data); 
        p = p->next;
    }
    printf("\n"); 
}

int main(){
    int A[] = {10,20,30,40,50,60}; 
    Node * first = create(A, 6);

    printf("Length before insertion: %d\n", length(first));
    display(first);

    first = Insert(first, 2, 25);
    printf("After inserting 25 at index 2:\n");
    display(first);

    first = Insert(first, 0, 5);
    printf("After inserting 5 at index 0:\n");
    display(first);
    return 0;
}