#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

void fenqueue();
void renqueue();
void fdequeue();
void rdequeue();
void display();

int main()
{
    int n;
    while (1)
    {
        printf("enter a choice::\n1.frontenqueue\n2.rearenqueue\n3.frontdequeue\n4.reardequeue::");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            fenqueue();
            break;
        case 2:
            renqueue();
            break;
        case 3:
            fdequeue();
            break;
        case 4:
            rdequeue();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("worng choice\n");
        }
    }
    return 0;
}

void fenqueue()
{
    if ((rear + 1) % MAX == front)
    {
        printf("Overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if (front < 1)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }
    scanf("%d", &queue[front]);
}
void renqueue()
{
    if ((front == 0 && rear == MAX - 1) || (rear + 1) == front)
    {
        printf("\noverflow");
    }
    else if (rear == -1 && front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)         
    {
        rear = (rear + 1) % MAX;
    }
    else
    {
        rear++;
    }
    scanf("%d", &queue[rear]);
}
void fdequeue()
{
   if(front==-1&&rear==-1)
   {
        printf("underflow\n");
   }
   else if(front==rear)
   {
        front = rear = -1;
   }
   else if(front==MAX-1)
   {
        printf("%d is deleted\n", queue[front]);
        front = 0;
        
   }
   else
   {
        printf("%d is deelted\n", queue[front]);
        front++;
   }
}
void rdequeue()
{
    if(front==-1&&rear==-1)
   {
        printf("underflow\n");
   }
   else if(front==rear)
   {
        front = rear = -1;
   }
   else if(rear==0)
   {
        printf("%d is deleted\n",queue[rear]);
        rear=MAX-1;
   }
   else{
        printf("%d is deleted\n", queue[rear]);
        rear--;
   }
}
void display()
{
    if (front == -1 && rear==-1)
    {
        printf("underflow\n");
    }
    else
    {
        for (int i = front; i != rear; i = (i + 1 % MAX))
        {
            printf("%d ", queue[i]);
        }
        printf("%d ", queue[rear]);
        }
}