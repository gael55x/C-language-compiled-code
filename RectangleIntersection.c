#include <stdbool.h> 

struct rect_tag {
    float left; 
    float right; 
    float top; 
    float bottom;
};

typedef struct rect_tag rect_t; 


float minimum(float f1, float f2){
    if (f1 < f2) {
        return f1;
    } else {
        return f2;
    } 
}

float maximum(float f1, float f2){
    if (f1 > f2) {
        return f1;
    } else {
        return f2;
    }
}

bool does_intersect(rect_t r1, rect_t r2){
    return !(r1.left >= r2.right || r1.right <= r2.left || r1.bottom >= r2.top || r1.top <= r2.bottom);
}

// to find the intersection between 2 rectangles -> r1 and r2
rect_t intersection(rect_t r1, rect_t r2) {
    // initialize answer variable to edit the rect_t data structure
    rect_t ans; 

    if does_intersect(r1, r2) { 
        // determine the min coordinate of the left side of the intersection -> max of left sides of r1 and r2
        ans.left = maximum(r1.left, r2.left);
        // determine the y-coordinate of the bottom side of the intersection -> max of the bottom sides of r1 and r2
        ans.bottom = maximum(r1.bottom, r2.bottom);
        // x coordinate of the right side of the intersection -> min of the right sides of r1 and r2
        ans.right = minimum(r1.right, r2.right);
        // y coordinate of the top side of the intersection -> min of the top sides of r1 and r2
        ans.top = minimum(r1.top, r2.top);
    }
    // if rectangles overlap
    else {
        // no intersection and return an invalid rectange
        ans.left = ans.bottom = ans.right = ans.top = 0; 
    }

}