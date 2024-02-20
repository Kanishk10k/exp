#include<stdio.h>
#include<stdlib.h>

typedef struct linknode{
    int data;
    struct linknode *next;
}node;

node *start,*temp,*rear;

void create_list(){
    temp=(node*)malloc(sizeof(node));
    printf("Enter the new value : ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(start==NULL){
        start=temp;
        rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}

void display(){
    if(start==NULL)
        printf("\nUnderflow\n");

    else{
        temp=start;
        while(temp!=NULL){
            printf("%d\t->\t",temp->data);
            temp=temp->next;
        }
        printf("\n\n");
    }
}

void reverse(){
    node *x,*y,*z;
    y=start;
    start=rear;
    rear=y;
    while(y!=NULL){
        z=y->next;
        y->next=x;
        x=y;
        y=z;
    }
}

int main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        create_list();

    display();
    reverse();
    printf("\n\nThe reversed linked list is as followed : \n\n");
    display();
    return 0;
}