#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeArray(struct Student *students, int size, char *input) {
    char *token;
    int i = 0;
    
    token = strtok(input, " ");
    while (token != NULL && i < size) {
        students[i].rollno = atoi(token);
        
        token = strtok(NULL, " ");
        strcpy(students[i].name, token);
        
        token = strtok(NULL, " ");
        students[i].marks = atof(token);
        
        token = strtok(NULL, " ");
        i++;
    }
}

int main() {
    char input[] = "1001 Aron 100.00";
    int size = 1; // Change this to the desired size of the array
    
    struct Student *students = (struct Student*) malloc(size * sizeof(struct Student));
    
    initializeArray(students, size, input);
    
    printf("Initialized Array of Structures:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
    
    free(students);
    
    return 0;
}
