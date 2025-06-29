#include <stdio.h> 

void swap(int * a, int * b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

void Bubble(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]); 
        }
    }
}

void AdaptiveBubble(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int flag = 0; 
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]); 
                flag = 1; 
            }
        }
        if (flag == 0) break; 
    }
}


int main(){
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = 10; 

    Bubble(A, n); 

    printf("Sorted: "); 
    for (int i = 0; i < n; i++){
        printf("%d, ", A[i]); 
    }

    return 0; 
}