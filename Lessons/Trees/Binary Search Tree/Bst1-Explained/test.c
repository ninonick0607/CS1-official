#include <stdio.h>
#include 
typedef struct bstNode {
  struct bstNode *left, *right;
  int data;
} bstNode;

int countNodes(bstNode *root) {
  int count = 0;
  if (root != NULL) {
    count = 1 + countNodes(root->left) + countNodes(root->right); 
  }
  return count;
}

int main() {

  bstNode *root = NULL;
  
  // Build a sample tree
  root = malloc(sizeof(bstNode));
  root->data = 1;
  
  root->left = malloc(sizeof(bstNode));
  root->left->data = 2;
  
  root->right = malloc(sizeof(bstNode));
  root->right->data = 3;
  
  root->left->left = malloc(sizeof(bstNode));
  root->left->left->data = 4;
  
  root->right->right = malloc(sizeof(bstNode));
  root->right->right->data = 5;

  int nodeCount = countNodes(root);
  
  printf("Node count: %d\n", nodeCount);
  
  return 0;
}