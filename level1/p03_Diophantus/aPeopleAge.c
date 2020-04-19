#include<stdio.h>
int main()
{
	float age;
	for(age=1;age<200;age++)
	    if(age/12+age/6+age/7+5+age/2+4==age){
	    	printf("%.0f", age);
	    	break;
	    }
	return 0;
}
