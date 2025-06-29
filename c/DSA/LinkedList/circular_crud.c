#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node{
    int val; 
    struct Node * next; 
} Node; 

Node * create(int x){
    Node * q = (Node*)malloc(sizeof(Node)); 
    q->val = x; 
    q->next = q; 
    return q; 
}

Node * insert(Node * head, int x){
    Node * q = (Node*)malloc(sizeof(Node)); 

    if (q == NULL){
        printf("Memory ALlocation failed\n"); 
    }

    q->val = x; 

    if (head == NULL){
        q->next = q; 
        return q; 
    }

    Node * curr = head; 
    while (curr->next != head){
        curr = curr->next; 
    }

    curr->next = q; 
    q->next = head; 

    return head; 
}

Node* delete(Node * head, int x){
    if (head == NULL) return NULL; 
    Node * curr = head; 
    Node * prev = NULL; 

    // if delete head
    if (head->val == x){
        if (head->next == head){
            free(head); 
            return NULL; 
        }
        Node * tail = head; 
        while (tail->next != head){
            tail = tail->next; 
        }
        tail->next = head->next; 
        Node * n = head->next; 
        free(head); 
        return n; 
    }

    // else search for node to delete
    do {
        prev = curr; 
        curr = curr->next; 
        if (curr->val == x){
            prev->next = curr->next; 
            free(curr); 
            return head; 
        }

    } while (curr != head);
    printf("Value not found\n"); 
    return head;  
}

void display(Node *head){
    if (head == NULL){
        printf("List is empty \n"); 
        return; 
    }
    Node * t = head; 
    do {
        printf("%d ", t->val); 
        t=t->next; 
    }while (t!=head); 
    printf("\n"); 
}

int main(){
    Node* head = NULL;
    head = insert(head, 1); 
    head = insert(head, 2); 
    head = insert(head, 3);
    
    printf("Circular linked list: "); 
    display(head); 

    head = delete(head, 2); 
    printf("\nafter deleting 2: "); 
    display(head); 
    return 0; 
}