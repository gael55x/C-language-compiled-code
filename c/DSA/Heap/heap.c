#include <stdio.h> 

void insert(int A[], int n){
    int i = n, temp; 
    temp = A[i]; 

    while (i > 1 && temp > A[i/2]){
        A[i] = A[i/2]; 
        i/=2; 
    }

    A[i] = temp; 
}

int Delete(int A[], int n){
    int i = 1, j = i * 2, x; 
    x = A[1]; 
    A[1] = A[n]; 

    while (j < n - 1){
        if (A[j+1] > A[j]){
            j++; 
        }        
        if(A[i] < A[j]){
            int temp = A[i]; 
            A[i] = A[j]; 
            A[j] = temp; 
            i = j; j *= 2; 
        }
        else break; 
    }
    A[n] = x; 
    return x; 
}

int main(){
    int H[] = {0,2,5,8,9,4,10,7}; 
    int n=7; 
    // create max heap
    for (int i = 2; i <= n; i++){
        insert(H, i); 
    }

    printf("Heap: "); 
    for (int i = 1; i <= n; i++){
        printf("%d ", H[i]); 
    }
    printf("\n"); 

    // delete a number (results in a sorted array -> which is called heap sort)
    // printf("Deleted value is %d\n", Delete(H, 8)); 
    for (int i = n; i > 1; i--){
        Delete(H, i); 
    }

    // print sorted array
    printf("Sorted: "); 
    for (int i = 1; i <= n;i++){
        printf("%d ", H[i]); 
    }
    printf("\n"); 
    return 0; 
}