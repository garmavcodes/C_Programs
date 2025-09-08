#include <stdio.h>
int func(int n)
{
    if (n==0){
        return 0; // base case for recursion
    }
    func(n/10); // recursive call for remaining digits
    switch(n%10)
    {
    case 0:
        printf("zero\t");
        break;
    case 1:
        printf("one\t");
        break;
    case 2:
        printf("two\t");
        break;
    case 3:
        printf("three\t");
        break;
    case 4:
        printf("four\t");
        break;
    case 5:
        printf("five\t");
        break;
    case 6:
        printf("six\t");
        break;
    case 7:
        printf("seven\t");
        break;
    case 8:
        printf("eight\t");
        break;
    case 9:
        printf("nine\t");
        break;
    default :
        return 0;
    }
}
int main(){
    int n;
    printf("enter a number:");
    scanf("%d",&n); // read number
    if(n==0){
        printf("zero\t"); // special case for 0
        return 0;
    }
    func(n); // convert number to words
}