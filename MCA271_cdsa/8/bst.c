#include"bst.h"
#include<stdio.h>
#include<stdlib.h>

Node* createNode(int data) {
    Node* newNode = (Node*) malloc (sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Arg: root, data
Node* insertNode(Node* root, int data) {

    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// ---------------------------------- DELETION ----------------------------------------------
// finding the minimum node from the right subtree. 
// changing the value of the current node and deleting the min node found.



Node* findMin(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// ARGS: 
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    // if key is the root node
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        // Get the in-order successor (smallest in the right subtree)
        Node* temp = findMin(root->right);

        // Copy the in-order successor's value to this node
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


// --------------------------------- TRAVESALS --------------------------------------

void preorder_traveral (Node *root) {
    if (root == NULL) {
        return;
    }
    printf ("%d ", root->data);

    preorder_traveral (root->left);
    preorder_traveral (root->right);
}

void postorder_traversal (Node *root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);

    printf("%d ", root->data);
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}