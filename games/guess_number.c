#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int num;
	char choice;
	srand(time(NULL));
	int secret=(rand()%100)+1;  // random number from 1 to 100
	printf("WELCOME TO NUMBER GUESSING GAME\nthe number ranges from 1 to 100\n");
	

	do {
        
		printf("enter the number:");
		scanf("%d",&num);  // user enters their guess
		if(num==secret) {
			printf("wow,you guessed it right 🎀🙌🥳🏆\n");
			secret=(rand()%100)+1;  // generate new random secret number
			printf("the secret number has changed,continue playing\n");
			
			
		}
		else if(num<secret) {
			printf("oops,your number is small\n");

		}
		else if(num>secret) {
			printf("oops,your number is large\n");

		}

		printf("do you want to continue(y/n)");
		scanf(" %c",&choice);  // check if user wants to continue
	} while(choice=='y' || choice=='Y');
	return 0;


}
