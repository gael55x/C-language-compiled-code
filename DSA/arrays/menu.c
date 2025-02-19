// to compile: gcc menu.c -o menu
// to run: ./menu

#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

void display(struct Array arr) {
    printf("Array: ");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void insert(struct Array *arr, int value) {
    if (arr->length >= arr->size) {
        printf("Array is full.\n");
        return;
    }
    int i = arr->length - 1;
    while (i >= 0 && arr->A[i] > value) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = value;
    arr->length++;
}

void deleteElement(struct Array *arr, int index) {
    if (index >= 0 && index < arr->length) {
        for (int i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
    } else {
        printf("Invalid index.\n");
    }
}

int binarySearch(struct Array arr, int key) {
    int low = 0, high = arr.length - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr.A[mid] == key)
            return mid;
        else if (arr.A[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int sum(struct Array arr) {
    int total = 0;
    for (int i = 0; i < arr.length; i++)
        total += arr.A[i];
    return total;
}

int main() {
    struct Array arr;
    printf("Enter size of array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    int choice, index, value, key;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search (Binary Search)\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&arr, value);
                break;
            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteElement(&arr, index);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &key);
                index = binarySearch(arr, key);
                if (index != -1)
                    printf("Value found at index %d\n", index);
                else
                    printf("Value not found.\n");
                break;
            case 4:
                printf("Sum of elements: %d\n", sum(arr));
                break;
            case 5:
                display(arr);
                break;
            case 6:
                free(arr.A);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
