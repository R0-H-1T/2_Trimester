

#include<stdio.h>
#include<string.h>

void compute_lsp (char *pattern, int M, int *lsp) {
    
    lsp[0] = 0;
    int i = 1;
    int j = 0;

    while (i < M) {
        if (pattern[i] == pattern[j]) {
            lsp[i] = j+1;
        } else {
            if (j != 0) {
                j = lsp[j-1];
            } else {
                lsp[i] = 0;
                i++;
            }
        }
    }
}

void kmp_search (char *text, char *pattern) {
    int M = strlen (text);
    int N = strlen(pattern);

    
    int lsp [M];

    compute_lsp(pattern, M, lsp);
    int i=0, j=0;
    while (i < M) {
        if (pattern[i] == pattern[j]) {
            i++; j++;
        }
        else {
                
        }
    }

}


int main() {
    char *text = "oniononionspl";
    char *patterns = "onions";

    kmp_search (text, pattern);

}
