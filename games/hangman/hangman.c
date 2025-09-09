#include <stdio.h>
#include <string.h>
char word[]="puzzling";  // the word to guess
int length;
char space[100];  // to store guessed letters

// display current state of guessed word
void structure() {
	for(int i=0; i<length; i++) {
		printf("%c",space[i]);
	}
	printf("\n");
}

// check if the whole word is guessed correctly
int correct() {
	if(strcmp(word,space)==0) {
		printf("wow you guessed it right!! the word is %s🎉🏆",word);
		return 1;
	}
	return 0;
}

int main() {
	length=strlen(word);
	char guess;
	int mistakes=0,max_mistakes=length;  // max mistakes allowed is word length
	printf("🎮 WELCOME TO THE GAME OF HANGMAN!! YAYYY..🎮\n");
	printf("the word has %d letters\n",length);

	for(int i=0; i<length; i++) {
		space[i]='-';  // initialize hidden letters
	}
	space[length]='\0';

	while(1) {
		printf("word:");
		structure();  // show current guessed letters
		printf("remaining changes:%d||mistakes:%d",max_mistakes-mistakes,mistakes);
		printf("\nguess a letter:");
		scanf(" %c",&guess);  // read guessed letter

		int iswrong=1;  // flag to check if guess is wrong
		for(int i=0; i<length; i++) {
			if(guess==word[i]) {
				if(space[i]!=guess) {
					space[i]=guess;  // reveal the correct letter
					iswrong=0;  // mark as correct guess
				}
			}
		}

		if(iswrong) {
			printf("you guessed it wrong.❌\n____________________________\n");
			mistakes++;
		}
		else {
			printf("yes🎯 %c is in the word\n_________________________\n",guess);
		}

		if(mistakes>=max_mistakes) {  // player loses
			printf("opps,you lost the 🎮 !!\nthe word was %s💀",word);
			break;
		}
		if(correct()) {  // player wins
			break;
		}
	}
	return 0;
}
