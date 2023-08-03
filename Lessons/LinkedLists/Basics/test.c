#include <stdio.h>
#include <stdlib.h>


typedef struct test test;
struct test{
    int data;
    test *link;
};


test* createnode(int data){
    test *temp=(test*)malloc(sizeof(test));

    temp->data=data;
    temp->link=NULL;

    return temp;
}

test *insert_end(test *head,int data){
    test *temp=createnode(data);
    
    if(head=NULL) head=temp;
    else{
        test *t=head;
        while (t->link!=NULL){
            t=t->link;
        }
        t->link=temp;
    }

    return head;
}

void printlist(test* head){
    while(head!=NULL){
        printf("Number: %d ",head->data);
        head=head->link;
    }
}

int main(){

    int num;
    test *head=NULL;

    while(1){
        printf("Number please: ");
        scanf("%d",&num);
        head=insert_end(head,num);
        printlist(head);

    }

    return 0;
}