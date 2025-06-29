#include <stdio.h> 

void Merge(int arr[], int l, int mid, int h){
    int i = l , j = mid + 1, k = 0; 
    int arr2[h - l + 1]; 

    while (i <= mid && j <= h){
        if (arr[i] < arr[j]) arr2[k++] = arr[i++]; 
        else arr2[k++] = arr[j++]; 
    }   
    while (i <= mid) {
        arr2[k++] = arr[i++]; 
    }
    while (j <= h) {
        arr2[k++] = arr[j++]; 
    }

    for (i = l, k = 0; i <= h; i++, k++){
        arr[i] = arr2[k]; 
    }
}

void iterativeMerge(int arr[], int n){
    int p, l, h, mid, i; 

    for (p = 2; p <= n; p *= 2){
        for (i = 0; i + p -1 < n; i+=p){
            l = i; 
            h = i + p -1; 
            mid = (l + h) / 2; 
            Merge(arr, l, mid, h); 
        }
    }
    if (p / 2 < n) Merge(arr, 0, p/2 -1, n-1); 
}


int main(){
    int arr[] = {11,13,7,12,16,9,24,5,10,3}, n = 10; 
    int i; 

    iterativeMerge(arr, n); 
    printf("Sorted array: "); 
    for (int i = 0; i < n; i++) printf("%d, ", arr[i]); 
}