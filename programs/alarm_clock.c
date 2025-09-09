#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    int hour, min, sec;
    printf("enter the time in the format (HH:MM:SS)"); // ask user to enter alarm time
    scanf("%d:%d:%d", &hour, &min, &sec);
    while (1) {  // repeat forever
        time_t now = time(NULL);  // get current time
        struct tm *t = localtime(&now);  // convert to local time
        system("clear");  // clear screen
        printf("\nCURRENT TIME:%.2d:%.2d:%.2d", (*t).tm_hour, (*t).tm_min, (*t).tm_sec);  // show current time
        if ((*t).tm_hour == hour && (*t).tm_min == min && (*t).tm_sec == sec) {  // check if alarm time reached
            printf("\nWAKE UP!!its %.2d:%.2d:%.2d", (*t).tm_hour, (*t).tm_min, (*t).tm_sec);  // alarm message
            break;  // stop loop
        }
        sleep(1);  // wait 1 second
    }
}