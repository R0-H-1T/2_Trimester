#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node *left;
    struct Node *right;
    int data;
} Node;

Node *getNode (int n) {
    Node *newnode = (Node*) malloc (sizeof(Node));
    newnode->data = n;
    newnode->left = newnode->right = NULL;
    
    return newnode;
}

Node* createLevelOrderTree (int *arr, Node *root, int i, int n) {
    if (i < n) {
        root = getNode (arr[i]);

        root->left = createLevelOrderTree (arr, root->left, 2*i+1, n);
        root->right = createLevelOrderTree (arr, root->right, 2*i+2, n);
    }
    return root;
}

void preorder_traveral (Node *root) {
    if (root == NULL) {
        return;
    }
    printf ("%d ", root->data);

    preorder_traveral (root->left);
    preorder_traveral (root->right);
}


int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; ++i) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1; // Not found
}

Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    
    Node* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    // Find the index of the current element in inorder array
    int inIndex = findIndex(inorder, inStart, inEnd, root->data);

    // Recursively build left and right subtrees
    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

int main() {
    int arr[]  = {1,2,3,4,5};
    Node *root;
    root = createLevelOrderTree (arr, root, 0, sizeof(arr) / sizeof(int));

    preorder_traveral(root);

    // printf("root->data: %d", root->data);
    // printf("\nroot->left->data: %d", root->left->data);
    // printf("\nroot->right->data: %d", root->right->data);
    // printf("\nroot->left->left->data: %d", root->left->left->data);
    // printf("\nroot->left->right->data: %d", root->left->right->data);

    return 0;
    
}
