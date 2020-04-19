#include<stdio.h>
#include<math.h>
int main()
{
    int m, i, n;
    scanf("%d", &m);
    if(m==1){
        printf("%d不是素数");
        }
    else{
        n = sqrt(m);
        for(i=1;i<=n;i++){
            if(m%i==0)
            break;
        }
        if(i>n){
            pritnf("%d是素数");
        }else{
            printf("%d不是素数");
        }
}
   return 0;
}
