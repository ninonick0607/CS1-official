#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;

node* add_beg(node* head,int item){
    node *temp=(node*)malloc(sizeof(node));
    temp->info=item;
    temp->next=NULL;
   
    temp->next=head;
    head=temp;

    //printf("%d ", head->info);

    return temp; 
}

void display(node *phead){
    node *tmp = phead;

    while(tmp!=NULL){
        printf("%d ", tmp->info);
        tmp=tmp->next;
    }
}

int main()
{
    node *head=(node*)malloc(sizeof(node));
    head->info=2;
    head->next=NULL;

    node *ptr=(node*)malloc(sizeof(struct node));
    ptr->info=3;
    ptr->next=NULL;

    head->next=ptr;

    add_beg(head,1);

    display(head);
    
    return 0;
}