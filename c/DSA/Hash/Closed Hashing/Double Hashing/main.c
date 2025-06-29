#include <stdio.h>
#include <stdlib.h> 

#define TABLE_SIZE 10
#define EMPTY -1

int hash_table[TABLE_SIZE];
int hash1(int key){
    return key % TABLE_SIZE;
}

// prime number less than table size for secondary hash function
int hash2(int key){
    return 7 - (key % 7);
}

int insert(int key){
    int index = hash1(key);
    int step = hash2(key);
    int i = 0;
    while (hash_table[index] != EMPTY && i < TABLE_SIZE){
        index = (index + step) % TABLE_SIZE;
        i++;
    }
    if (i < TABLE_SIZE){
        hash_table[index] = key;
        printf("Key %d inserted at index %d\n", key, index);
        return index;
    }
    else{
        printf("Hash table is full\n");
        return -1;
    }
}

int search(int key){
    int index = hash1(key);
    int step = hash2(key);
    int i = 0;
    while (hash_table[index] != key && i < TABLE_SIZE){
        index = (index + step) % TABLE_SIZE;
        i++;
    }
    if (i < TABLE_SIZE){
        return index;
    }
    else{
        printf("Key %d not found\n", key);
        return -1;
    }
}

void display(){
    printf("Hash table:\n");
    for (int i = 0; i < TABLE_SIZE; i++){
        printf("%d ", hash_table[i]);
    }
    printf("\n");
}

int main(){
    int choice, key, index;
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = EMPTY;
    }
    while (1){
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                index = insert(key);
                if (index != -1){
                    printf("Key %d inserted at index %d\n", key, index);
                }
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                index = search(key);
                if (index != -1){
                    printf("Key %d found at index %d\n", key, index);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
        }
    }
    return 0;
}