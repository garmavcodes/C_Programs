#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *operation;
    operation = argv[1];  // read operation from command line argument

    int a = atoi(argv[2]);  // convert first number argument to int
    int b = atoi(argv[3]);  // convert second number argument to int

    if (argc != 4) {  // check if correct number of arguments given
        printf("enter the operation and values in command line \n");
        printf("the order is <operation> <first value> <second value>\n");
        return 1;
    }

    if (strcmp(operation, "addition") == 0) {
        printf("the sum is %d\n", a + b);  // addition
    }
    else if (strcmp(operation, "subtraction") == 0) {
        printf("the difference is %d\n", a - b);  // subtraction
    }
    else if (strcmp(operation, "multiplication") == 0) {
        printf("the product is %d\n", a * b);  // multiplication
    }
    else if (strcmp(operation, "division") == 0) {
        if (b == 0) {
            printf("the denominator cannot be zero\n");  // handle division by zero
        } else {
            printf("the quotient is %d\n", a / b);  // division
        }
    }
    else {
        printf("invalid operation\n");  // if operation is wrong
    }

    return 0;
}