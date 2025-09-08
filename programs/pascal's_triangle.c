#include <stdio.h>

int fac(int num){
    if(num==0 || num==1){
        return 1; // factorial of 0 or 1 is 1
    }
    else{
        return (num)*fac(num-1); // recursive factorial
    }
}
int binomial(int a ,int k){
    return fac(a)/(fac(k)*fac(a-k)); // calculate binomial coefficient
}

int main()
{
    int a;
    printf("enter the number of rows required in pascals triangle:");
    scanf("%d",&a); // read number of rows
    for(int i =0;i<a;i++){
        for(int j=0;j<a-i-1;j++){
            printf(" "); // print spaces for alignment
        }    
        
        for(int k=0;k<=i;k++){
            
            printf("%6d",binomial(i,k)); // print binomial coefficient
            
        }printf("\n"); // new line after each row
    }
    
}