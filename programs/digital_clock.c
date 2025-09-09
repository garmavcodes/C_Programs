#include <stdio.h>  
#include <time.h>  
#include <unistd.h>  
  
int main(){  
    while(1){  // repeat forever  
        time_t now = time(NULL);  // get current time  
        struct tm *t = localtime(&now);  // convert time to local time  
        system("clear");  // clear screen  
        printf("DIGITAL CLOCK\n");  // print title  
        printf("%.2d:%.2d:%.2d\n", (*t).tm_hour, (*t).tm_min, (*t).tm_sec);  // print time  
        sleep(1);  // wait 1 second  
    }  
}