#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for storing contact details
typedef struct {
	char name[30];
	char email[50];
	char phone[15];
	char date_birth[50];
	char gender[10];
} std;

// Add a new contact
void add_contact(int *n,std **to_do) {
	(*n)++;
	*to_do=realloc(*to_do,(*n)*sizeof(std));
	printf("\nname:");
	fgets((*to_do)[(*n)-1].name,30,stdin);
	(*to_do)[(*n)-1].name[strcspn((*to_do)[(*n)-1].name,"\n")]=0;
	for(int i=0; (*to_do)[(*n)-1].name[i]; i++) {
		(*to_do)[(*n)-1].name[i]=tolower((*to_do)[(*n)-1].name[i]); // convert to lowercase
	}
	printf("email:");
	scanf("%s",(*to_do)[(*n)-1].email);
	printf("gender:");
	scanf("%s",(*to_do)[(*n)-1].gender);
	for(int i=0; (*to_do)[(*n)-1].gender[i]; i++) {
		(*to_do)[(*n)-1].gender[i]=tolower((*to_do)[(*n)-1].gender[i]); // convert to lowercase
	}
	printf("date of birth(YYYY-MM-DD):");
	scanf("%s",(*to_do)[(*n)-1].date_birth);
	printf("phone number:");
	scanf("%s",(*to_do)[(*n)-1].phone);
	printf("contact ADDED!!\n");
	printf("______________________________________________________");
}

// View all contacts
void view_contact(int n,std *to_do,FILE *ptr) {
	if(n==0) {
		fprintf(ptr,"NO contacts\n\n");
	}
	for(int j=0; j<n; j++) {
		fprintf(ptr,"\n**CONTACT %d**\n",j+1);
		fprintf(ptr,"name:%s\n",(to_do)[j].name);
		fprintf(ptr,"email:%s\n",(to_do)[j].email);
		fprintf(ptr,"gender:%s\n",(to_do)[j].gender);
		fprintf(ptr,"birth date:%s\n",(to_do)[j].date_birth);
		fprintf(ptr,"phone number:%s\n",(to_do)[j].phone);
	}
	fprintf(ptr,"____________________________________________________\n");
}

// Remove a contact
void remove_contact(int *n,std **to_do,int index,FILE *ptr) {
	if(index<0 || index>=(*n)) {
		printf("invalid contact number\n_________________________________________________________\n");
		return;
	}
	for(int i=index; i<(*n)-1; i++) {
		(*to_do)[i]=(*to_do)[i+1]; // shift contacts
	}
	(*n)--;
	(*to_do)=realloc(*to_do,(*n)*sizeof(std));
	printf("CONTACT REMOVED!!");
	printf("\n________________________________________________________________\n");
	view_contact(*n,*to_do,ptr); // show updated contacts
}

// Update a contact
void update_contact(int *n,std **to_do,int update,FILE *ptr) {
	char new[20],change[20];
	if(update<0 || update>=(*n)) {
		printf("invalid contact number\n____________________________________________\n");
		return;
	}
	printf("what do you want to update(name,email,gender,date_birth,phone)?:");
	scanf("%s",change);
	if(strcmp(change,"email")==0) {
		printf("enter the new %s:",change);
		scanf("%s",new);
		strcpy((*to_do)[update].email,new);
		printf("UPDATED!!\n__________________________________________________________\n");
	}
	else if(strcmp(change,"gender")==0) {
		printf("enter the new %s:",change);
		scanf("%s",new);
		for(int i=0; new[i]; i++) {
			new[i]=tolower(new[i]);
		}
		strcpy((*to_do)[update].gender,new);
		printf("UPDATED!!\n__________________________________________________________\n");
	}
	else if(strcmp(change,"date_birth")==0) {
		printf("enter the new %s:",change);
		scanf("%s",new);
		strcpy((*to_do)[update].date_birth,new);
		printf("UPDATED!!\n__________________________________________________________\n");
	}
	else if(strcmp(change,"name")==0) {
		getchar();
		printf("enter the new %s:",change);
		fgets(new,20,stdin);
		new[strcspn(new,"\n")]=0;
		for(int i=0; new[i]; i++) {
			new[i]=tolower(new[i]);
		}
		strcpy((*to_do)[update].name,new);
		printf("UPDATED!!\n__________________________________________________________\n");
	}
	else if(strcmp(change,"phone")==0) {
		printf("enter new phone number:");
		scanf("%s",new);
		strcpy((*to_do)[update].phone,new);
		printf("UPDATED!!\n__________________________________________________________\n");
	}
	else {
		printf("%s doesnt exist\n________________________________________________________________\n",change);
	}
	view_contact(*n,*to_do,ptr); // show updated contact
}

// Search for a contact by name
void search_contact(int n,std *to_do,char *check,FILE *ptr) {
	int found=0;
	for(int j=0; j<n; j++) {
		if( strcmp((to_do)[(j)].name,check)==0) {
			printf("\n**CONTACT %d**\n",j+1);
			printf("name:%s\n",(to_do)[j].name);
			printf("email:%s\n",(to_do)[j].email);
			printf("gender:%s\n",(to_do)[j].gender);
			printf("birth date:%s\n",(to_do)[j].date_birth);
			printf("phone number:%s\n",(to_do)[j].phone);
			found=1;
			printf("\n________________________________________________________________________________\n");
		}
	}
	if(!found) {
		printf("no contact found!!\n_________________________________________________________________________\n");
	}
}

// Main function
int main() {
	std *to_do;
	int index,update,choice,n=0;
	char  check[30];
	to_do=malloc(n*sizeof(std));
	FILE*ptr;

	printf("***contact Manager***\n");
	do {
		printf("\n1.add contact\n2.view contacts\n3.remove contact\n4.update contact\n5.search contact\n6.exit\n");
		printf("Enter choice:");
		scanf("%d",&choice);
		getchar(); // clear input buffer
		switch(choice) {
		case 1:
			add_contact(&n,&to_do); // add new contact
			ptr=fopen("myfile.txt","w"); // save to file
			view_contact(n,to_do,ptr);
			fclose(ptr);
			break;

		case 2:
			view_contact(n,to_do,stdout); // display contacts on screen
			break;

		case 3: {
			printf("enter the contact number to delete:");
			scanf("%d",&index);
			remove_contact(&n,&to_do,index-1,stdout); // delete contact
			ptr=fopen("myfile.txt","w"); // update file
			view_contact(n,to_do,ptr);
			fclose(ptr);
			break;
		}
		case 4:
			printf("enter the contact number you want to update:");
			scanf("%d",&update);
			getchar();
			update_contact(&n,&to_do,update-1,stdout); // update contact
			ptr=fopen("myfile.txt","w"); // save changes
			view_contact(n,to_do,ptr);
			fclose(ptr);
			break;
		case 5:
			printf("enter the name to find the contact:");
			fgets(check,30,stdin);
			check[strcspn(check,"\n")]=0;
			for(int i=0; check[i]; i++) {
				check[i]=tolower(check[i]); // convert search term to lowercase
			}
			search_contact(n,to_do,check,stdout); // search contact
			break;

		case 6:
			printf("thank you\n");
			break;
		default:
			printf("invalid choice\n");
			break;
		}
	} while(choice!=6);
	free(to_do); // free allocated memory
}
