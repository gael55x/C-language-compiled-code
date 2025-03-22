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
