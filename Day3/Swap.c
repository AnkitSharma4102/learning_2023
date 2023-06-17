#include <stdio.h>

void swap(void* a, void* b, size_t size) {
    unsigned char* ptr_a = (unsigned char*)a;
    unsigned char* ptr_b = (unsigned char*)b;
    
    for (size_t i = 0; i < size; i++) {
        unsigned char temp = *(ptr_a + i);
        *(ptr_a + i) = *(ptr_b + i);
        *(ptr_b + i) = temp;
    }
}

int main() {
    int x = 5;
    int y = 10;
    
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y, sizeof(int));
    printf("After swap: x = %d, y = %d\n", x, y);
    
    double a = 2.5;
    double b = 3.7;
    
    printf("Before swap: a = %lf, b = %lf\n", a, b);
    swap(&a, &b, sizeof(double));
    printf("After swap: a = %lf, b = %lf\n", a, b);
    
    return 0;
}
