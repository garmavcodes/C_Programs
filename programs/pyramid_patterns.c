#include <stdio.h>

int centered_pyr(int n) {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n-i; j++) {
			printf(" "); // print spaces for centered alignment
		}
		for (int k=1; k<=2*i-1; k++) {
			printf("*"); // print stars
		}
		printf("\n");
	}
	return 0;
}

int left_pry(int n) {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			printf("*"); // print stars in left aligned pyramid
		}
		printf("\n");
	}
	return 0;
}

int rev_left_pry(int n) {
	for(int i=n; i>=1; i--) {
		for(int j=1; j<=i; j++) {
			printf("*"); // print stars in reverse left aligned pyramid
		}
		printf("\n");
	}
	return 0;
}

int rev_center_pyr(int n){
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= n - i; j++) {
            printf(" "); // print spaces for reversed centered alignment
        }

        for(int k = 1; k <= 2 * i - 1; k++) {
            printf("*"); // print stars
        }

        printf("\n");
    }
    return 0;
}

int main() {
	int n, choice;
	printf("enter the number based on ur preference\n1.centered pyramid\n2.left aligned pyramid\n3.revered left alignedpyramid\n4.revered centered pyramid\n");
	scanf("%d",&choice);
	printf("Enter the number of rows for PYRAMID: ");
	scanf("%d", &n);

	switch(choice) {
	case 1:
		centered_pyr(n); // centered pyramid
		break;
	case 2:
		left_pry(n); // left aligned pyramid
		break;
	case 3:
		rev_left_pry(n); // reversed left aligned pyramid
		break;
	case 4:
		rev_center_pyr(n); // reversed centered pyramid
		break;
	default:
		printf("invalid choice");
	}

	return 0;
}