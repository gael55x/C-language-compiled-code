#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node{
    struct Node* prev; 
    int val; 
    struct Node * next; 
} Node; 


Node * create(int x){
    Node * head = (struct Node*)malloc(sizeof(Node)); 
    head->prev = NULL; 
    head->val = x; 
    head->next = NULL; 

    return head; 
}

// sorted based insertion
Node * insert(Node * head, int x){
    Node * new = (struct Node*)malloc(sizeof(Node)); 
    new->prev = NULL; 
    new->val = x; 
    new->next = NULL; 
    // if list empty
    if (head == NULL){
        return new; 
    }

    // if we insert at beginning
    if ( x < head->val){
        new->prev = head; 
        head->prev = new; 
        return new;  
    }

    Node * temp = head; 
    while (temp->next != NULL && temp->next->val <x ){
        temp = temp->next; 
    }
    // if we insert at the end
    if (temp->next == NULL){
        temp->next = new;
        new->prev=temp;
        return head; 
    }

    new->next = temp->next; 
    new->prev = temp; 
    temp->next->prev = new; 
    temp->next = new; 
    return head; 

}

// insertion stack based
Node * insertStack(Node * head, int x){
    Node * new = (Node*)malloc(sizeof(Node)); 
    new->val=x; 
    new->next =head; 
    new->prev = NULL; 

    if (head != NULL){
        head->prev = new; 
    }
    return head; 
}

// insert LIFO style 
Node * delete(Node * head, int x){
    // list emtpy 
    if (head == NULL) return NULL; 

    // traverse nodes
    Node * temp = head; 
    while (temp!=NULL && temp->val != x){
        temp=temp->next; 
    }

    if (temp == NULL){
        printf("Value %d not found in the list.\n", x); 
        return head; 
    }

    // case delete head node in middle
    if (temp == head){
        head = head->next; 
        if (head != NULL) head->prev = NULL: 
        free(temp); 
        return head; 
    } 

    // case delete last node 
    if (temp->next == NULL){
        temp->prev->next = NULL; 
        free(temp); 
        return head; 
    }

    // delete node in the mid
    temp->prev->next = temp->next; 
    temp->next->prev = temp->prev;
    free(temp);  
    return head; 
}   

void display(Node * head){
    if (head == NULL) return; 
    Node * temp = head; 
    while (temp != NULL){
        printf("%d ", temp->val); 
        if (temp->next != NULL) printf("<-> "); 
        temp = temp->next; 

    }
    printf("\n"); 
}


int main{   
    
}