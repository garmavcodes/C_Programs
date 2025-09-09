#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	char name[30];          // store player's name
	int i=0,choice;         // loop counter and player's choice
	static int  n1=0;       // player's score
	static int n2=0;        // computer's score
	srand(time(NULL));       // initialize random seed
	char*game[5]={"","ROCK ✊","PAPER ✋","SCISSOR ✌️"};  // choices

	printf("WELCOME TO ROCK , PAPER AND SCISSORS GAME 🎮\nGIVEN INSTRUCTIONS:YOU WILL HAVE 3 ROUNDS\nSELECT THE NUMBER FOR YOUR CHOICE:\n1.ROCK ✊\n2.PAPER ✋\n3.SCISSOR ✌️\n");
	printf("Enter your name :");
	scanf("%s",name);       // input player's name

	while(i<3) {            // 3 rounds
	    int r=rand()%3+1;   // computer's random choice
		printf("%s choice(1-rock,2-paper,3-scissor):",name);
		scanf("%d",&choice);
		printf("Computers choice:%s\n",game[r]);

		if(choice==r){
		    printf("its draw! 🤝\n\n");   // tie
		}
		else if((choice==1 && r==2) || (choice==2 && r==3) || (choice==3 && r==1) ){
		    n2++;
		    printf("computer won this round! 💻\n\n");  // computer wins
		}
		else if((choice==1 && r==3) || (choice==2 && r==1) || (choice==3 && r==2)){
		    n1++;
		    printf("yow won this round! 🎉\n\n");       // player wins
		}
		
		i++;
	}

	// display final result
	printf("\nFINAL RESULT 🏆\n");
	if(n1>n2){
	    printf("CONGRATS,YOU WOW!! 🥳");
	}
	else if(n2>n1){
	    printf("oops, you lost 😢");
	}
	else{
	    printf("its a draw! 🤝");
	}
}
