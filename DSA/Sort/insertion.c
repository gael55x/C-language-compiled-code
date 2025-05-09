#include <stdio.h> 

// Runtime O(n^2)
// No. of passes = (n-1) 
// Space complexity O(n)
void swap(int * a, int * b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}


void Insertion(int arr[], int n){
    for (int i = 0; i < n; i++){
        int j = i - 1;
        int x = arr[i];  
        while (j > -1 && arr[j] > x){
            arr[j + 1] = arr[j]; 
            j--; 
        }
        arr[j+1] = x; 
    }
}

int main(){
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n = 10; 

    Insertion(A, n); 

    printf("Sorted: "); 
    for (int i = 0; i < n; i++){
        printf("%d, ", A[i]); 
    }

    return 0; 
}