#include<stdio.h>
#include<stdlib.h>

typedef struct linknode{
    struct linknode *prev;
    int data;
    struct linknode *next;
}node;

node *start,*temp,*rear;
void create_node(){
    temp=(node*)malloc(sizeof(node));
    printf("Enter the new value : ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;
}

void display_front(){
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

void display_back(){
    if(start==NULL)
        printf("\nUnderflow\n");

    else{
        temp=rear;
        while(temp!=NULL){
            printf("%d\t->\t",temp->data);
            temp=temp->prev;
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
        start->prev=temp;
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
        temp->prev=rear;
        rear=temp;
    }
}

// void insert_mid(){
//     int pos;
//     printf("Enter the position of middle element to be inserted : ");
//     scanf("%d",&pos);
//     if(pos>0 && pos<=c+1){
//         if(pos==1)
//             insert_front();
//     }
// }

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
            temp->prev=rear;
            rear=temp;
        }
    }

    display_front();
    printf("\n\n");
    display_back();
    insert_front();
    display_front();
    insert_end();
    display_back();
    
    return 0;
}