#include <stdio.h> 
#include <stdlib.h> 
#include "stack.h"

Stack * createS(){
    Stack * stack = (Stack *)malloc(sizeof(Stack)); 
    if (stack == NULL) exit(EXIT_FAILURE); 
    stack->top = NULL; 
    return stack; 
}   

int isStackEmpty(Stack * stack){
    return (stack->top == NULL);
}

void push(Stack * stack, void *data){
    StackNode * n = (StackNode *)malloc(sizeof(StackNode)); 
    if (n == NULL) exit(EXIT_FAILURE); 
    n->data = data; 
    n->next = stack->top; 
    stack->top = n; 
}

void * pop(Stack * stack){
    if (isStackEmpty(stack)) return NULL; 
    StackNode * temp = stack->top; 
    void *data = temp->data; 
    stack->top = temp->next; 
    free(temp); 
    return data; 
}

void freeStack(Stack * stack){
    while (!isStackEmpty(stack)){
        pop(stack); 
    }
    free(stack); 
}

