#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct hashEntry{
    int key; 
    int value;
    int occupied;    
} hashEntry; 

hashEntry hashTable[SIZE]; 

int hash(int key){
    return key % SIZE; 
}

void insert(int key, int value){
    int index = hash(key); 
    int i = 0; 

    while (hashTable[index].occupied == 1){
        index = (index + i * i) % SIZE; 
        i++; 
    }

    hashTable[index].key = key; 
    hashTable[index].value = value; 
    hashTable[index].occupied = 1; 
    printf("Element inserted at index %d\n", index); 
    return; 
}

int search(int key){
    int index = hash(key); 
    int i = 0; 

    while (hashTable[index].occupied == 1){
        if (hashTable[index].key == key){
            return index; 
        }
        index = (index + i * i) % SIZE; 
        i++; 
    }

    return -1; 
}


int main(){
    int n, x; 

    printf("Enter the number of elements: "); 
    scanf("%d", &n); 

    for (int i = 0; i < n; i++){
        printf("Enter the element: "); 
        scanf("%d", &x); 
        insert(x, x); 
    }

    printf("Enter the element to search: "); 
    scanf("%d", &x); 
    int result = search(x); 
    printf("Element found at index %d\n", result);

    return 0; 
    
}