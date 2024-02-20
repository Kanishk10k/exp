#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *start,*front,*rear;
int counter=0;
void create(int);
void display();
void count();
void ADDatBEGNING(int);
void addAFTER(int, int);
void delete(int);
void doubley();
void doublE_NODE();
void reverse();
void push();
void pop();
void peak();
void enqueue();
void dis();
void dequeue();
int main()
{

    int num, i, choice, pos;
    front=NULL;
    rear=start;
    start = NULL;
    
    printf("Enter    1 : to create a list\n\t 2 : to display \n\t 3 : to count the node\n\t 4 : to add at begning \n\t 5 : to add after \n\t 6 : to delete \n\t 7 : to double last second element\n\t 8 : to double nth element from last  \n\t 9 : to reverse the list \n\t 10 : for stack\n 11: queue \n 12 : exit");
    do{                           
        
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item to add in list : ");
            scanf("%d", &num);
            printf("\n");
            create(num);
            break;
        case 2:
            display();
            break;
        case 3:
            count();
            break;
        case 4:
            printf("Enter item to add in list : ");
            scanf("%d", &num);
            printf("\n");
            ADDatBEGNING(num);
            break;
        case 5:
            printf("Enter position : ");
            scanf("%d", &pos);
            printf("Enter item to add in list : ");
            scanf("%d", &num);
            printf("\n");
            addAFTER(pos, num);
            break;
        case 6:
            printf("Enter item ypu want to remove from list : ");
            scanf("%d", &num);
            printf("\n");
            delete (num);
            break;
        case 7: doubley();
               break;
        case 8:doublE_NODE();
                break;
        case 9  : reverse();
                  break; 
        case 10 : printf("\n\t1 : push\n\t2 : pop \n\t3 : peak");
                  int n;
                  scanf("%d",&n);
                  switch(n){
                    case 1: push();
                            break;
                    case 2 : pop();
                             break;
                    case 3 : peak();
                  }
                  break;
        case 11 : 
                   printf("Enter \n\t 1 : enqueue \n\t 2 : dequeue \n\t 3 : display");
                    int ai;
                   scanf("%d",&ai);
                   switch(ai){
                    case 1 : enqueue();
                             break;
                    case 2 : dequeue();
                             break;
                    case 3 : dis();
                   }
                  break;
        case 12 : exit(0);
        
        default:
            printf("WRONG CHOICE \n");
        }
    } while (1);
}

void create(int num)
{
    // this function add node at the end of link list
    struct node *q, *t;
    if (start == NULL)
    {
        start = (struct node *)malloc(sizeof(struct node));
        start->data = num;
        start->next = NULL;
    }
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        t = (struct node *)malloc(sizeof(struct node));
        t->data = num;
        t->next = NULL;
        q->next = t;
    }
    counter++;
}

void display()
{
    struct node *q;
    if (start == NULL)
    {
        printf("LIST is EMPTY\n");
        return;
    }
    printf("Item in list :\t");
    for (q = start; q != NULL; q = q->next)
        printf("\t %d", q->data);
        printf("\n");
}

void count()
{
    struct node *q;
    int n = 0;
    for (q = start; q != NULL; q = q->next)
        n++;
    printf("\n NUMBER of nodes in list = %d\n", n);
}

void ADDatBEGNING(int num)
{
    struct node *q;
    q = (struct node *)malloc(sizeof(struct node));
    q->data = num;
    q->next = start;
    start = q;
    counter++;

}

void addlast(int num){
    struct node *q,*t;
    q=start;
    if(q==NULL){
        create(num);
    }
    
    else{    // q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        t = (struct node *)malloc(sizeof(struct node));
        t->data = num;
        t->next = NULL;
        q->next = t;
    }
    counter++;
}
void addAFTER(int pos, int num)
{
    struct node *q, *t;
    int i;
    q = start;
    if(pos==1){
     ADDatBEGNING(num);
     return;
    }
    for (i = 1; i < pos; i++)
    {
        q = q->next;

        if (q == NULL)
        {
            printf(" there are less then %d elements \n", pos);
            return;
        }
    }
    t = (struct node *)malloc(sizeof(struct node));
    t->data = num;
    t->next = q->next;
    q->next = t;
    counter++;
}

void delete(int num)
{
    struct node *q, *t;
    q = start;
    if (q == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (q->data == num)
    {
        start = q->next;
        printf("Element Removed");
        free(q);
        return;
    }
    t = q;
    q = q->next;
    while (q != NULL)
    {
        if (q->data == num)
        {
            t->next = q->next;
            printf("Item Removed\n");
            free(q);
            return;
        }
        t = q;
        q = q->next;
    }
    printf("\nItem =%d is not found\n", num);
}
void doubley(){
    struct node *q;
    q=start;
    if(q==NULL||q->next==NULL)
    printf("underflow");
    else{
       for (; q->next->next!= NULL; q = q->next){

       }

    q->data=(q->data)*2;
    printf("\n after performing number become = %d\n\n", q->data);
    }
}
void doublE_NODE(){
    struct node *q;
    q=start;
    int n;
    printf("enter the node position you want to double from last : ");
    scanf("%d",&n);
    if(q==NULL||n>counter||n<1)
    printf("INVALID location\n");
    else{
       for (int i=0;i<counter-n;i++)
        q=q->next;
        q->data=(q->data)*2;
    printf("\n double element = %d\n\n", q->data);
    }
}
void reverse(){
     struct node *q,*r,*s;
     q=start;
     if(q==NULL)
        printf("%d",q->data);
     else{
        r=q->next;
        s=r->next;
        q->next=NULL;
        while(s!=NULL){
            r->next=q;
            q=r;
            r=s;
            s=s->next;

        }
        r->next=q;
        start=r;
        
     }

}
void push()
{
    struct node *q,*t;
    q=start;
    int num;
    printf("enter no. you want to enter : ");
    scanf("%d",&num);
    
          t=(struct node *)malloc(sizeof(struct node));
          t->data=num;
          t->next=q;
          start=t;
}
void pop(){
    struct node *q;
    q=start;
    if(start==NULL){
        printf("underflow\n");
    }
    else{
        start=q->next;
        free(q);
    }
}
void peak(){
    struct node *q;
    q=start;
    if(q==NULL){
        printf("stack is empty");
    }
    else{
        while(q->next!=NULL){
        }
        printf("%d",q->data);
    }
}
void enqueue(){
    struct node *t;
    int num;
    printf("enter number you want to enter : ");
    scanf("%d",&num);
    
    if (front == NULL)
    {
        front = (struct node *)malloc(sizeof(struct node));
        front->data = num;
        front->next = NULL;
        rear=front;
        start=rear;
    }
    else
    {
       
        t = (struct node *)malloc(sizeof(struct node));
        t->data = num;
        t->next = NULL;
        front->next = t;
        front=t;
        
    } 
}
void dis(){
    struct node *q=rear;
    while(q!=NULL){
        printf("%d\t",q->data);
        q=q->next;
    }
}
void dequeue(){
    if(rear==NULL){
        printf("Underflow");
    }
    else{
        printf("dequeue element is %d",rear->data);
        rear=rear->next;
        start=rear;
    }
}