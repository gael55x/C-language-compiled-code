// prints a star lol 

#include <stdio.h> 

int main(void){
    int i, j, n; 

    printf("No. of rows: ");
    scanf("%d", &n); 

    // non-inverted pyramid
    for (i = 1; i <= n; i++) {
        for (j = i; j < n; j++){
            printf(" ");
        }
        for (j = 1; j <= (2 * i - 1); j++){
            printf("#"); 
        }
        printf("\n");
    }

    // inverted pyramid 
    for (i = n - 1; i >= 1; i--){
        for (j = n; j > i; j--){
            printf(" "); 
        }
        for (j = 1; j <= (2 * i - 1); j++){
            printf("#");
        }
        printf("\n");
    }
    return 0; 
}