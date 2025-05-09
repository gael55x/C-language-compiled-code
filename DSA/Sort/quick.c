#include <stdio.h> 
#include <stdint.h> 

void swap(int * a, int * b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int partition(int arr[], int l, int h){
    int pivot = arr[l]; 
    int i = l, j = h; 
    do {
        do {
            i++; 
        } while (arr[i] <= pivot); 
        do {
            j--; 
        } while (arr[j] > pivot); 
        if (i < j) {
            swap(&arr[i], &arr[j]); 
        }
    } while (i < j); 
    swap(&arr[l], &arr[j]); 
    return j; 
}

void Quick(int arr[], int l, int h){
    if (l < h){
        int j= partition(arr, l, h);
        Quick(arr, l, j);
        Quick(arr, j+1, h);
    }
}

int main(){
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = sizeof(A) / sizeof(A[0]); 

    Quick(A, 0, n); 

    printf("Sorted: "); 
    for (int i = 0; i < n; i++){
        printf("%d, ", A[i]); 
    }

    return 0; 
}