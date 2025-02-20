#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node{
    int val; 
    struct Node * next; 
} Node; 

Node * create(int x){
    Node * new = (Node *)malloc(sizeof(Node)); 
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
    Node * t = head; 
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node *delete(Node *head, int index) {

}

void display(Node *head) {

}

int main() {
    int size, value, index;
    Node *head = NULL, *tail = NULL;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid size. Exiting.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &value);
        Node *newNode = createNode(value);
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Initial Linked List:\n");
    display(head);

    printf("Enter index and value to insert: ");
    scanf("%d %d", &index, &value);
    head = insert(head, index, value);
    printf("After insertion:\n");
    display(head);

    printf("Enter index to delete: ");
    scanf("%d", &index);
    head = delete(head, index);
    printf("After deletion:\n");
    display(head);

    return 0;
}