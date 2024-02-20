#include<stdio.h>
void push(char);
char pop();
int t=-1;
char stack[50];

int main(){
    char a,str[50]="[{()}][";
    int x=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        push(str[i]);

        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            if(t==-1){
                x=1;
                break;
            }
            
            else{
                a=pop();
                if(a =='(' && str[i]!=')'){
                x=1;
                break;
            }
            
            else if(a =='{' && str[i]!='}'){
                x=1;
                break;
            }
            
            else if(a =='[' && str[i]!=']'){
                x=1;
                break;
            }
            }
        }
    }
    if(t>=0)
    x=1;

    if(x)
    printf("Not Balanced");

    else
    printf("Balanced");
    return 0;
}

void push(char a){
    stack[++t]=a;
}

char pop(){
    return stack[t--];
}