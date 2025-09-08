#include <stdio.h>
#include <math.h>


int main()
{
    int num,rem,original,temp,count=0;
    int value=0;
    printf("enter a  number:");
    scanf("%d",&num); // read number
    
    if(num==0){
        printf("it is an armstrong"); // handle zero
        return 0;
        
    }
    original=num;
    temp=num;
    while(num>0){
        num=num/10; // count digits
        count++;
  
    }
    
    while(original>0){
        rem=original%10; // get last digit
        original=original/10; // remove last digit
        value=value+(int) pow(rem,count); // add digit^count to value
        
    }
    if(value==temp){
        printf("it is armstrong"); // number is armstrong
    }
    else{
        printf("it is not an armstrong"); // number is not armstrong
    }
  
    
    
}