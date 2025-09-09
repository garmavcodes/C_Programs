#include <stdio.h>
#include <string.h>

// Define a structure for account
typedef struct {
	char pin[6];    // 5-digit PIN
	char name[20];  // Account holder name
	int balance;    // Current balance
} std;

// Function to check balance
void balance(char * pin,std *account) {
	for(int i=0; i<3; i++) {
		if(strcmp(pin,account[i].pin)==0) {  // Match PIN
			printf("\nCurrent balance: %d\n\n",account[i].balance);
		}
	}
}

// Function to withdraw money
void withdraw(char * pin,std *account) {
	int amount;
	for(int i=0; i<3; i++) {
		if(strcmp(pin,account[i].pin)==0) {  // Match PIN
			printf("\nEnter the amount to withdraw:");
			scanf("%d",&amount);
			if(amount>account[i].balance) {   // Check sufficient balance
				printf("\nWithdraw canceled: amount exceeded\nAvailable Balance:%d\n",account[i].balance);
				break;
			}
			else {
				account[i].balance=account[i].balance-amount;  // Deduct balance
				printf("Withdraw Successful\nBalance:%d\n",account[i].balance);
				break;
			}
		}
	}
}

// Function to deposit money
void deposit(char * pin,std *account ) {
	int amount;
	printf("\nEnter the amount to deposit:");
	scanf("%d",&amount);
	for(int i=0; i<3; i++) {
		if(strcmp(pin,account[i].pin)==0) {  // Match PIN
			account[i].balance=account[i].balance+amount;  // Add to balance
			printf("Deposit Successful\nBalance:%d\n",account[i].balance);
			break;
		}
	}
}

int main()
{
	char pin[6];         // User entered PIN
	int choice, access=1;  
	// Initialize 3 accounts
	std account[3]= {{"12345","harish",50000},{"23456","manoj",1200099},{"34567","banty",2000}};

	printf("WELCOME TO THE ATM !!!\n");
	printf("Enter your 5-digit pin:");
	scanf("%s",pin);

	// Validate PIN length
	if (strlen(pin) != 5) {
        printf("Invalid PIN format. Access Denied.\n");
        return 1;
    }

	// Check access
	for(int i=0; i<3; i++) {
		if(strcmp(pin,account[i].pin)==0) {
			printf("Access Granted!!\n\n");
			printf("Hello %s\n",account[i].name);
			printf("Current balance:%d\n\n",account[i].balance);
			access=0;
			break;
		}
	}
	if(access==1) {
		printf("Access Denied\n");
		return 1;
	}

	// Main menu loop
	do {
		printf("=====ATM MENU=====\n\n");
		printf("1.Check balance\n2.Withdraw money\n3.Deposit money\n4.Exit\n");
		printf("Enter your option:");

		// Validate input
		while(scanf("%d",&choice)!=1){
		    printf("INVALID CHOICE\nPlease enter a number:");
		    while(getchar()!='\n');
		}

		switch(choice) {
		case 1:
			balance(pin,account);  // Show balance
			break;
		case 2:
			withdraw(pin,account); // Withdraw money
			break;
		case 3:
			deposit(pin,account);  // Deposit money
			break;
		case 4:
			printf("Thank You!\n"); // Exit
			break;
		default:
			printf("Invalid option\n");
			break;
		}
	} while(choice!=4);  // Loop until exit
}
