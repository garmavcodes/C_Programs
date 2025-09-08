#include <stdio.h>

// Function to check prime number
int prime() {
    int i, val;
    printf("enter the number to check if it is prime:");
    scanf("%d", &val);  // read input number

    int isprime = 1;

    if (val == 1 || val == 0 || val < 0) {
        printf("it is not a prime number\n");
        return 1;
    }

    for (i = 2; i < val; i++) {  // check divisibility
        if (val % i == 0) {
            isprime = 0;
            break;
        }
    }

    if (isprime) {
        printf("the number is prime\n");
    } else {
        printf("the number is not prime\n");
    }

    return 0;
}

// Recursive function to calculate factorial
int factorial(int val) {
    if (val == 0 || val == 1) {
        return 1;
    } else {
        return val * factorial(val - 1);
    }
}

// Function to print fibonacci series
int fibonacci(int val) {
    int a = 0, b = 1;
    printf("the fibonacci series is \n");

    for (int i = 1; i <= val; i++) {
        printf("%d\t", a);
        int temp = a;
        a = a + b;
        b = temp;
    }
}

// Main function
int main() {
    int option;

    printf("enter the option number u want to choose\n");
    printf("1.prime number check\n2.factorial\n3.fibonacci series\n");
    scanf("%d", &option);  // read user option

    switch (option) {
        case 1:
            prime();  // call prime function
            break;

        case 2: {
            int val;
            printf("enter the number to find its factorial:");
            scanf("%d", &val);  // read number for factorial
            int c = factorial(val);
            printf("the factorial of %d is %d", val, c);
            break;
        }

        case 3: {
            int vale;
            printf("enter the number till which term you need fibonacci series:");
            scanf("%d", &vale);  // read number of terms
            fibonacci(vale);
            break;
        }

        default:
            printf("invalid option");
    }

    return 0;
}