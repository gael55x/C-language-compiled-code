#include <stdio.h> 

void swap(int * a, int * b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}


void Selection(int arr[], int n){
    for (int i = 0; i < n; i++){
        int min = i; 
        for (int j = i; j < n; j++){
            if (arr[min] > arr[j]) min = j; 
        }
        swap(&arr[min], &arr[i]); 
    }
}

int main(){
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = 10; 

    Selection(A, n); 

    printf("Sorted: "); 
    for (int i = 0; i < n; i++){
        printf("%d, ", A[i]); 
    }

    return 0; 
}