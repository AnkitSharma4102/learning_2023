#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollNumber;
    char name[50];
    int age;
};

int main() {
    int n, i;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    struct Student *students = (struct Student*) malloc(n * sizeof(struct Student));
    
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i+1);
        printf("Roll Number: ");
        scanf("%d", &(students[i].rollNumber));
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &(students[i].age));
    }
    
    printf("Student Details:\n");
    
    for (i = 0; i < n; i++) {
        printf("Student %d:\n", i+1);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
    }
    
    free(students);
    
    return 0;
}
