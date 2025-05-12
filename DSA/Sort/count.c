#include <stdio.h> 
#include <stdlib.h> 

int findMax(int arr[], int n){
    int min = -9999; 
    for (int i = 0; i < n; i++){
        if (arr[i] > min) min = arr[i]; 
    }
    return min; 
}

void countSort(int arr[], int n){
    int max = findMax(arr, n); 
    int * count = calloc(max + 1, sizeof(int)); 
    for (int i = 0; i < n; i++){
        count[arr[i]]++; 
    }
    int j = 0, i = 0; 
    while (i < max + 1){
        if (count[i] > 0){
            arr[j++] = i; 
            count[i]--; 
        } else i++; 
    }
}

int main(){
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = sizeof(A) / sizeof(A[0]); 

    countSort(A, n); 

    printf("Sorted: "); 
    for (int i = 0; i < n; i++){
        printf("%d, ", A[i]); 
    }

    return 0; 
}