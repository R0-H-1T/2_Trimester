#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char string[64] = "1dead";

    printf("%d", strcmp(string, "1dead"));
    if( string == "dead" ) {
        printf("Its working");

    }

    return 0;
}