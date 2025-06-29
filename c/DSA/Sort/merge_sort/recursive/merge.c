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

void recursiveMerge(int arr[], int l, int h){
    if (l < h){
        int mid = (l  + h) / 2; 
        recursiveMerge(arr, l, mid); 
        recursiveMerge(arr, mid + 1, h); 
        Merge(arr, l, mid, h); 
    }
}


int main(){
    int arr[] = {11,13,7,12,16,9,24,5,10,3}, n = 10; 
    int i; 

    recursiveMerge(arr, 0, 10); 
    printf("Sorted array: "); 
    for (int i = 0; i < n; i++) printf("%d, ", arr[i]); 
}