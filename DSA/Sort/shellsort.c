#include <stdio.h> 

void shellSort(int arr[], int n){
    for (int gap = n / 2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i++){
            int t = arr[i], j; 
            for (j = i; j >= gap && arr[j - gap] > t; j -=gap){
                arr[j] = arr[j- gap]; 
            }
            arr[j] =t; 
        }
    }
}
int main(){
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}