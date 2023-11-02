#include<stdio.h>
#include "hr.h"

void line(char c, int n){
    int i=0;
    while(i<n){
        printf("%c", c);
        i++;
    }
    printf("\n");
}
