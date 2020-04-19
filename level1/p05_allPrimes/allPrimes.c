#include<stdio.h>
#include<math.h>
#include<time.h>
int main(void)
{
	int t1=clock();
	int i, m, n;
	for(m=2;m<=1000;m++){
		n=sqrt(m);
		if(m>3&&(m%2==0||m%3==0)){
			continue;
		}
		for(i=2;i<=n;i++){
			if(m%i==0)
			break;
		if(i>=n){
			printf("%d\n", m);
		}
	}
}
    int t2=clock();
    printf("%dms\n", t2 - t1);
	return 0;
} 
