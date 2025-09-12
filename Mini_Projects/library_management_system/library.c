#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//structure for book
typedef struct {
	int id;             //book id
	char name[30];      //book issued person name
	char title[50];     // book title
	char author[50];    //book author
	char available[20]; // book available/issued
} std;

//function to check if the book id exist
int if_id(int n,int option, std * book) {
	for (int i=0; i<n; i++) {
		if(book[i].id==option) {
			printf("Book Found📖 !!\n\n"); 
			return i; // id found
		}
	}
	printf("❌ Book Not Found\n");
	return -1; //id not found
}

//function to add a new book
void add_book(int *n,std **book) {
	(*n)++;
	int id;
	(*book)=realloc((*book),(*n) * sizeof(std)); //allocating new memory
	while(1) {
		int exist_id=0;
		printf("Enter Book ID:");
		scanf("%d",&id);
		getchar();
		for(int i=0; i<(*n)-1; i++) {
			if((*book)[i].id==id) {
				printf("Book Id already exist\n");
				exist_id=1; //id exist
				break;
			}
		}
		if(!exist_id) { // if id does not exist
			(*book)[(*n)-1].id=id;
			break;
		}
	}
	printf("Enter Title:");
	fgets((*book)[(*n)-1].title,50,stdin);
	(*book)[(*n)-1].title[strcspn((*book)[(*n)-1].title,"\n")]=0;
	printf("Enter Author :");
	fgets((*book)[(*n)-1].author,50,stdin);
	(*book)[(*n)-1].author[strcspn((*book)[(*n)-1].author,"\n")]=0;
	strcpy((*book)[(*n)-1].available,"Available");
	strcpy((*book)[(*n)-1].name,""); //since book is added no issued name
	printf("\nBOOK ADDED SUCCESSFULLY!!✔️");
}

//function to edit book
void edit_book(int j,int *n,std **book) {
	int id;
	while(1) {
		int exist_id=0;
		printf("Enter New Book ID:");
		scanf("%d",&id);
		getchar();
		for(int i=0; i<(*n); i++) {
			if(i!=j && (*book)[i].id==id) {
				printf("Book Id already exist\n");
				exist_id=1; // id exist
				break;
			}
		}
		if(!exist_id) { //if id does not exist
			(*book)[j].id=id;
			break;
		}
	}
	printf("Enter New Title:");
	fgets((*book)[j].title,50,stdin);
	(*book)[j].title[strcspn((*book)[j].title,"\n")]=0;
	printf("Enter New Author :");
	fgets((*book)[j].author,50,stdin);
	(*book)[j].author[strcspn((*book)[j].author,"\n")]=0;
	printf("\nBOOK EDITED SUCCESSFULLY!!✔️");
}

// function to delete book
void delete_book(int* n,int j,std **book) {
	for(int i=j; i<(*n)-1; i++) {
		(*book)[i]=(*book)[i+1];
	}
	(*n)--; 
	if((*n)==0) { // checks if all books are deleted
		free(*book);
		*book=NULL; 
	}
	else {
		(*book)=realloc((*book),(*n) * sizeof(std)); //removes extra memory
		if((*book)==NULL) {
			printf("Memory Reallocation failed\n");
			exit(1); //exist the program due to error
		}
	}
	printf("BOOK DELETED SUCCESSFULLY!!✔️\n");
}

//function to display all books
void display_book(int n,std * book) {
	printf("******BOOKS******\n\n");
	for(int i=0; i<n; i++) {
		printf("Book ID:%d\n",book[i].id);
		printf("Title:%s\n",book[i].title);
		printf("Author:%s\n",book[i].author);
		printf("Status:%s\n\n",book[i].available);
	}
}

//function to search a book by id
void search_book(int n,std *book,int i) {
	printf("Book ID:%d\n",book[i].id);
	printf("Title:%s\n",book[i].title);
	printf("Author:%s\n",book[i].author);
	printf("Status:%s\n\n",book[i].available);
}

