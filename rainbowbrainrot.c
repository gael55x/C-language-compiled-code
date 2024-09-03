#include <stdio.h>
#include <string.h>

#define MAX_COLORS 7
#define MAX_LINE_LENGTH 30

typedef struct {
    char* color;
    int position; //  start position of the color in the line
} RainbowColor;

void rainbow_arch() {
    RainbowColor colors[MAX_COLORS] = {
        {"Green", 12},
        {"Yellow", 6},
        {"Brown", 18},
        {"Orange", 2},
        {"Indigo", 22},
        {"Red", 0},
        {"Violet", 24}
    };
    
    // hold the formatted lines of the rainbow arch
    char lines[4][MAX_LINE_LENGTH + 1];
    
    //  lines with spaces and null terminators
    for (int i = 0; i < 4; i++) {
        memset(lines[i], ' ', MAX_LINE_LENGTH);
        lines[i][MAX_LINE_LENGTH] = '\0'; 
    }
    
    for (int i = 0; i < MAX_COLORS; i++) {
        int line_index = i / 2;
        int pos = colors[i].position;
        //color name into the correct position in the line
        strncpy(&lines[line_index][pos], colors[i].color, strlen(colors[i].color));
    }

    // Print the rainbow 
    for (int i = 0; i < 4; i++) {
        printf("%s\n", lines[i]);
    }
}

int main() {
    rainbow_arch();
    return 0;
}
