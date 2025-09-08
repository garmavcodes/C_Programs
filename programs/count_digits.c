#include <stdio.h>

int main()
{
	int n,count=0;
	printf("enter the number:");
	scanf("%d",&n); // read the number

	if(n==0){
	    count=1; // zero has 1 digit
	}
	while(n!=0){
	    n=n/10; // remove last digit
	    count++; // increment digit count
	}
	printf("the number of digits are:%d",count); // print total digits
	return 0;
}