#include <stdio.h>

char board[3][3];  // 3x3 board array
char player='x';   // Starting player is 'x'

// Function to initialize spaces with blank
void spaces() {
	for (int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			board[i][j]=' ';
		}
	}
}

// Function to print current board structure
void structure() {
	printf("\n");
	for(int i=0; i<3; i++) {
		printf("%c |%c |%c \n",board[i][0],board[i][1],board[i][2]);
		if(i<2) {
			printf("--|--|--\n");
		}
	}
	printf("\n");
}

// Function to check win condition
int win() {
	for(int i=0; i<3; i++) {
		if((board[i][0]==player && board[i][1]==player && board[i][2]==player ) || (
		            board[0][i]==player && board[1][i]==player && board[2][i]==player)) {
			return 1;
		}
	}

	if((board[0][0]==player && board[1][1]==player && board[2][2]==player)||(
	            board[0][2]==player && board[1][1]==player && board[2][0]==player)) {
		return 1;
	}

	return 0;
}

// Function to check draw (no spaces left)
int draw() {
	for(int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (board[i][j]==' ') {
				return 0;
			}
		}
	}
	return 1;
}

// Function to switch player between 'x' and 'o'
void playerswitch() {
	player=(player=='x')? 'o':'x';
}

int main()
{
	int row,column;

	printf("HELLO ,WELCOME TO TIC TAC TOE GAME!!!\n");

	spaces();  // Initialize board with empty spaces

	while(1) {
		structure();  // Show current board
		printf("%c player:enter your move(row and column 0 1 2):",player);
		scanf("%d %d",&row,&column);
		
		if(row<0|| row >2 || column<0 || column>2){
		    printf("invalid move,try again\n");
		    continue;
		}
		
		if(board[row][column]!=' '){
		    printf("already taken\n");
		    continue;
		}

		board[row][column]=player;  // Place player symbol on board

		if(win()) {
			structure();
			printf("%c player ,you won the game ˚.🎀༘⋆!!",player);
			break;
		}

		if (draw()) {
			structure();
			printf("ahh,its a draw!!");
			break;
		}

		playerswitch();  // Switch turn
	}

	return 0;
}
