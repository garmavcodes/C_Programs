#include <stdio.h>
int main() 
{
    
    int a,b,gcd,lcm;
    printf("enter 2 numbers:");
    scanf("%d %d",&a,&b); // read two numbers
    int min = (a<b)?a:b; // smaller number for GCD loop
    int max =(a<b)?b:a;  // larger number for LCM loop
    for(int i=1;i<=min;i++){
        if(a%i==0 && b%i==0){
            gcd=i; // update gcd if common divisor found
        }
        
    }
    
    for(int j=max;;j++){
        if(j%a==0 && j%b==0){
            lcm=j; // first common multiple is LCM
            break;
            
        }
    }   
    
    
    
    
    printf("the gcd is %d\n",gcd); // print GCD
    printf("the lcm is %d",lcm); // print LCM
      
}