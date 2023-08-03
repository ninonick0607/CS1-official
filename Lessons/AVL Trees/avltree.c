// Arup Guha
// Started 6/26/2020
// AVL Tree Implementation (just insert, delete)
// Continued on 7/7/2020

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct avlnode {
    int data;
    struct avlnode* left;
    struct avlnode* right;
    int height;
} avlnode;

// Traversals - checkTree prints both.
void checkTree(avlnode* root);
void preorder(avlnode* root);
void postorder(avlnode* root);

// Helper functions.
avlnode* makeNewNode(int val);
int max(int a, int b);
int isLeafNode(avlnode* root);
int hasTwoChildren(avlnode* root);
avlnode* maxLeft(avlnode* root);
void freeTree(avlnode* root);

// Functions to aid in rebalancing.
void updateHeight(avlnode* root);
avlnode* rebalance(avlnode* root);

// Insert and search functions.
avlnode* insert(avlnode* root, int value);
int search(avlnode* root, int value);

// Functions for delete.
avlnode* delValue(avlnode* root, int value);
avlnode* findDelPtr(avlnode* root, int value);
avlnode* del(avlnode* root, avlnode* ptrDel) ;

// My tests
void smallinsert();
void manyinsertsbadcase();
void smalldel();
void manyinsertsanddeletesbadcase();

int main(void) {
    manyinsertsanddeletesbadcase();
    return 0;
}

// Runs a small hard-coded test of insert.
void smallinsert() {

    avlnode* tree = NULL;

    // Induce first rebalance then print.
    tree = insert(tree, 5);
    tree = insert(tree, 1);
    tree = insert(tree, 3);
    checkTree(tree);

    // Another one here.
    tree = insert(tree, 7);
    tree = insert(tree, 4);
    tree = insert(tree, 6);
    checkTree(tree);

    // Rebalance not at the top level.
    tree = insert(tree, 20);
    tree = insert(tree, 13);
    tree = insert(tree, 30);
    tree = insert(tree, 10);
    checkTree(tree);

    // Minor rebalance here.
    tree = insert(tree, 25);
    checkTree(tree);

    // Big one here at root.
    tree = insert(tree, 27);
    checkTree(tree);

    freeTree(tree);
}

// Runs a small hard-coded test of insert.
void smalldel() {

    avlnode* tree = NULL;

    // Tree before delete.
    tree = insert(tree, 10);
    tree = insert(tree, 5);
    tree = insert(tree, 15);
    tree = insert(tree, 13);
    tree = insert(tree, 17);
    checkTree(tree);

    // Root case, should delete physical node with the 5.
    tree = delValue(tree, 10);
    checkTree(tree);

    // Do a few more inserts.
    tree = insert(tree, 16);
    tree = insert(tree, 40);
    tree = insert(tree, 26);
    checkTree(tree);

    // Trigger case, 13 moves up to 5, then rebalance has to happen at 15.
    tree = delValue(tree, 5);
    checkTree(tree);

    // This is a two rebalance case here...when 16 goes 13,14,15 restructure, and then 17 has to also.
    tree = insert(tree, 60);
    tree = insert(tree, 14);
    tree = insert(tree, 21);
    tree = insert(tree, 30);
    tree = insert(tree, 50);
    tree = insert(tree, 70);
    tree = insert(tree, 19);
    tree = insert(tree, 28);
    tree = insert(tree, 35);
    checkTree(tree);

    // This should show our two rebalances!
    tree = delValue(tree, 16);
    checkTree(tree);

    freeTree(tree);
}

// Runs a pattern hard coded test which would take too long for a regular binary search tree.
void manyinsertsbadcase() {

    avlnode* tree = NULL;

    // Start our timer.
    int start = time(0);

    // This would take an hour or so with a regular binary tree.
    for (int i=2; i<=2000000; i+=2)
        tree = insert(tree, i);

    // Here we run 2000000 searches....
    for (int i=1; i<=2000000; i++) {
        int res = search(tree, i);
        if (res + i%2 != 1)
            printf("error on search for %d\n", i);
    }

    // Stop the timer.
    int end = time(0);

    // Time should prove that rebalancing happened.
    printf("ta da! %d sec\n", end-start);

    freeTree(tree);
}

