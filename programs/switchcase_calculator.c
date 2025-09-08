#include <stdio.h>

void add(int x , int y){
    printf("the sum is%d:", x+y); // print sum
}

void sub(int x , int y){
    printf("the difference is:%d",x-y); // print difference
}

void multi(int x ,int y){
    printf("the product is:%d",x*y); // print product
}

void divide( int x ,int y){
    if(y==0){
        printf("the denominator cannot be zero , it results undefined"); // handle division by zero
    }
    else{
        printf("the quotient is:%f",(float)x/y); // print quotient
    }
}

int main()
{
	int a,b,choice;
	printf("enter your choice\n1.addition\n2.subtraction\n3.mutiplication\n4.division\n");
	scanf("%d",&choice); // read operation choice
	printf("enter the numbers to perform calculation:");
	scanf("%d",&a); // read first number
	scanf("%d",&b); // read second number
	switch (choice){
	    case 1:
	    	add(a,b); // addition
	    break;
	    case 2:
	    sub(a,b); // subtraction
	    break;
	    case 3:
	    multi(a,b); // multiplication
	    break;
	    case 4:
	    divide(a,b); // division
	    break;
	    default:
	    printf("enter valid choice"); // invalid input
	    break;
	}

	return 0;
}