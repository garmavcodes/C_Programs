#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	char task[100];
	char priority[10];
	char status[30];
	char due_date[20];
} std;

void add_task(int *n,std **to_do) {
	(*n)++;
	*to_do=realloc(*to_do,(*n)*sizeof(std));
	printf("\ntask:");
	fgets((*to_do)[(*n)-1].task,100,stdin);
	(*to_do)[(*n)-1].task[strcspn((*to_do)[(*n)-1].task,"\n")]=0;
	printf("priority(high,medium,low):");
	scanf("%s",(*to_do)[(*n)-1].priority);
	for(int i=0; (*to_do)[(*n)-1].priority[i]; i++) {
		(*to_do)[(*n)-1].priority[i]=tolower((*to_do)[(*n)-1].priority[i]);
	}
	printf("status(pending,completed,progress):");
	scanf("%s",(*to_do)[(*n)-1].status);
	for(int i=0; (*to_do)[(*n)-1].status[i]; i++) {
		(*to_do)[(*n)-1].status[i]=tolower((*to_do)[(*n)-1].status[i]);
	}
	printf("due date(YYYY-MM-DD):");
	scanf("%s",(*to_do)[(*n)-1].due_date);
	printf("TASK ADDED!!\n");
	printf("______________________________________________________");

}

void view_task(int n,std *to_do,FILE *ptr) {
	if(n==0) {
		fprintf(ptr,"NO TASKS\n\n");
	}
	for(int j=0; j<n; j++) {
		fprintf(ptr,"\n**TASK %d**\n",j+1);
		fprintf(ptr,"Task:%s\n",(to_do)[j].task);
		fprintf(ptr,"Priority:%s\n",(to_do)[j].priority);
		fprintf(ptr,"Status:%s\n",(to_do)[j].status);
		fprintf(ptr,"Due date:%s\n",(to_do)[j].due_date);
	}
	fprintf(ptr,"____________________________________________________\n");
}

void remove_task(int *n,std **to_do,int index,FILE *ptr) {
	if(index<0 || index>=(*n)) {
		printf("invalid task number\n_________________________________________________________\n");
		return;
	}
	for(int i=index; i<(*n)-1; i++) {
		(*to_do)[i]=(*to_do)[i+1];
	}
	(*n)--;
	(*to_do)=realloc(*to_do,(*n)*sizeof(std));
	printf("TASK REMOVED!!");
	printf("\n________________________________________________________________\n");
	view_task(*n,*to_do,ptr);
}

void update_task(int *n,std **to_do,int update,FILE *ptr) {
	char new[20],change[20];
	if(update<0 || update>=(*n)) {
		printf("invalid task number\n____________________________________________\n");
		return;
	}
	printf("what do you want to update(task,priority,status,due_date)?:");
	scanf("%s",change);
	if(strcmp(change,"priority")==0) {
		printf("enter the new %s:",change);
		scanf("%s",new);
		for(int i=0; new[i]; i++) {
			new[i]=tolower(new[i]);
		}
		strcpy((*to_do)[update].priority,new);
		printf("UPDATED!!\n__________________________________________________________\n");
	}
	else if(strcmp(change,"status")==0) {
		printf("enter the new %s:",change);
		scanf("%s",new);
		for(int i=0; new[i]; i++) {
			new[i]=tolower(new[i]);
		}
		strcpy((*to_do)[update].status,new);
		printf("UPDATED!!\n__________________________________________________________\n");
	}
	else if(strcmp(change,"due_date")==0) {
		printf("enter the new %s:",change);
		scanf("%s",new);
		strcpy((*to_do)[update].due_date,new);
		printf("UPDATED!!\n__________________________________________________________\n");
	}
	else if(strcmp(change,"task")==0) {
		getchar();
		printf("enter the new %s:",change);
		fgets(new,20,stdin);
		new[strcspn(new,"\n")]=0;
		strcpy((*to_do)[update].task,new);
		printf("UPDATED!!\n__________________________________________________________\n");
	}
	else {
		printf("%s doesnt exist\n________________________________________________________________\n",change);
	}
	view_task(*n,*to_do,ptr);
}

int main() {
	std *to_do;
	int index,update,choice,n=0;
	to_do=malloc(n*sizeof(std));
	FILE*ptr;

	printf("***To-Do List Manager***\n");
	do {
		printf("\n1.add task\n2.view tasks\n3.remove task\n4.update task\n5.exit\n");
		printf("Enter choice:");
		scanf("%d",&choice);
		getchar();
		switch(choice) {
		case 1:
			add_task(&n,&to_do);
			ptr=fopen("myfile.txt","w");
			view_task(n,to_do,ptr);
			fclose(ptr);
			break;

		case 2:
			view_task(n,to_do,stdout);
			break;
		case 3: {
			printf("enter the task number to delete:");
			scanf("%d",&index);
			remove_task(&n,&to_do,index-1,stdout);
			ptr=fopen("myfile.txt","w");
			view_task(n,to_do,ptr);
			fclose(ptr);

			break;
		}
		case 4:
			printf("enter the task number you want to update:");
			scanf("%d",&update);
			getchar();
			update_task(&n,&to_do,update-1,stdout);
			ptr=fopen("myfile.txt","w");
			view_task(n,to_do,ptr);
			fclose(ptr);
			break;
		case 5:
			printf("thank you\n");
			break;
		default:
			printf("invalid choice\n");
			break;
		}
	} while(choice!=5);
	free(to_do);

}
