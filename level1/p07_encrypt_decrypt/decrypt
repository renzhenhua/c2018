#include<stdio.h>
#include<string.h>
#define MAXLINE 100
void decrypt(char *);
int main()
{
	char line[MAXLINE];
	printf("Input the string:");
	gets(line);
	decrypt(line);
	printf("%s\n", line);
	return 0;
}
void decrypt(char*s)
{
	for(; *s!='\0';s++){
		if(*s=='a'){
			*s='z';
		}else{
			*s=*s - 1;
		}
	}
}
