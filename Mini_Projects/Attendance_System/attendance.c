#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//structure defined for Attendance
typedef struct {
	int roll_no;  //roll number
	char name[30];//name of student
	char status[10];//absent or present
} std;

//function to add student
void add_student(int* n,std **Student) {
	(*n)++;
	*Student=realloc(*Student,(*n) * sizeof(std)); //allocate new memory
	if(*Student==NULL) { //Memory check
		printf("Memory Allocation Failed.\n");
		exit(1);
	}
	else {
		//enter the details
		while(1) {
			int choice1,choice=1;
			printf("Enter Roll.no:");
			choice=scanf("%d",&(*Student)[(*n)-1].roll_no);
			while(getchar()!='\n');//discard invalid input
			if(choice!=1) {//invalid input
				printf("enter a digit roll no.\n");
				continue;
			}
			break;
		}
		printf("Enter Name:");
		fgets((*Student)[(*n)-1].name,30,stdin);
		(*Student)[(*n)-1].name[strcspn((*Student)[(*n)-1].name,"\n")]=0;
		strcpy((*Student)[(*n)-1].status,"");
		printf("\nAdded Successfully!!\n");//student added
	}
}

//function to view students
void view_students(int n,std *Student) {
	if(n==0) {
		printf("\nNo Students.Add Students First\n");
		return;
	}
	else {
		printf("=============================\n");
		printf("ROLL.NO       NAME\n");
		printf("=============================\n");
		for(int i=0; i<n; i++) {
			printf("%d         %s\n",Student[i].roll_no,Student[i].name);
		}
	}
}

//function to mark the Attendance
void mark_attendance(int *n,std **Student) {
	char mark;
	for(int i=0; i<(*n); i++) {
		printf("roll.no:%d\t",(*Student)[i].roll_no);
		printf("name:%s\t",(*Student)[i].name);
		printf("\nMark Attendance:Present(P) Absent(A):");
		while(1) {
			mark=getchar();
			while(getchar()!='\n');//to store one char
			mark=toupper(mark);
			if(mark=='P') {//if student present
				strcpy((*Student)[i].status,"Present");
				printf("\n");
				break;
			}
			else if(mark=='A') {//if student absent
				strcpy((*Student)[i].status,"Absent");
				printf("\n");
				break;
			}
			else {
				printf("invalid input.please enter present(P)/Absent(A)\n");
				continue;
			}
		}
	}
	printf("Added Successfully!!\n");
}

//function to view attendance
void view_attendance(int n,std *Student,FILE*ptr) {
	fprintf(ptr,"------Attendance Report------\n\n");
	if(n==0) {
	   	fprintf(ptr,"\nNo Report.Attendance Not Taken.\n");
		return;
	}
	else {
		fprintf(ptr,"Date:%s\n",__DATE__);//date
		fprintf(ptr,"=======================================\n");
		fprintf(ptr,"ROLL.NO     NAME           STATUS\n");
		fprintf(ptr,"=======================================\n");
		for(int i=0; i<n; i++) {
			fprintf(ptr,"%-10d  %-15s %-10s\n",Student[i].roll_no,Student[i].name,Student[i].status);
		}
	}
}

int main()
{
	int choice,result=1;
	int n=0;
	std * Student=malloc(n * sizeof(std));//memory Allocation
	FILE*ptr;
	ptr=fopen("attendance.txt","a");//opeinf a file in append mode
	if(ptr==NULL) {
		perror("Failed to open file");
		exit(1);
	}

	do {
		//Attendance Menu
		printf("\n========ATTENDANCE SYSTEM========\n\n");
		printf("1.Add Student\n2.View Students\n3.Mark Attendance\n4.View Attendance\n5.Exit\n\n");
		printf("enter your choice:");
		result=scanf("%d",&choice);
		while(getchar()!='\n');  //discard invalid iutput
		if(result!=1) { //invalid input
			printf("invalid choice,enter a number.\n");
			continue;
		}
		switch(choice) {
		case 1:
			add_student(&n,&Student);
			break;
		case 2:
			view_students(n,Student);
			break;
		case 3:
			mark_attendance(&n,&Student);
			break;
		case 4:
			view_attendance(n,Student,stdout);
			view_attendance(n,Student,ptr);
			break;
		case 5:
			printf("\nThank you!!\n");
			break;
		default:
			printf("Invalid Choice\n");
			break;
		}
	}
	while(choice!=5);//untill the user exit

	free(Student);//free memory
	fclose(ptr);//close the file
}
