#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

void swapFields(struct Person *p1, struct Person *p2) {
    struct Person temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    struct Person person1 = {"John", 25};
    struct Person person2 = {"Alice", 30};
    
    printf("Before swapping:\n");
    printf("Person 1: %s, %d years old\n", person1.name, person1.age);
    printf("Person 2: %s, %d years old\n", person2.name, person2.age);
    
    swapFields(&person1, &person2);
    
    printf("After swapping:\n");
    printf("Person 1: %s, %d years old\n", person1.name, person1.age);
    printf("Person 2: %s, %d years old\n", person2.name, person2.age);
    
    return 0;
}