// Runs a pattern hard coded test which would take too long for a regular binary search tree.
void manyinsertsanddeletesbadcase() {

    avlnode* tree = NULL;

    // Start our timer.
    int start = time(0);

    // This would take an hour or so with a regular binary tree.
    for (int i=2; i<=2000000; i+=2)
        tree = insert(tree, i);

    // Here we run 2000000 searches....
    for (int i=1; i<=2000000; i++) {
        int res = search(tree, i);
        if (res + i%2 != 1)
            printf("error on search for %d\n", i);
    }

    // Now we delete everything except for 2,4,6,8.
    for (int i=2000000; i>=10; i-=2)
       tree = delValue(tree, i);

    // Stop the timer.
    int end = time(0);

    // Time should prove that rebalancing happened.
    printf("ta da! %d sec\n", end-start);

    // Should show our 4 values...
    checkTree(tree);

    freeTree(tree);
}


// Inserts a node storing value into the avl tree pointed to by root returning the new root of the tree.
avlnode* insert(avlnode* root, int value) {

    // Empty tree, return a new one node tree.
    if (root == NULL) return makeNewNode(value);

    // Recursively insert into the left.
    if (value < root->data)
        root->left = insert(root->left, value);

    // Recursively insert into the right.
    else
        root->right = insert(root->right, value);

    // Here we rebalance this node before returning it.
    root = rebalance(root);

    // Update height.
    updateHeight(root);
    return root;
}

// Updates the height of the node pointed to by root.
void updateHeight(avlnode* root) {
    if (root == NULL) return;
    int leftH = root->left == NULL ? -1 : root->left->height;
    int rightH = root->right == NULL ? -1 : root->right->height;
    root->height = 1 + max(leftH, rightH);
}

// Returns the larger of a and b.
int max(int a, int b) {
    return a > b ? a : b;
}

// Allocates memory for a new node storing val and returns a pointer to it.
avlnode* makeNewNode(int val) {
    avlnode* tmp = malloc(sizeof(avlnode));
    tmp->data = val;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->height = 0;
    return tmp;
}

// Pre-condition: root isn't null.
avlnode* rebalance(avlnode* root) {

    // Just in case.
    if (root == NULL) return NULL;

    // Look left and right.
    int leftH = root->left == NULL ? -1 : root->left->height;
    int rightH = root->right == NULL ? -1 : root->right->height;

    // We're good!
    if (abs(leftH-rightH) <= 1) return root;

    // Will use these for restructuring.
    avlnode* tempA = NULL;
    avlnode* tempB = NULL;
    avlnode* tempC = NULL;
    avlnode* subT0 = NULL;
    avlnode* subT1 = NULL;
    avlnode* subT2 = NULL;
    avlnode* subT3 = NULL;

    // Left is too tall...
    if (leftH > rightH) {

        // Now, we must look at left's kids.
        int leftLeftH = root->left->left == NULL ? -1 : root->left->left->height;
        int leftRightH = root->left->right == NULL ? -1 : root->left->right->height;

        // We go left, left.
        if (leftLeftH >= leftRightH) {
            tempC = root;
            tempB = root->left;
            tempA = root->left->left;
            subT1 = tempA->right;
            subT2 = tempB->right;
        }

        // This is the left, right case.
        else {
            tempA = root->left;
            tempB = root->left->right;
            tempC = root;
            subT1 = tempB->left;
            subT2 = tempB->right;
        }
    }

    else {

        // Now, we must look at right's kids.
        int rightLeftH = root->right->left == NULL ? -1 : root->right->left->height;
        int rightRightH = root->right->right == NULL ? -1 : root->right->right->height;

        // This is the right left case.
        if (rightLeftH > rightRightH) {
            tempA = root;
            tempB = root->right->left;
            tempC = root->right;
            subT1 = tempB->left;
            subT2 = tempB->right;
        }

        // This is the right right case.
        else {
            tempA = root;
            tempB = root->right;
            tempC = root->right->right;
            subT1 = tempB->left;
            subT2 = tempC->left;
        }
    }

    // These are the same
    subT0 = tempA->left;
    subT3 = tempC->right;

    // Form our tree B at top.
    tempB->left = tempA;
    tempB->right = tempC;

    // Attach all subtrees.
    tempA->left = subT0;
    tempA->right = subT1;
    tempC->left = subT2;
    tempC->right = subT3;

    // Update heights, in this order.
    updateHeight(tempA);
    updateHeight(tempC);
    updateHeight(tempB);
}

