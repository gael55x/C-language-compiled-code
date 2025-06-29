#ifndef STACK_H
#define STACK_H

typedef struct StackNode{
    void * data; 
    struct StackNode * next; 
} StackNode; 

typedef struct Stack{
    StackNode * top; 
} Stack; 

Stack * createS(); 
int isStackEmpty(Stack * stack); 
void push(Stack * stack, void * data); 
void * pop(Stack*stack); 
void freeStack(Stack * stack); 

#endif