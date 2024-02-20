#include<stdio.h>
#include<stdlib.h>
#define max 5
int cq[max];
int f=-1,r=-1;
void enqueue(){
    if((f==0 && r==max-1) || ((r+1)==f))
        printf("\nOverflow\n");

    else{
        if(f==-1){
            f++;
            r++;
        }
        else
            r=(r+1)%max;

        printf("Enter the element:\n");
        scanf("%d",&cq[r]);
        
    }
}

void dequeue(){
    if(f==-1 || f==r)
        printf("\nUnderflow\n");

    else
        f=(f+1)%max;
}

void display(){
    if((f==-1) || (f==(r+1)))
        printf("\nUnderflow\n");

    else{
        int i=f-1;
        do{
            i=(i+1)%max;
            printf("%d\t",cq[i]);
        }while(i!=r);
        printf("\n");
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
            enqueue();
            break;
        case 2:
            dequeue();
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