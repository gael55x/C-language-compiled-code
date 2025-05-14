#ifndef CHAINS_H
#define CHAINS_H

#include <stdlib.h>

struct Node{
    int data; 
    struct Node *next; 
}; 


void sortedInsert(struct Node **H, int key){
    struct Node *t, *q = NULL, *p = *H; 

    t = malloc(sizeof(struct Node)); 
    t->data = key; 
    t->next = NULL; 

    if (*H == NULL){
        *H = t; 
    } else {
        while (p && p->data < key){
            q = p; 
            p=p->next; 
        }

        if (p == *H){
            t->next = *H; 
            *H = t; 
        } else {
            t->next = q->next; 
            q->next = t; 
        }
    }
}

struct Node *search(struct Node *p, int key){
    while (p != NULL){
        if (key == p->data){
            return p; 
        }
        p = p->next; 
    }
    return NULL; 
}

#endif
