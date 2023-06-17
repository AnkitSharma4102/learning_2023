#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2, Result;
    char operator;

    printf("Enter First Number: ");
    scanf("%lf", &num1);

    printf("Enter Operator: ");
    scanf(" %c", &operator);

    printf("Enter Second Number: ");
    scanf("%lf", &num2);

    switch (operator) {
        case '+':
            Result = num1 + num2;
            break;
        case '-':
            Result = num1 - num2;
            break;
        case '*':
            Result = num1 * num2;
            break;
        case '/':
            Result = num1 / num2;
            break;
        case '%':
            Result = fmod(num1, num2);
            break;
        default:
            printf("Invalid operator!\n");
            return 1; 
    }

    printf("The Result of the Calculation is %lf\n", Result);

    return 0;
}