// Prints both the preorder and post order traversals on separate lines of the tree pointed to by root.
void checkTree(avlnode* root) {
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n\n");
}

// Prints the preorder traversal of the tree rooted at root.
void preorder(avlnode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Prints the postorder traversal of the tree rooted at root.
void postorder(avlnode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Frees all the dynamically allocated memory in the tree pointed to by root.
void freeTree(avlnode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Returns 1 iff value is in the tree rooted at root.
int search(avlnode* root, int value) {

    // Can't find anything in an empty tree.
    if (root == NULL) return 0;

    // Go left.
    if (value < root->data)
        return search(root->left, value);

    // Go right.
    else if (value > root->data)
        return search(root->right, value);

    // Got it!
    else
        return 1;
}

// Returns 1 iff root has two non-NULL children.
int hasTwoChildren(avlnode* root) {
    return root->left != NULL && root->right != NULL;
}

// Returns 1 iff root is a leaf node.
int isLeafNode(avlnode* root) {
    return root->left == NULL && root->right == NULL;
}

// Pre-condition: left of root isn't NULL.
// Post-condition: Returns a pointer to the maximum value node in the left subtree of root.
avlnode* maxLeft(avlnode* root) {

    // This is the left child.
    avlnode* tmp = root->left;

    // This is how you get the max in a BST, iteratively.
    while (tmp->right != NULL)
        tmp = tmp->right;

    // Pointer to max value on left.
    return tmp;
}

// Wrapper function for delete.
avlnode* delValue(avlnode* root, int value) {

    // Find a pointer to a node storing value.
    avlnode* gone = findDelPtr(root, value);

    // No action taken if the value isn't in the tree.
    if (gone == NULL) return root;

    // Here we call the real delete function.
    return del(root, gone);
}

// Returns a pointer to a node storing value to delete (that doesn't have two children), or returns
// NULL if value isn't in the tree.
avlnode* findDelPtr(avlnode* root, int value) {

    // Not found!
    if (root == NULL) return NULL;

    // Recursively look left.
    if (value < root->data) return findDelPtr(root->left, value);

    // Recursively look right.
    else if (value > root->data) return findDelPtr(root->right, value);

    // woo hoo, we found it!
    else return root;
}

// Pre-condition: root points to the original root of the tree, ptrDel points to a node in the
//                tree pointed to by root and is the node to be deleted, and has at most 1 child.
avlnode* del(avlnode* root, avlnode* ptrDel) {

    // Just to be safe.
    if (root == NULL) return NULL;

    // This is safe.
    int delVal = ptrDel->data;

    // We've made it to the node.
    if (root == ptrDel) {

        // Easy case. Get rid of one node, return NULL.
        if (isLeafNode(ptrDel)) {
            free(ptrDel);
            return NULL;
        }

        // Annoying case: we don't physically delete this node.
        else if (hasTwoChildren(ptrDel)) {

            // Find max on left.
            avlnode* tmp = maxLeft(ptrDel);

            // Save this value to store in ptrDel at the end.
            int saveVal = tmp->data;

            // This deletes the real physical node we want to delete.
            ptrDel->left = del(ptrDel->left, tmp);

            // Now, write over the data since the old data here is what was really supposed to be deleted.
            ptrDel->data = saveVal;

            // Rebalance and update height.
            ptrDel = rebalance(ptrDel);
            updateHeight(ptrDel);

            // Still our root.
            return ptrDel;
        }

        // One child case is here.
        else {

            // Store the rest of the tree.
            avlnode* retVal = root->left != NULL ? root->left : root->right;

            // Free this node.
            free(root);

            // Pointer to tree to return.
            return retVal;
        }
    }

    // Go left case.
    if (delVal < root->data)
        root->left = del(root->left, ptrDel);

    // Right case.
    else
        root->right = del(root->right, ptrDel);

    // Here we rebalance this node before returning it.
    root = rebalance(root);

    // Update height, return root.
    updateHeight(root);

    // Finally!
    return root;
}
