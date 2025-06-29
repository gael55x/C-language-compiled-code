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
        new->next = head; 
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
    return new; 
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
        if (head != NULL) head->prev = NULL; 
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


int main(){   
    Node * head = NULL; 
    int choice, val; 

    while (1){
        printf("1. Insert (Sorted Order)\n"); 
        printf("2. Insert (STack based) \n"); 
        printf("3. DELETE \n"); 
        printf("4. Display \n"); 
        printf("5. Exit\n");
        printf("Enter your choices: "); 
        scanf("%d", &choice); 

        switch(choice){
            case 1: 
                printf("Enter the value to be inserted (sorted): "); 
                scanf("%d", &val); 
                head = insert(head, val); 
                break; 
            case 2: 
                printf("Enter the value to be inserted (stacked based): "); 
                scanf("%d", &val); 
                head = insertStack(head, val); 
                break; 
            case 3: 
                printf("Enter the value to be deleted: "); 
                scanf("%d", &val); 
                head = delete(head, val); 
                break; 
            case 4: 
                display(head); 
                break; 
            case 5:
                printf("Exiting program..\n"); 
                return 0;  
            default: 
                printf("Invalid \n"); 
        }

    }
    return 0; 
}