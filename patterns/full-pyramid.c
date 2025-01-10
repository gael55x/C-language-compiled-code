#include <stdio.h> 

int main(void) { 
    int i, j, k, rows; 

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for(i = 0; i < rows; i++, k=0) {
        for (j = 0; j < rows - i; j++) {
            printf("  ");
        }
        while (k != 2 * i - 1) {
            printf("# "); 
            k++;
        }
        printf("\n");
    }
    return 0;
}