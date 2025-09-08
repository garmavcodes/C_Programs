#include <stdio.h>


int fuc(int a){
    static int b=34; // static variable retains its value between function calls
    printf(" value of b %d\n",b); // print current value of b
    b+=4; // increment b by 4
}

int main(){
    int c=6;
    fuc(c); // in each fuc call the value of b should be 34 but as we made it static 
             // the b value in the next function becomes the previous value of b, it's not reinitialised
    fuc(c);
    fuc(c);
    
    
}