//3

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    node *left;
    node *right;
}node;

node *prune(node *root){
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL)
        free(root);
        return root;
    root->left=prune(root->left);
    root->right=prune(root->right);

    return root;
}

//4


