#include <stdio.h>
#include <math.h>

int main()
{
	int  perfect =0,num;
	printf("enter a number:");
    scanf("%d",&num); // read number
    if (num==0){
        printf("it is not a perfect number"); // handle zero
        return 0;
    }
    for(int i=1;i<num;i++){
        if (num%i==0){
            perfect =perfect +i; // sum of divisors
            
        }
    }
    if(num==perfect){
        printf("it is a perfect number"); // number is perfect
    }
    else{
        printf("it is not a perfect number"); // number is not perfect
    }
    
    
}