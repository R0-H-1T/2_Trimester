#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *left;
    struct Node *right;
    int data;
} Node;

Node *getNode (int data) {
    Node *newnode = (Node *) malloc (sizeof(Node));
    newnode->left = newnode->right = NULL;
    newnode->data = data;

    return newnode;
}

Node *createLevelOrder (int *arr, Node *root, int start, int end) {
    if (start < end) {
        root = getNode (arr[start]);
        root->left = createLevelOrder (arr, root->left, 2*start+1, end);
        root->left = createLevelOrder (arr, root->left, 2*start+1, end);
    }
    return root;
}

int height (Node *root) {
    if (root == NULL)
        return 0;
    
    int l_height = height (root->left);
    int r_height = height (root->right);

    return (l_height > r_height) ? (l_height + 1) : (r_height+1);
}

void levelOrderTraversal (Node *root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1){
        printf("%d", root->data);
    } else if (level > 1){
        levelOrderTraversal (root->left, level-1);
        levelOrderTraversal (root->right, level-1);
    }
}

int main () {
    Node *root = NULL;
    int arr[] = {1,2,3,45,90};
    root = createLevelOrder (arr, root, 0, sizeof(arr)/sizeof(int));
    
}