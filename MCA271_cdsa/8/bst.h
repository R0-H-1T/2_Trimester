#ifndef _BST_H
#define _BST_H

typedef struct Node {
    struct Node* left;
    int data;
    struct Node* right;
} Node;

Node* createNode(int );
Node* insertNode(Node* , int );
void inorderTraversal(Node* );


#endif

