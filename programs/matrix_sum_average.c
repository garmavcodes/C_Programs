#include <stdio.h>

int main()
{
	int n, m, array = 0;
	printf("enter the values of n and m for size of  matrix:\n");
	scanf("%d", &n);
	scanf("%d", &m);

	int arr1[n][m];
	printf("enter the values of  matrix\n");
	for(int i = 0; i < n; i++) {
	    for(int j = 0; j < m; j++){
	        scanf("%d", &arr1[i][j]); // read matrix values
	    }
	}

	// calculate sum of all elements
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < m; j++){
	        array = array + arr1[i][j];
	    }
	}

	printf("the sum of array is :%d\n", array); // print sum
	printf("the average of array is :%f", (float) array / (n * m)); // print average
}