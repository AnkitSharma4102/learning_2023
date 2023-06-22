#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

void calculateVolumeAndSurfaceArea(struct Box *box) {
    double volume = box->length * box->width * box->height;
    double surfaceArea = 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
    
    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);
}

int main() {
    struct Box myBox;
    struct Box *boxPtr = &myBox;
    
    // Accessing structure members using (*)
    (*boxPtr).length = 5.0;
    (*boxPtr).width = 3.0;
    (*boxPtr).height = 2.0;
    
    calculateVolumeAndSurfaceArea(boxPtr);
    
    // Accessing structure members using (->)
    boxPtr->length = 4.0;
    boxPtr->width = 6.0;
    boxPtr->height = 3.0;
    
    calculateVolumeAndSurfaceArea(boxPtr);
    
    return 0;
}