//function to check the issued books
void issued_book(int n,std *book) {
	int found=0;
	printf("****ISSUED BOOKS****\n\n");
	for(int i=0; i<n; i++) {
		if(strcmp(book[i].available,"issued")==0) {
			printf("Book ID:%d\n",book[i].id);
			printf("Title:%s\n",book[i].title);
			printf("Author:%s\n",book[i].author);
			printf("Issued to:%s\n",book[i].name);
			printf("Status:%s\n\n",book[i].available);
			found=1; //book issued
		}
	}
	if(!found) { //no book issued
		printf("NO Books Issued✔️\n");
	}
}

//function to check if book available
void available_book(int n,std *book) {
	int found=0;
	printf("****AVAILABLE BOOKS****\n\n");
	for(int i=0; i<n; i++) {
		if(strcmp(book[i].available,"Available")==0) {
			printf("Book ID:%d\n",book[i].id);
			printf("Title:%s\n",book[i].title);
			printf("Author:%s\n",book[i].author);
			printf("Status:%s\n\n",book[i].available);
			found=1; //book available
		}
	}
	if(!found) { //book not available
		printf("NO Books Available❌\n");
	}
}

//function to issue a book
void issue_book(int i,int n,std *book) {
	char newuser[30]; 
	if(strcmp(book[i].available,"Available")==0) { //book Available or not
		getchar();
		printf("enter your name:");
		fgets(newuser,30,stdin);
		newuser[strcspn(newuser,"\n")]=0;
		strcpy(book[i].name,newuser);
		printf("BOOK ISSUED SUCCESSFULLY!!✔️\n");
		strcpy(book[i].available,"issued");
	} else {  //book unavailable
		printf("Book Not Available❌\n");
	}
}

//function to return a book
void return_book(int i,int n,std *book) {
	if(strcmp(book[i].available,"issued")==0) { //book issued or not
		printf("BOOK RETURNED SUCCESSFULLY!!✔️\n");
		strcpy(book[i].available,"Available");
		strcpy(book[i].name,"");
	} else { //book not issued
		printf("Book Not Issued❌\n");
	}
}

//function to search book by title or author
void search_book1(int n,std *book,char *name) {
	int found=0;
	char lower_title[50],lower_author[50];
	for(int i=0; i<n; i++) {
		strcpy(lower_author,book[i].author); 
		strcpy(lower_title,book[i].title);
		for(int j=0; lower_title[j]!='\0'; j++) {
			lower_title[j]=tolower(lower_title[j]);
		}
		for(int j=0; lower_author[j]!='\0'; j++) {
			lower_author[j]=tolower(lower_author[j]);
		}
		if((strstr(lower_author,name)!=NULL) || (strstr(lower_title,name))!=NULL ) { //check if the substring(author/title ) is availabble in the library
			printf("Book ID:%d\n",book[i].id);
			printf("Title:%s\n",book[i].title);
			printf("Author:%s\n",book[i].author);
			printf("Status:%s\n\n",book[i].available);
			found=1; //book found
		}
	}
	if(!found) {
		printf("book not found❌\n");
	}
}

