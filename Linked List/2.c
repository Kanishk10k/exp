#include<stdio.h>
#include<stdlib.h>

typedef struct linknode{
    int data;
    struct linknode *next;
}node;

node *start,*temp,*rear;
int c=0;

void create_node(){
    temp=(node*)malloc(sizeof(node));
    printf("Enter the new value : ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    c++;
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
    }
}

void insert_front(){
    printf("\nTo insert at the front , ");
    create_node();
    if(start==NULL){
        start=temp;
        rear=temp;
    }
    else{
        temp->next=start;
        start=temp;
    }
}

void insert_end(){
    printf("\nTo insert at the end , ");
    create_node();
    if(start==NULL){
        start=temp;
        rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}

void insert_mid(){
    int pos;
    node *p=NULL,*q=NULL;
    printf("Enter the position of middle element to be inserted : ");
    scanf("%d",&pos);
    if(pos>0 && pos<=c+1){
        if(pos==1)
            insert_front();
        
        else if(pos==c+1)
            insert_end();
        
        else{
            if(p==NULL){
                    p=start->next;
                }
            for(int i=1;i<pos-1;i++)
                p=p->next;
            temp->next=p->next;
            p->next=temp;
        }
    }

    else
        printf("\nInvalid Position\n");
}

int main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        create_node();
        if(start==NULL){
            start=temp;
            rear=temp;
        }
        else{
            rear->next=temp;
            rear=temp;
        }
    }

    display();

    insert_front();
    display();

    insert_end();
    display();
    return 0;
}