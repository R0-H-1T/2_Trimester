#include<stdio.h>
#include<stdlib.h>
#include"cinema.h"

int main(){
    int row, col;
    printf("\nEnter Cinema DB size in row and col: ");
    scanf("%d %d", &row, &col);
    
    Cinema **cinema1 = create_db(cinema1, row, col);
    get_movies(cinema1, row, col);
    printf("\nDisplaying movies\n ");
    display_movies(cinema1, row, col);
    return 0;
}