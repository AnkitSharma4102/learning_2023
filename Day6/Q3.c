#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayArray(struct Student *students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

int main() {
    int size = 5; // Change this to the desired size of the array
    
    struct Student *students = (struct Student*) malloc(size * sizeof(struct Student));
    
    // Assume the array is already initialized or filled with data
    
    displayArray(students, size);
    
    free(students);
    
    return 0;
}
