#include <stdio.h>
int main(){
    int n;
    float series=0;
    printf("enter the number till u want the series 1+ 1/2+1/3+....+1/n:\n");
    scanf("%d",&n); // read the number n
    for(int i=1;i<=n;i++){
        series=series +  (1.0/i); // add 1/i to series
    }
    printf("%f", series); // print the series sum
}