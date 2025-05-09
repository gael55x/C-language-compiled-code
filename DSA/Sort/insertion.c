#include <stdio.h> 

void swap(int * a, int * b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}


void Insertion(int arr[], int n){

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