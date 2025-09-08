#include <stdio.h>

int main()
{
	int n, m;
	printf("enter the values of n and m for size of  matrix:\n");
	scanf("%d", &n);
	scanf("%d", &m);

	int arr1[n][m];
	printf("enter the values of  first matrix\n");
	for(int i = 0; i < n; i++) {
	    for(int j = 0; j < m; j++){
	        scanf("%d", &arr1[i][j]); // read first matrix values
	    }
	}

	int arr2[n][m];
	printf("enter the values of second matrix: \n");
	for(int i = 0; i < n; i++) {
	    for(int j = 0; j < m; j++){
	        scanf("%d", &arr2[i][j]); // read second matrix values
	    }
	}

	int arr3[2*n][m]; // merged matrix with 2n rows

	// copy first matrix into merged matrix
	for (int i = 0; i < n; i++){
	    for (int j = 0; j < m; j++){
	        arr3[i][j] = arr1[i][j];
	    }
	}

	// copy second matrix below the first
	for(int i = n; i < 2*n; i++){
	    for (int j = 0; j < m; j++){
	        arr3[i][j] = arr2[i - n][j];
	    }
	}

	printf("the merge of the 2 matrix is :\n");
	for(int i = 0; i < 2*n; i++) {
	    for(int j = 0; j < m; j++){
	        printf("%d ", arr3[i][j]); // print merged matrix
	    }
	    printf("\n");
	}
}