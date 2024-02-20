#include<stdio.h>
#include<stdlib.h>
#define max 5
int s[max],s1[max];
int t=-1,t1=-1;

void push(int x){
    s[++t]=x;
}

int pop(){
    return s[t--];
}

void push1(int x){
    s1[++t1]=x;
}

int pop1(){
    return s1[t1--];
}

void enque(){
    int n;
    if(t==max-1)
    printf("\nOverflow\n");

    else{
        printf("\nEnter the Element: ");
        scanf("%d",&n);
        push(n);
    }
}

void deque(){
    int x;
    if(t==-1)
    printf("\nUnderflow\n");

    else{
            while(t>=-1){
                x=pop();
                push1(x);
            }
            printf("\n%d is deleted\n",pop1());
            while (t>=-1)
            {
                x=pop1();
                push(x);
            }
    }
}

void display(){
    if(t==-1)
    printf("\nUnderflow\n");
    else{
        for(int i=t;s[i]!='\0';i++)
            printf("%d\n",s[i]);
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n1:enque\n2:deque\n3:display\n0:exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enque();
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("wrong choice\n");
            break;
        }
    }
    return 0;
}