#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node {
    float val; 
    struct Node * next; 
} Node; 

float findMax(float arr[], int n){
    float max = arr[0]; 
    for (int i = 1; i < n; i++){
        if (arr[i] > max) max = arr[i]; 
    }
    return max; 
}

Node * insertSorted(Node * head, float value){
    Node * newN = malloc(sizeof(Node)); 
    newN->val = value; 
    newN->next = NULL; 

    if (head == NULL || head->val >= value){
        newN->next = head; 
        return newN; 
    }

    Node * curr = head; 
    while (curr->next != NULL && curr->next->val < value){
        curr= curr->next; 
    }
    newN->next = curr->next; 
    curr->next = newN; 
    return head; 
}

void bucketSort(float arr[], int n){
    Node ** buckets = calloc(n, sizeof(Node*));
    int k = 0; 
    for (int i = 0; i < n; i++){
        int idx = (int)n * arr[i]; 
        if (idx >= n) idx = n - 1; 
        buckets[idx] = insertSorted(buckets[idx], arr[i]); 
    } 

    for (int i = 0; i < n; i++){
        Node * curr = buckets[i]; 
        while (curr != NULL){
            arr[k++] = curr->val;
            Node * temp = curr;  
            curr = curr->next; 
            free(temp); 
        }
    }
    free(buckets); 
}

int main(){
    float A[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68, 3.0, 2.8, 12.2, 12.0, 13.0, 1.0};
    int n = 16;  

    // normalize
    float max = findMax(A, n);
    for (int i = 0; i < n; i++) {
        A[i] /= max;
    }

    bucketSort(A, n); 

    // denormalize to get val
    for (int i = 0; i < n; i++) {
        A[i] *= max;
    }
    printf("Sorted: "); 
    for (int i = 0; i < n; i++){
        printf("%.2f, ", A[i]); 
    }

    return 0; 
}