#include <stdio.h>

void find_smallest_largest_digits(int n, int numbers[]) {
    int smallest = 9;
    int largest = 0;
    int i, j, digit;
    for (i = 0; i < n; i++) {
        int current_num = numbers[i];
        while (current_num != 0) {
            digit = current_num % 10;
            if (digit < smallest) {
                smallest = digit;
            }
            if (digit > largest) {
                largest = digit;
            }
            current_num /= 10;
        }
    }
    if (smallest == largest) {
        printf("Not Valid\n");
    } else {
        printf("Smallest digit: %d\n", smallest);
        printf("Largest digit: %d\n", largest);
    }
}

int main() {
    int n;
    printf("Enter the value
