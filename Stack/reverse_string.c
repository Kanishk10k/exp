#include<stdio.h>

void push(char);
char pop();
int t=-1;
char stack[50];

int main(){
    char str[50]="kanishk gupta";
    for(int i=0;str[i]!='\0';i++)
        push(str[i]);

    for(int i=t;i>=0;i--)
        pop();
}

void push(char a){
    stack[++t]=a;
}

char pop(){
    printf("%c",stack[t--]);
}