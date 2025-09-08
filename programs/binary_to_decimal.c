#include <stdio.h>
#include <math.h>

int main()
{
    int decimal=0,i=0,binary,rem;
    double val;
    printf("enter a binary number:");
    scanf("%d",&binary); // read binary number
    if(binary==0){
        printf("decimal :0"); // handle zero
        return 0;
        
    }
    while(binary>0){
        rem=binary%10; // get last digit
        val=rem* pow(2,i); // calculate its decimal value
        decimal=decimal+val; // add to total decimal
        binary=binary/10; // remove last digit
        i++;
  
    }
    printf("the decimal value is:"); // print decimal value
    printf("%d",decimal); // output decimal
    
}