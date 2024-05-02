#include<stdio.h>
#include<stdbool.h>
#include"helper.h"


void line(char ch, int n, bool newline) {
    printf("\n");
    for(int i=0; i<n; i++) {
        printf("%c", ch);
        getchar();
    }
    if(newline) {
        printf("\n");   
    }
}

void clear() {
    printf("\e[1;1H\e[2J");
}
