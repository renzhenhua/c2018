#include<stdio.h> 
#include<stdlib.h>
#include <windows.h>
int main()
{
	char str[20];
	int i, j, k;
	gets(str);
    for(i=1;i<=115;i++)
	{
	    for(j=1;j<i;j++)
	    printf(" ");
	    printf("%s",str);
	    Sleep(20);
	    system("CLS");
    }
    for(k=114;k>=1;k--) 
	{
	  	for(j=1;j<=k;j++)
	  	printf(" ");
	  	printf("%s",str);
	  	Sleep(20);
	    system("CLS");
    }
	return 0;
}
