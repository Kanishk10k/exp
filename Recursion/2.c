#include<stdio.h>
int i=1,n;

int rec(int n){
    if(n<=0)
        return n;

    n=n+rec(n-1);
    return n;
}


int main(){
    int n,sum;
    scanf("%d",&n);
    sum=rec(n);
    printf("sum=%d",sum);
    return 0;
}