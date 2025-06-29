#include <stdio.h>

#define SIZE 10

int hash(int key){
    return key % SIZE; 
}

int probe(int hashTable[], int key){
    int index = hash(key); 
    int i = 0; 

    while (hashTable[(index + i) % SIZE] != 0){
        i++; 
    }

    return (index + i) % SIZE; 
}
void insert(int hashTable[], int key){
    int index = hash(key); 
    
    if (hashTable[index] != 0){
        index = probe(hashTable, key); 
    }

    hashTable[index] = key; 
}

int search(int hashTable[], int key){
    int index = hash(key); 

    while (hashTable[index] != key){
        if (hashTable[index] == 0){
            return -1; 
        }
        index = (index + 1) % SIZE; 
    }

    return index; 
}   

int main(){
    int hashTable[SIZE] = {0}; 
    int n, x; 

    printf("Enter the number of elements: "); 
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++){
        printf("Enter the element: "); 
        scanf("%d", &x); 
        insert(hashTable, x); 
    }

    printf("Hash Table: "); 
    for (int i = 0; i < SIZE; i++){
        printf("%d ", hashTable[i]); 
    }

    printf("\nEnter the element to search: "); 
    scanf("%d", &x); 
    int result = search(hashTable, x); 
    printf("Element found at index %d\n", result);


    return 0; 
}