int main()
{
	int n=2,by,choice1,choice2,choice3,i,option1;
	char pass1[10];
	std * book;
	book=malloc(n*sizeof(std)); //allocating Memory
	book[0].id=101;
	strcpy(book[0].name,"");
	strcpy(book[0].title,"C Programming");
	strcpy(book[0].author,"Dennis Ritchie");
	strcpy(book[0].available,"Available");
	book[1].id=102;
	strcpy(book[1].title,"Data Structures");
	strcpy(book[1].author,"Mark Allen");
	strcpy(book[1].available,"issued");
	strcpy(book[1].name,"kamya");
	do {
		printf("\n=====📚 Library Management System📚 ====\n");
		printf("1.Admin login\n2.User login\n3.Exit\n"); //main menu
		printf("enter your choice:");
		scanf("%d",&choice1);
		if(choice1==1) { //admin menu
			printf("\nEnter Admin Password:"); //admin pass
			scanf("%s",pass1);
			if(strcmp(pass1,"admin123")!=0) {
				printf("❌ Wrong Password,Login Denied\n");
				continue;
			}
			printf("Login Successful✅\n");
			do {
				printf("\n===Admin Menu===\n");
				printf("1.Add Book\n2.Edit Book\n3.Delete Book\n4.Display All Books\n5.Search Book\n6.View Issued Books\n7.Logout\n");
				printf("Enter your choice:");
				scanf("%d",&choice2);
				switch(choice2) {
				case 1:
					add_book(&n,&book);
					break;
				case 2: {
					printf("Enter The Book ID:");
					scanf("%d",&option1);
					i=if_id(n,option1,book);
					if(i!=-1) {
						edit_book(i,&n,&book);
					}
					break;
				}
				case 3: {
					printf("Enter Book ID:");
					scanf("%d",&option1);
					i=if_id(n,option1,book);
					if(i!=-1) {
						delete_book(&n,i,&book);
					}
					break;
				}
				case 4:
					display_book(n,book);
					break;
				case 5: {
					printf("search by\n1.book id\n2.book name\n3.author name\n");
					scanf("%d",&by);
					if(by==1) {
						printf("enter ID:");
						scanf("%d",&option1);
						i=if_id(n,option1,book);
						if(i!=-1) {
							search_book(n,book,i);
						}
					}
					else if(by==2 ||by==3) {
						getchar();
						printf("enter Name:");
						char name1[30];
						fgets(name1,30,stdin);
						name1[strcspn(name1,"\n")]=0;
						for(int j=0; j<strlen(name1); j++) {
							name1[j]=tolower(name1[j]);
						}
						search_book1(n,book,name1);
					}
					break;
				}
				case 6:
					issued_book(n,book);
					break;
				case 7:
					printf("Thank You!!🥰\n");
					break;
				default:
					printf("Invalid choice❌\n");//invalid admin mmenu
					break;
				}
			} while(choice2!=7);
		}
		else if(choice1==2) { 
			do { //user menu
				printf("\n===User Menu===\n");
				printf("1.View Available Books\n2.Search Book\n3.Issue Book\n4.Return book\n5.Logout\n");
				printf("Enter your choice:");
				scanf("%d",&choice3);
				switch(choice3) {
				case 1:
					available_book(n,book);
					break;
				case 2: {
					printf("search by\n1.book id\n2.book name\n3.author name\n:");
					scanf("%d",&by);
					if(by==1) {
						printf("enter ID:");
						scanf("%d",&option1);
						i=if_id(n,option1,book);
						if(i!=-1) {
							search_book(n,book,i);
						}
					}
					else if(by==2 ||by==3) {
						getchar();
						printf("enter Name:");
						char name1[30];
						fgets(name1,30,stdin);
						name1[strcspn(name1,"\n")]=0;
						for(int j=0; j<strlen(name1); j++) {
							name1[j]=tolower(name1[j]);
						}
						search_book1(n,book,name1);
					}
					break;
				}
				case 3: {
					printf("Enter Book ID:");
					scanf("%d",&option1);
					i=if_id(n,option1,book);
					if(i!=-1) {
						issue_book(i,n,book);
					}
					break;
				}
				case 4: {
					printf("Enter Book ID:");
					scanf("%d",&option1);
					i=if_id(n,option1,book);
					if(i!=-1) {
						return_book(i,n,book);
					}
					break;
				}
				case 5:
					printf("Thank you!!🥰\n");
					break;
				default:
					printf("Invalid choice❌\n");//invalid user menu choice
				}
			} while(choice3!=5);
		}
		else if(choice1==3) {
			printf("Thank you for using our Library📚🙏 !!\n");
		}
		else {
			printf("invalid option❌\n");//invalid  main menu choice
		}
	} while(choice1!=3);
	free(book); //free the Memory
}