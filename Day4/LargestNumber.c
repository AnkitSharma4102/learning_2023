#include <stdio.h>

int find_largest_number(int num) {
    int largest = 0;
    char num_str[5];
    sprintf(num_str, "%d", num);
    int i;
    for (i = 0; i < 4; i++) {
        char current_num_str[4];
        strncpy(current_num_str, num_str, i);
        strncpy(current_num_str + i, num_str + i + 1, 3 - i);
        current_num_str[3] = '\0';
        int current_num = atoi(current_num_str);
        if (current_num > largest) {
            largest = current_num;
        }
    }
    return largest;
}

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largest_number = find_largest_number(num);
    printf("Largest number by deleting a single digit: %d\n", largest_number);

    return 0;
}
