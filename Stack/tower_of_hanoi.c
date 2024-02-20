#include<stdio.h>
void toh(int, char,char,char);
int main(){
    int n=3;
    char a='A',b='B',c='C';
    toh(n,a,b,c);
    return 0;
}

void toh(int n, char a,char b, char c){
    if(n>0){
        toh((n-1),a,c,b);
        printf("%c -> %c\n",a,c);
        toh((n-1),b,a,c);
    }
}