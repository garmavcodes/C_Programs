#include <stdio.h>

int main()
{
    int decimal,i=0,binary[32];
    printf("enter a decimal number:");
    scanf("%d",&decimal); // read decimal number
    if(decimal==0){
        printf("binary :0"); // handle zero
        return 0;
        
    }
    while(decimal>0){
        binary[i]=decimal%2; // store remainder (binary digit)
        decimal=decimal/2; // divide by 2
        
        i++;
  
    }
    printf("the binaray value is:"); // print binary value exactly as in original
    for(int j=i-1;j>=0;j--){
        printf("%d",binary[j]); // print binary digits
    }
    
}