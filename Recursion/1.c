#include<stdio.h>
int i=1,n;

int rec(int n){
    if(n>50)
        return n;
    printf("%d\t",n);
    rec(n+1);
}


int main(){
    int n=1;
    rec(n);
    return 0;
}