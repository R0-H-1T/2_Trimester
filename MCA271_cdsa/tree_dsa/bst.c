#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *left;
    int data;
    struct Node *right;
} Node;


Node *getNode (int data) {
    Node *newnode = (Node*) malloc (sizeof(Node));
    newnode->data = data;
    newnode->left = newnode->right =NULL;

    return newnode;
}

Node *addNode (Node *root, int data) {
    if (root == NULL)
        return getNode (data);
    
    if (data < root->data) {
        root->left = addNode (root->left, data);
    } else if (data > root->data) {
        root->right = addNode (root->right, data);
    }

    return root;
}


void inorder (Node *root) {
    if (root == NULL)
        return;
    
    inorder (root->left);
    printf("%d ", root->data);
    inorder (root->right);
}

Node *findMinNode (Node *root) {
    while (root->left != NULL){
        root = root->left;
    }

    return root;
}

Node* deleteNode (Node *root, int delNode) {
    if (root == NULL)
        return root;

    if (delNode < root->data) {
        root->left = deleteNode (root->left, delNode);
    } else if (delNode > root->data) {
        root->right = deleteNode (root->right, delNode);
    } else {
        if (root->left == NULL) {
            Node *temp = root->left;
            free(root->left);
            return temp;
        } else if (root->right == NULL){
            Node *temp = root->right;
            free(root->right);
            return temp;
        }

        Node *minNode = findMinNode (root->right);
        printf ("\nMin Node: %d\n", minNode->data);
        root->data = minNode->data;

        root->right = deleteNode (root->right, minNode->data);
    }

    return root;
}

int main () {
    char ch;
    Node *root = NULL;
    do {
        int data;
        printf ("Enter data: ");
        scanf ("%d", &data);
        getchar();
        if (root == NULL){
            root = addNode (root, data);
        }
        addNode (root, data);

        printf("Enter another node (y)?: ");
        scanf("%c", &ch);
        getchar();
    }while (ch == 'y');

    printf("\n\nInorder Traversal\n");
    inorder(root);

    int delNode;
    printf ("Enter the node to be deleted: ");
    scanf ("%d", &delNode);

    deleteNode (root, delNode);

    inorder(root);

    return 0;
}