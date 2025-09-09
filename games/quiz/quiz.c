#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

// struct to store each quiz question
typedef struct {
	char question[200];        // question text
	char option[4][100];       // options A, B, C, D
	char correct;              // correct option
} quiz;

int main()
{
	char option;               // user's answer
	int score=0,total=4;       // score and total questions

	// questions array
	quiz game[4]= {
	    {"1.What is the smallest prime number?",{"A) 0","B) 1","C) 2","D) 3"},'c'},
	    {"2. Who invented the telephone?",{"A) Thomas Edison","B) Nikola Tesla","C) Alexander Graham Bell","D) Guglielmo Marconi"},'c'},
	    {"3. Which planet is known for its rings?",{"A) Jupiter","B) Uranus","C) Neptune","D) Saturn"},'d'},
	    {"4. Which programming language is used for web development?",{"A) Python","B) Java","C) HTML","D) C++"},'c'}
	};

	// shuffle questions randomly
	srand(time(NULL));
	for (int i = 0; i < total; i++) {
		int j = rand() % total;
		quiz temp = game[i];
		game[i] = game[j];
		game[j] = temp;
	}

	// loop through all questions
	for(int i=0; i<4; i++) {
		printf("\n%s\n",game[i].question);   // print question
		for(int j=0; j<4; j++) {
			printf("\n%s\n",game[i].option[j]); // print options
		}

		// input validation loop
		do
		{
			printf("enter your answer:");
			scanf(" %c",&option);
			option=tolower(option);  // convert to lowercase
			if(option<'a'||option>'d') {
				printf("INVALID OPTION\n");   // invalid input
			}
		}
		while(option<'a'||option>'d');

		// check if answer is correct
		if(option==game[i].correct) {
			printf("your answer is correct\n");
			score++;    // increment score
		}
		else {
			int correct_ans=game[i].correct-'a';
			printf("your answer is wrong, the correct answer is option %s\n",game[i].option[correct_ans]);
		}

		// system("clear"); //optional if you want to clear the screen after each question
	}

	// display final score
	printf("your final score is %d/%d",score,total);
}
