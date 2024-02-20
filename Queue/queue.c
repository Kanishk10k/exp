#include <stdio.h>
#include <stdlib.h>
int queue[50];
int r = -1, f = -1;
void enque(); 
void deque();  
void display();
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
void enque()
{
    if (r == 49)
    {
        printf("overflow\n");
    }
    else
    {
        if (f == -1)
        {
            f++;
            r++;
        }
        else
            r++;
        printf("\nenter new element:\n");
        scanf("%d", &queue[r]);
    }
}
void deque()
{
    if (f == -1)
    {
        printf("\nunderflow\n");
    }
    else
    {
        f++;
    }
    if (f > r)
    {
        f = -1;
        r = -1;
    }
}
void display()
{
    if (f == -1)
    {
        printf("\nunderflow");
    }
    else
    {
        for (int i = f; i <= r; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
    printf("\n");
}