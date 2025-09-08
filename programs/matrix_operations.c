#include <stdio.h>

// Function to add two matrices
void add() {
    int n, m;
    printf("enter the value of n and m for size of matrix\n");
    scanf("%d %d", &n, &m);

    int arr1[n][m], arr2[n][m], arr3[n][m];

    printf("enter the values of matrix 1:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr1[i][j]);  // read matrix 1 elements
        }
    }

    printf("enter the values of matrix 2:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr2[i][j]);  // read matrix 2 elements
        }
    }

    printf("THE SUM OF THE MATRIX IS:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", arr3[i][j] = arr1[i][j] + arr2[i][j]);  // sum element-wise
        }
        printf("\n");
    }
}

// Function to subtract two matrices
void sub() {
    int n, m;
    printf("enter the value of n and m for size of matrix\n");
    scanf("%d %d", &n, &m);

    int arr1[n][m], arr2[n][m], arr3[n][m];

    printf("enter the values of matrix 1:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr1[i][j]);  // read matrix 1 elements
        }
    }

    printf("enter the values of matrix 2:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr2[i][j]);  // read matrix 2 elements
        }
    }

    printf("THE DIFFERENCE OF THE MATRIX IS:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", arr3[i][j] = arr1[i][j] - arr2[i][j]);  // subtract element-wise
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void mul() {
    int n1, m1, n2, m2;

    printf("enter the value of n1 and m1 for size of first matrix\n");
    scanf("%d %d", &n1, &m1);

    int arr1[n1][m1];
    printf("enter the values of matrix 1:\n");
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            scanf("%d", &arr1[i][j]);  // read matrix 1 elements
        }
    }

    printf("enter the value of n2 and m2 for the size of second matrix\n");
    scanf("%d %d", &n2, &m2);

    int arr2[n2][m2], arr3[n1][m2];

    printf("enter the values of matrix 2:\n");
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            scanf("%d", &arr2[i][j]);  // read matrix 2 elements
        }
    }

    if (m1 != n2) {  // check matrix multiplication condition
        printf("matrix unmatch\n for n1 cross m1 and n2 cross m2 (m1==n2)");
        return;
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            arr3[i][j] = 0;
            for (int k = 0; k < m1; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];  // multiply and sum
            }
        }
    }

    printf("THE PRODUCT OF MATRIX IS:\n");
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            printf("%d\t", arr3[i][j]);  // print result
        }
        printf("\n");
    }
}

// Function to transpose a matrix
void trans() {
    int n, m;
    printf("enter the value of n and m for size of matrix\n");
    scanf("%d %d", &n, &m);

    int arr1[n][m], arr2[m][n];

    printf("enter the values of matrix :\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr1[i][j]);  // read matrix elements
        }
    }

    printf("THE TRANSPOSE OF MATRIX IS:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", arr2[i][j] = arr1[j][i]);  // transpose
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice;

    printf("enter your choice based on the operation you want to perform on matrixs\n");
    printf("1.addition\n2.subtraction\n3.multiply\n4.transpose\n");
    scanf("%d", &choice);  // read operation choice

    switch (choice) {
        case 1:
            add();
            break;

        case 2:
            sub();
            break;

        case 3:
            mul();
            break;

        case 4:
            trans();
            break;

        default:
            printf("invalid choice");
    }

    return 0;
}