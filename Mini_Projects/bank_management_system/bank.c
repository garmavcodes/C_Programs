#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// structure for account
typedef struct {
	char pin[6];        // 5-digit PIN
	char name[20];      // account holder name
	char history[1000]; // transaction history
	int balance;        // account balance
} std;

// function to check if PIN contains only digits
int is_digit( char * pin) {
	for(int i=0; i<strlen(pin); i++) {
		if(!isdigit(pin[i])) {
			return 0; // not a digit
		}
	}
	return 1; // all digits
}

// display current balance
void balance(char * pin,std *account,int n) {
	for(int i=0; i<n; i++) {
		if(strcmp(pin,account[i].pin)==0) {
			printf("\nCurrent balance💰 :%d\n\n",account[i].balance);
		}
	}
}

// withdraw money
void withdraw(char * pin,std *account,int n) {
	int amount;
	for(int i=0; i<n; i++) {
		if(strcmp(pin,account[i].pin)==0) {
			printf("\nEnter the amount to withdraw:");
			scanf("%d",&amount);
			if(amount>account[i].balance) {
				printf("\n🚫 Withdraw canceled:amount excceded\nAvailable Balance:%d\n",account[i].balance);
				break;
			}
			else {
				account[i].balance=account[i].balance-amount;
				printf("Withdraw Successfull✅ !!\nBalance:%d\n",account[i].balance);
			}
			char temp[100];
			sprintf(temp,"Withdraw %d on ",amount);
			strcat(account[i].history,temp);
			strcat(account[i].history,__DATE__); // record date
			strcat(account[i].history,"\n");
			break;
		}
	}
}

// deposit money
void deposit(char * pin,std *account,int n ) {
	int amount;
	printf("\nEnter the amount to deposit:");
	scanf("%d",&amount);
	for(int i=0; i<n; i++) {
		if(strcmp(pin,account[i].pin)==0) {
			account[i].balance=account[i].balance+amount;
			printf("Deposit Successfull✅ !!\nBalance:%d\n",account[i].balance);
			char temp[100];
			sprintf(temp,"Deposit %d on ",amount);
			strcat(account[i].history,temp);
			strcat(account[i].history,__DATE__);
			strcat(account[i].history,"\n");
			break;
		}
	}
}

// change PIN
void pin_change(char *pin,std *account,int n) {
	char check[6];
	char newpin[6];
	int found=0;
	for(int i=0; i<n; i++) {
		if(strcmp(pin,account[i].pin)==0) {
			printf("enter your present 5-digit pin:");
			scanf("%s",check);
			if(strcmp(check,account[i].pin)==0) {
				found=1;
				while(1) {
					printf("enter new 5-digit pin:");
					scanf("%s",newpin);
					if(strcmp(newpin,account[i].pin)==0) {
						printf("🚫 It is same pin,Use a new pin\n\n");
						continue;
					}
					else if(strlen(newpin)!=5 ||!is_digit(newpin)) {
						printf("❌ Invalid,Must be exactly 5-digit pin\n\n");
						continue;
					}
					strcpy(account[i].pin,newpin);
					strcpy(pin,newpin);
					printf("PIN Changed Successfully✅ !!\n");
					strcat(account[i].history,"Pin changed on ");
					strcat(account[i].history,__DATE__);
					strcat(account[i].history,"\n");
					break;
				}
			}
		}
	}
	if(!found) {
		printf("🚫 Account not found\n");
	}
}

// display transaction history
void history(char * pin,std * account,FILE * ptr,int n) {
	for(int i=0; i<n; i++) {
		if(strcmp(pin,account[i].pin)==0) {
			printf("\n***Transcation History***\nName:%s\n",account[i].name);
			printf("%s\n",account[i].history);
			printf("💰 Balance:%d\n",account[i].balance);
		}
	}
}

// view all accounts (admin)
void view_account(std * account,int n) {
	for (int i=0; i<n; i++) {
		printf("**Account %d**\n",i+1);
		printf("Name:%s|Pin:%s|Balance:%d\n\n",account[i].name,account[i].pin,account[i].balance);
	}
}

// create new account (admin)
void new_account(int *n,std **account) {
	(*n)++;
	(*account)=realloc((*account),(*n) * sizeof(std));
	printf("\nEnter your name:");
	scanf("%s",(*account)[(*n)-1].name);
	while(1) {
		int duplicate =0;
		printf("enter 5-digit pin:");
		scanf("%s",(*account)[(*n)-1].pin);
		for(int i =0; i<(*n)-1; i++) {
			if(strcmp((*account)[(*n)-1].pin,(*account)[i].pin)==0) {
				printf("🚫 pin exist ,enter a new pin\n");
				duplicate=1;
				break;
			}
		}
		if(strlen((*account)[(*n)-1].pin)!=5 || !is_digit((*account)[(*n)-1].pin)) {
			printf("❌ Invalid,Enter 5-digit number\n");
			continue;
		}
		if(duplicate) {
			continue;
		}
		strcpy((*account)[(*n)-1].history,"");
		break;
	}
	printf("enter initial balance:");
	scanf("%d",&(*account)[(*n)-1].balance);
	printf("\nAccount Created Successfully ✅ !!\n");
}

