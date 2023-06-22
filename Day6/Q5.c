#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchByName(struct Student *students, int size, char *name) {
    int found = 0;
    
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found:\n");
            printf("Roll Number: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student not found.\n");
    }
}

int main() {
    int size = 5; // Change this to the desired size of the array
    
    struct Student *students = (struct Student*) malloc(size * sizeof(struct Student));
    
    // Assume the array is already initialized or filled with data
    
    char searchName[20];
    printf("Enter the name to search: ");
    scanf("%s", searchName);
    
    searchByName(students, size, searchName);
    
    free(students);
    
    return 0;
}
