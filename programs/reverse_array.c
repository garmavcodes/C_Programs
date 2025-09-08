#include <stdio.h>
int main(){
   int s1[10];
   int temp;
   printf("enter the values of array\n");
   for(int i=0;i<10;i++){
       scanf(" %d",&s1[i]); // read array elements
   }
   for(int i=0;i<5;i++){
       temp=s1[i];       // swap elements
       s1[i]=s1[9-i];
       s1[9-i]=temp;
       }
   
   for(int i=0;i<10;i++){
       printf("%d\t",s1[i]); // print reversed array
   }
   
   
}