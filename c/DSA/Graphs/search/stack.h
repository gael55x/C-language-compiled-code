#ifndef STACK_H
#define STACK_H

#define MAX_NODES 100
int stack[MAX_NODES];
int top = -1; 

void push(int val){
   if (top == MAX_NODES -1) {
    return; 
   }
    stack[++top] = val; 
}

int pop(int stack[]){
    if (top == -1){
        return -1; 
    }
    return stack[top--]; 
}

bool isEmpty(){
    return top == -1; 
}

bool isFull(){
    return top == MAX_NODES -1; 
}


#endif