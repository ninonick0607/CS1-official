#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    int data;
    node *link;
};

node *createnode(int data){
    node *temp=(node*)malloc(sizeof(node));

    temp->data=data;
    temp->link=NULL;
    printf("Num: %d",temp->data);
    return temp;

}


int main(){
    int data[3]={1,2,3};
    node* head=NULL;

    for(int i=0;i<3;i++){
        createnode(data[i]);
    }

    printf("Hello");
    while(head!=NULL){
        printf("Number: %d",head->data);
        head=head->link;
    }
    return 0;
}