#include <stdio.h>
#include <math.h>

// Recursive function to calculate factorial
int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;  // Base case
    } else {
        return (num) * factorial(num - 1);  // Recursive call
    }
}

int main() {
    int factorials = 1, num;

    printf("enter a number to find its factorial:");
    scanf("%d", &num);  // read input number

    if (num == 0) {
        printf("the factorial of zero is 1");
        return 0;
    }

    // Iterative factorial calculation
    for (int i = 1; i <= num; i++) {
        factorials = factorials * i;
    }

    printf("the factorial of %d is:%d\n", num, factorials);

    // Recursive factorial calculation
    int c = factorial(num);
    printf(" answer from recusive factorial is :%d", c);
}