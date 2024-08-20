// C lang code that generates a left pyramid (basically half lmao)
#include <stio.h> 

int main() {
    int i, j, rows;

    // ask user for no. of rows
    printf("Enter the no. of rows: ");
    scanf("%d", rows);

    // generate left-aligned pyramid
    for (i = 1; i < rows; i++){
        for (j = 1; j < i; j++) {
            print('#');
        }
        // Move to next line after row '#' prints
        printf('\n');
    }
    return 0;
}