// delete account (admin)
void del_account(int *n,std **account,char * pin1) {
	for(int i=0; i<(*n); i++) {
		if(strcmp((*account)[i].pin,pin1)==0) {
			for(int j=i; j<(*n)-1; j++) {
				(	*account)[j]=(*account)[j+1];
			}
		}
	}
	(*n)--;
	(*account)=realloc((*account),(*n) * sizeof(std));
	printf("\nAccount Deleted Successfully✅ \n");
  return;
}

// display total bank balance (admin)
void bank_balance(int n,std *account) {
	int money=0;
	for (int i=0; i<n; i++) {
		money+=account[i].balance;
	}
	printf("\n💰 Total Bank Balance:%d\n",money);
}

// main function
int main()
{
	FILE *ptr;
	char pin[6];
	int n=3;
	int	choice,choice1,choice2;
	std *account=malloc(n*sizeof(std));
	// initial accounts
	account[0].balance=50000;
	account[1].balance=1200099;
	account[2].balance=2000;
	strcpy(account[0].name,"harish");
	strcpy(account[1].name,"manoj");
	strcpy(account[2].name,"banty");
	strcpy(account[0].pin,"12345");
	strcpy(account[1].pin,"23456");
	strcpy(account[2].pin,"34567");
	strcpy(account[0].history,"");
	strcpy(account[1].history,"");
	strcpy(account[2].history,"");

	do {
		// main menu
		printf("🏧 WELCOME TO THE ATM🏧  !!!\n");
		printf("\n1.User login\n2.Admin login\n3.exit\n");
		printf("enter your choice:");
		scanf("%d",&choice1);
		if(choice1==1) { // user login
			int access=1;
			printf("enter your 5-digit pin:");
			scanf("%s",pin);
			if (strlen(pin) != 5) {
				printf("❌ Invalid PIN format. Access Denied.\n\n");
				continue;
			}
			for(int i=0; i<n; i++) {
				if(strcmp(pin,account[i].pin)==0) {
					printf("Access Granted✅ !!\n\n");
					printf("hello %s\n",account[i].name);
					printf("Current balance💰 :%d\n\n",account[i].balance);
					access=0;
					break;
				}
			}
			if(access==1) {
				printf("Access Denied❌\n\n");
				continue;
			}
			do { // user menu
				printf("=====ATM MENU=====\n\n");
				printf("1.Check balance\n2.Withdraw money\n3.Deposit money\n4.View transcation history\n5.Change pin\n6.Logout\n");
				printf("Enter your option:");
				while(scanf("%d",&choice)!=1) {
					printf("INVALID CHOICE❌\nPlease enter a number:");
					while(getchar()!='\n');
				}
				switch(choice) {
				case 1:
					balance(pin,account,n);
					continue;
				case 2:
					withdraw(pin,account,n);
					continue;
				case 3:
					deposit(pin,account,n);
					continue;
				case 5:
					pin_change(pin,account,n);
					continue;
				case 4:
					history(pin,account,stdout,n);
					break;
				case 6:
					printf("Thank You!!...loging out✔️ \n.....\n");
					break;
				default:
					printf("Invalid option❌\n");
					break;
				}
			} while(choice != 6);
		}
		else if(choice1 == 2) { // admin login
			do {
				printf(" ===== Admin Menu =====\n");
				printf("1. View all accounts\n2. Create new account\n3. Delete account\n4. Total bank balance\n5. Logout\n");
				printf("enter your choice:");
				scanf("%d", &choice2);
				switch(choice2) {
					case 1:
						view_account(account, n);
						break;
					case 2:
						new_account(&n, &account);
						break;
					case 3: {
						char pin1[6];
						int yes = 0;
						printf("enter account 5-digit pin:");
						scanf("%s", pin1);
						for(int i = 0; i < n; i++) {
							if(strcmp(account[i].pin, pin1) == 0) {
								del_account(&n, &account, pin1);
								yes = 1;
								break;
							}
						}
						if(yes == 0) {
							printf("\n🚫 Account not found\n");
						}
					}
					break;
					case 4:
						bank_balance(n, account);
						break;
					case 5:
						printf("Thank you!!....logging out✔️ \n.......\n");
						break;
					default:
						printf("Invalid choice❌\n");
						break;
				}
			} while(choice2 != 5);
		}
		else if(choice1 == 3) { // exit
			printf("THANK YOU😊 \nbye👋\n");
		}
		else { // invalid main menu choice
			printf("invalid choice❌\n");
		}
	} while(choice1 != 3);

	free(account); // free dynamically allocated memory
	return 0;
}
