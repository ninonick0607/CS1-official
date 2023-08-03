#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


typedef struct Node Node;

struct Node{
    int data; //Can be whatever type
    Node *next;
};



//Function to create a node
Node *createNode(int data){
    //Dynamically create Node
    Node *res=(Node*)malloc(sizeof(Node));

    //Initialize the data within the node
    res->data=data;

    //Initialize next pointer. It is unknwon at this point what
    //the node will point to, but the node could be the only node in
    //the list. If the node is the only node, then the next pointer
    //Should be NULL as this is the last node in the Linked List.
    res->next=NULL;

    //Return the node and the data associated with it
    return res;
}

//Function to inset a value at the beginning of a list
Node *insertBegHead(Node *head,int data){
    //Dynamically create node
    Node *newNode=createNode(data);

    //The old head will be the node that follows this new head
    newNode->next=head;

    //Return the resulting head of the linked list
    return newNode;
}

//Function to insert a value at the end of a linked list
Node *insertendHead(Node *head, int data){
    //Create the node dynamically
    Node *newNode= createNode(data);

    //Handle the empty linked list case
    if(head=NULL) return newNode;

    //The last will hold the address of the last node of the
    //Linked List

    Node *last = head;

    ///Find the last node of the linked list
    while(last->next != NULL){
        //The last was not the actual last since there was a next
        last = last->next;
    }
    //The old last will point to this new node
    last->next=newNode;

    //Return the resulting head of the linked list
    return head;
}

//Function to remove a node at the beginning of a linked list
Node *removeHead(Node *head){
    //Handle the empty Linked List case
    if(head==NULL) return NULL;

    //Get the pointer to the resuling head of the list
    Node *newHead = head->next;

    //Delete the old head
    free(head);

    //Return the resulting head of the linked list
    return newHead;

}
/*
Node *removeTail(Node *head){
    if(head==NULL) return NULL;

    //Handle the single node case
    if(head->next == NULL){
        free(head);
        return NULL;
    }

    //Get the pointer to the node before the last node
    Node *secondToLast = head;

    //Find the actual second to the last node
    while(secondToLast->next != NULL){
        //It was not the correct node..
        //Maybe its last next one!
        secondToLast=secondToLast->next;
    }

    //Delete the old tail
    free(secondToLast->next);

    //Update the second to last node to become the tail
    secondToLast->next=NULL;

    //Return the resulting head of the linked list
    return newHead;
}
*/

void printList(Node *head){
    //Loop over each node
    while(head!=NULL){
        printf("The number is %d\n",head->data);

        //Move to the next node
        head=head->next;
    }
}
/*
void deleteList(Node *head){
    //While the list is not empty
    while(head!=NULL){
        head=removeNode(head);
    }
}
*/

int main(){

    int arr[3]={3,2,1};
    Node *head=NULL;

    for(int i=0;i<3;++i){
        head = createNode(arr[i]);
        printList(head);
    }

    return 0;
}