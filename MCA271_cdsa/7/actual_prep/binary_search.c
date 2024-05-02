#include"binary_search.h"
#include<stdio.h>
#include<stdlib.h>

Node *create_node (int num) {
    Node *newnode = (Node*) malloc (sizeof(Node));

    newnode->data = num;
    newnode->right = newnode->left = NULL;

    return newnode;
}

Node *enter_data (Node *root, int num) {

    if (root == NULL) {
        return create_node (num);
    }

    if (num < root->data) {
        root->left = enter_data (root->left, num);
    } else {
        root->right = enter_data (root->right, num);
    }

    return root;
}

void inorder_traversal (Node* root) {
    if (root == NULL) {
        return;
    }

    inorder_traversal (root->left);
    printf("%d ", root->data);
    inorder_traversal (root->right);

}

//              1
//             / \ 
//            2   3
//           / \   \
//          4   5   6 
//         /         \
//        7           9
//
//
int height (Node *root) {
    if (root == NULL) {
        return;
    }

    int left_height = height (root->left);
    int right_height = height (root->right);

    return (left_height > right_height) ? left_height + 1 : right_height + 1;
}

