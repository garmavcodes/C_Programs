#include <stdio.h>

int main() {
    int max1, max2, arr[5];

    printf("enter the values of array of len five \n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);  // read array values
    }

    // Initialize max1 and max2 using first two elements
    if (arr[0] > arr[1]) {
        max1 = arr[0];
        max2 = arr[1];
    } else {
        max1 = arr[1];
        max2 = arr[0];
    }

    // Loop through remaining elements to find max1 and max2
    for (int i = 2; i < 5; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];  // new largest found
        }
        else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];  // update second largest
        }
    }

    printf("largest is %d\n", max1);       // print largest
    printf("second largest is %d", max2); // print second largest
}