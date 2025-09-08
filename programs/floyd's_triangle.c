#include <stdio.h>

int main() {
    int n, count = 1;
    printf("Enter the number of rows for Floyd's Triangle: ");
    scanf("%d", &n); // read number of rows

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d ", count); // print the number
            count++; // increment for next number
        }
        printf("\n"); // move to next row
    }
    return 0;
}