#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node{
    int val; 
    struct Node * next; 
} Node; 

Node * create(int x){
    Node * new = (Node*)malloc(sizeof(Node)); 
    new->val = x; 
    new->next = NULL; 
    return new; 
}
Node * insert(Node * head, int idx, int val){
    Node * new = create(val); 
    if (idx == 0){
        new->next = head; 
        return new; 
    }
    Node * temp = head; 

    for (int i = 0; temp != NULL && i < idx -1; i++ ){
        temp = temp->next; 
    }
    if (temp == NULL) { 
        printf("Index out of range\n");
        free(new);
        return head;
    }

    new->next = temp->next; 
    temp->next = new; 
    return head; 
}

Node *delete(Node *head, int idx) {   
    if (head == NULL) {
        printf("List is empty"); 
        return head; 
    }
    Node * temp = head; 
    
    // delete 1st idx
    if (idx == 0){  
        head = head->next;
        free(temp);  
        return head; 
    }

    // delete for any idx; 
    Node * prev = NULL;
    for (int i = 0; temp!=NULL && i < idx; i++){
        prev = temp; 
        temp = temp->next; 
    }

    if (temp == NULL) {
        printf("Index out of range\n"); 
        return head; 
    }
    prev->next = temp->next; 
    free(temp); 
    return head; 
}

void display(Node *head) {
    Node * temp = head; 
    while (temp != NULL){
        printf("%d -> ", temp->val); 
        temp=temp->next; 
    }
    printf("\n"); 
}

int main() {
    int size, val, idx; 
    Node * head = NULL, *tail=NULL; 

    printf("Enter size of Linked list: "); 
    scanf("%d", &size);

    if (size <= 0){
        printf("Invalid size\n");
        return 1;  
    }

    printf("Enter the elements: \n"); 
    for (int i = 0; i < size; i++){
        scanf("%d", &val); 
        Node *new = create(val); 
        if (head == NULL){
            head = tail = new; 
        }
        else {
            tail->next = new; 
            tail = new; 
        }
    }

    printf("initial linked list: \n"); 
    display(head); 

    printf("enter the idx and value to insert: ");
    scanf("%d %d", &idx, &val); 
    
    head = insert(head, idx, val); 
    printf("After insertion: \n"); 
    display(head); 

    printf("Enter the idx to delete: "); 
    scanf("%d", &idx); 

    head = delete(head, idx); 
    printf("After deletion: "); 
    display(head); 

    return 0;

}