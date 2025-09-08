#include <stdio.h>

int main() {
    int even = 0, odd = 0, n;

    printf("enter the size of array");  
    scanf("%d", &n);  // read size of array

    int arr[n];

    printf("enter the values of array \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // read array elements
    }

    for (int j = 0; j < n; j++) {
        if (arr[j] % 2 != 0) {
            odd = odd + arr[j];  // add to odd sum
        } else {
            even = even + arr[j];  // add to even sum
        }
    }

    printf(" the sum of odd numbers is  %d\n", odd);
    printf("the sum of even numbers is %d", even);
}