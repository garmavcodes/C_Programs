#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Replace all occurrences of oldword with newword in str
char* replace(const char * str,const char * oldword, const char * newword) {
	char * resultstr;
	int i,count=0;
	int newlen=strlen(newword);
	int oldlen=strlen(oldword);

	// Count occurrences of oldword
	for(int i=0; str[i]!='\0'; i++) {
		if(strstr(&str[i],oldword)==&str[i]) {
			count ++;
			i=i+oldlen-1;
		}
	}

	// Allocate memory for new string
	resultstr=malloc(i+count * (newlen - oldlen)+1);
	i=0;

	// Copy str to resultstr and replace oldword
	while(*str) {
		if(strstr(str,oldword)==str) {
			strcpy(&resultstr[i],newword);
			i+=newlen;
			str+=oldlen;
		}
		else {
			resultstr[i]=*str;
			i++;
			str++;
		}
	}
	resultstr[i]='\0';
	return resultstr;
}

int main()
{
	FILE*ptr=NULL;  // file to read original text
	FILE*ptr2=NULL; // file to write replaced text
	char str[400];  // buffer for file content
	char name[50];  // user input name
	char item[30];  // user input item
	char outlet[60]; // user input outlet

	// take user input
	printf("enter your name:");
	fgets(name,50,stdin);
	name[strcspn(name, "\n")] = '\0';

	printf("enter the item you parchased:");
	fgets(item,30,stdin);
	item[strcspn(item, "\n")] = '\0';

	printf("enter the outlet name:");
	fgets(outlet,60,stdin);
	outlet[strcspn(outlet, "\n")] = '\0';

	// read original file
	ptr=fopen("myfile.txt","r");
	fgets(str,400,ptr);
	printf("the bill before:%s\n\n",str);
	

	char * newstr; // store replaced string
	ptr2=fopen("myfile2.txt","w");

	// replace placeholders
	newstr=replace(str,"(name)",name);
	newstr=replace(newstr,"(item)",item);
	newstr=replace(newstr,"(outlet)",outlet);

	// write replaced string to file and display
	fprintf(ptr2,"%s",newstr);
	printf("the bill later:%s",newstr);
	
	free(newstr);
	fclose(ptr);
	fclose(ptr2);
	return 0;
}
