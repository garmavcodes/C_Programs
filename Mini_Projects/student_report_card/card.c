#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
	char name[50];
	int roll_num;
	char class_name[10];
	int marks[4];
} std;

// Function to calculate total marks, percentage and grade
void report(std names,FILE *ptr) {
	int total=0;
	float per;

	for(int j=0; j<4; j++) {
		total+=names.marks[j]; // Sum marks
	}
	per=(total/400.0)*100; // Calculate percentage
	fprintf(ptr,"THE TOTAL MARKS OUT OF 400 ARE :%d\n",total);
	fprintf(ptr,"THE PERCENTAGE IS:%.2f\n",per);
	fprintf(ptr,"GRADE:");
	if(per>=90) {
		fprintf(ptr,"A\n");
	} else if(per<90 && per>=80) {
		fprintf(ptr,"B\n\n\n");
	}
	else if(per<80 && per>=70) {
		fprintf(ptr,"C\n\n\n");
	}
	else if(per<70 && per>=60) {
		fprintf(ptr,"D\n\n\n");
	}
	else  {
		fprintf(ptr,"F\n\n\n");
	}
}

int main()
{
    int n;
    printf("enter no students:");
    scanf("%d",&n);
	std*names=malloc(n*sizeof(std)); // Allocate memory for students
    // to take input from user
	for(int i=0; i<n; i++) {
		printf("\nstudent %d\n",i+1);
		printf("enter your name:");
		scanf(" %s",names[i].name);
		printf("enter your roll number:");
		scanf(" %d",&names[i].roll_num);
		printf("enter your class:");
		scanf(" %s",names[i].class_name);
		printf("enter your marks\n");
		printf("  math:");
		scanf(" %d",&names[i].marks[0]);
		printf("  science:");
		scanf(" %d",&names[i].marks[1]);
		printf("  social:");
		scanf(" %d",&names[i].marks[2]);
		printf("  hindi:");
		scanf(" %d",&names[i].marks[3]);
		
	}
	//to write output on screen
	for(int i=0; i<n; i++) {
		printf("\nreport card of student %d:\n",i+1);
		printf(" name:%s\n",names[i].name);
		printf(" roll number:%d\n",names[i].roll_num);
		printf(" class name:%s\n",names[i].class_name);
		printf(" marks\n");
		printf("  math:%d\n",names[i].marks[0]);
		printf("  science:%d\n",names[i].marks[1]);
		printf("  social:%d\n",names[i].marks[2]);
		printf("  hindi:%d\n",names[i].marks[3]);
		report(names[i],stdout); // Call report function
	}
	
	//to write the output in a file
	FILE * ptr;
	ptr=fopen("myfile.txt","w");
	if(ptr==NULL){
	    printf("error opening the file\n");
	    free(names);
	    return 1;
	}
	for(int i=0; i<n; i++) {
		fprintf(ptr,"\nreport card of student %d:\n",i+1);
		fprintf(ptr," name:%s\n",names[i].name);
		fprintf(ptr," roll number:%d\n",names[i].roll_num);
		fprintf(ptr," class name:%s\n",names[i].class_name);
		fprintf(ptr," marks\n");
		fprintf(ptr,"  math:%d\n",names[i].marks[0]);
		fprintf(ptr,"  science:%d\n",names[i].marks[1]);
		fprintf(ptr,"  social:%d\n",names[i].marks[2]);
		fprintf(ptr,"  hindi:%d\n",names[i].marks[3]);
		report(names[i],ptr); // Call report function for file
	}
	
	free(names); // Free allocated memory
	fclose(ptr); // Close file
}
