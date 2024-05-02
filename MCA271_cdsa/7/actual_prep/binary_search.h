#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

typedef struct Node {
    struct Node *left;
    int data;
    struct Node *right;
} Node;

Node *enter_data (Node *, int );
Node *create_node (int num);
void inorder_traversal(Node* );


void height (Node *);

#endif
