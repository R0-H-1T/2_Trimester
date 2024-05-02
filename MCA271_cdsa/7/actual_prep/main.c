#include<stdio.h>
#include"binary_search.h"

int main (void) {
    Node *root = NULL;
    int n;
    char ch;
    do {

        printf ("Enter the data value: ");
        scanf ("%d", &n);
        getchar();
        root = enter_data (root, n);
        printf ("Enter another data? (y/n)");
        scanf ("%c", &ch);
    } while (ch == 'Y' || ch == 'y');

    printf ("Inorder traversal: ");
    inorder_traversal(root);

    return 0;
}
