#include<stdio.h>
#include<math.h>
int isPrime(int c);
int main()
{
	int i, a, b,n1, n2;
	for(i=4;i<=100;i++,i++){
		for(a=2;a<(i/2);a++){
			n1 = isPrime(a);
			if(n1){
				b = i-a;
				n2 = isPrime(b);
				if(n2){
					printf("%d = %d + %d\n", i, a, b);
				}
			}
		}
	}
	return 0;
}
int isPrime(int c)
{
	int m, i;
	m = sqrt(c);
	if(c==2){
		return 1;
	}
	for(i=2;i<=m;i++){
		if(c%i==0){
			return 0;
			break;
		}
	}
	if(m>i)
	return 1;
}
