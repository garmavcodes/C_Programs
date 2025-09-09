#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store an expense
typedef struct {
	char date[20];
	char description[100];
	int amount;
} std;

// Function to add an expense
void add_expense(int * n,std **entry) {
	(*n)++;
	*entry=realloc((*entry),(*n)*sizeof(std));
	printf("Enter date(YYYY-MM-DD):");
	scanf(" %s",(*entry)[(*n)-2].date);
	getchar();
	printf("Enter description:");
	fgets((*entry)[(*n)-2].description,100,stdin);
	(*entry)[(*n)-2].description[strcspn((*entry)[(*n)-2].description, "\n")] = 0;
	printf("Enter amount:");
	scanf("%d",&(*entry)[(*n)-2].amount);
}

// Function to view all expenses
void view_expense(int n,std *entry,FILE*ptr) {
	if(n==1) {
		fprintf(ptr,"no expenses\n\n");
	}
	else {
		fprintf(ptr,"*****expenses*****\n");
		for(int i=0; i<n-1; i++) {
			fprintf(ptr,"%s|%s|%d\n",entry[i].date,entry[i].description,entry[i].amount);
		}
	}
}

// Function to calculate total expenses for a particular day
void daily_total(int n,std *entry) {
	char date[20];
	int amount=0;
	printf("enter date to check:");
	scanf("%s",date);
	for(int i=0; i<n-1; i++) {
		if(strcmp(date,entry[i].date)==0) {
			amount+=entry[i].amount;
		}
	}
	printf("the daily total is %d:\n",amount);
}

int main() {
	int choice;
	int n=1;
	std *entry=malloc(n*sizeof(std));
	FILE *ptr;
	ptr=fopen("myfile.txt","a"); // open file to save expenses
	if(ptr==NULL) {
		printf("error opening file\n");
		return 1;
	}

	do {
		printf("\n1.add expense\n2.view expenses\n3.daily total\n4.exit\n");
		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice) {
		case 1:
			add_expense(&n,&entry);
			view_expense(n,entry,ptr);
			break;
		case 2:
			view_expense(n,entry,stdout);
			break;
		case 3:
			daily_total(n,entry);
			break;
		case 4:
			printf("thank you\n");
			return 0;
		default:
			printf("invalid option\n");
		}
	} while(choice!=4);
	free(entry);
	fclose(ptr);
}
