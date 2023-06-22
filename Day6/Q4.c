#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int compare(const void *a, const void *b) {
    const struct Student *s1 = (const struct Student *)a;
    const struct Student *s2 = (const struct Student *)b;
    
    if (s1->marks < s2->marks) {
        return 1;
    } else if (s1->marks > s2->marks) {
        return -1;
    }
    
    return 0;
}

void sortArray(struct Student *students, int size) {
    qsort(students, size, sizeof(struct Student), compare);
}

int main() {
    int size = 5; // Change this to the desired size of the array
    
    struct Student *students = (struct Student*) malloc(size * sizeof(struct Student));
    
    // Assume the array is already initialized or filled with data
    
    sortArray(students, size);
    
    printf("Sorted Array of Structures (Descending Order):\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
    
    free(students);
    
    return 0;
}
