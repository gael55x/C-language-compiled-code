#include <stdio.h> 
#include <stdlib.h> 
#define MAX 20

typedef struct {
    int data[MAX];
    int top; 
} Stack; 

void initStack(Stack *s){
    s->top=-1; 
}

int isFull(Stack *s){
    return s->top == MAX -1; 
}

int isEmpty(Stack *s){
    return s->top == -1; 
}

void push(Stack * s, int val){
    if (isFull(s)) {
        printf("Stack overflow\n"); 
        return; 
    }
    s->data[++(s->top)] = val; 
}

int pop(Stack *s){  
    if(isEmpty(s)){
        printf("Stack underflow\n"); 
        return -1; 
    }
    return s->data[(s->top)--]; 
}

int peek(Stack *s){
    if (isEmpty(s)){
        printf("Stack is empty"); 
        return -1; 
    }
    return s->data[s->top]; 
}

void display(Stack *s){
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->top; i>= 0; i--){   
        printf("%d ", s->data[i]); 

    }
    printf("\n"); 
}
int main(){
    Stack s; 
    initStack(&s); 

    int c, val; 
    while (1){
        printf("Stack operations\n"); 
        printf("1. Push\n"); 
        printf("2. Pop\n"); 
        printf("3. Peek\n"); 
        printf("4. Display\n");
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &c); 

        switch(c){
            case 1: 
                printf("Enter value to push: "); 
                scanf("%d", &val); 
                push(&s, val); 
                break; 
            case 2: 
                val= pop(&s); 
                if (val != -1) printf("Popped value: %d\n", val); 
                break; 
            case 3: 
                val = peek(&s); 
                if (val !=-1){
                    printf("Top val: %d\n", val); 
                }
                break; 
            case 4: 
                display(&s); 
                break;
            case 5: 
                return 0; 
            default:
                printf("Invalid"); 

        }
        printf("\n"); 
    }
}
