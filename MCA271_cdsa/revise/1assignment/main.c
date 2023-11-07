#include<stdio.h>
#include<stdlib.h>
#include"cinema.h"

void cinema_menu(){
    // printf("******** WELCOME TO CINEMA DB ********");
    printf("\nSelect ");
    printf("\n1. Difference of rating between 2 cinemas.");
    printf("\n2. Average box office earnings of cinemas.");
    printf("\n3. Filter movie by year.");
    printf("\n4. Percentage difference between cinemas.");
    printf("\n5. Exit: ");
    printf("\nEnter choice: ");
}


int main(){
    int row, col;
    printf("\nEnter Cinema DB size in row and col: ");
    scanf("%d %d", &row, &col);
    
    Cinema **animation = create_db(animation, row, col);
    Cinema **hollywood = create_db(hollywood, row, col);

    get_movies(animation, row, col);
    get_movies(hollywood, row, col);


    printf("\nDisplaying animation\n ");
    display_movies(animation, row, col);
    printf("\nDisplaying hollywood\n ");
    display_movies(hollywood, row, col);
    
    // unsigned long int myearning = (*(animation + 0) + 0)->box_office_earnings - (*(hollywood + 0) + 0)->box_office_earnings;
    // myearning = ((*(hollywood + 0) + 0)->box_office_earnings / myearning) * 100;
    // printf("\n\nMy earnrings: %li", myearning);
    int ch;
    while(1){
        cinema_menu();
        scanf("%d", &ch);
        do_analysis(animation, hollywood, row, col, ch);
    }

    do_analysis(animation, hollywood, row, col, 2);

    // printf("\nDifferecnce between percentage  change earnings of 2 cinemas\n");
    // do_analysis(animation, hollywood, row, col, 2);

    delete_cinemaDB(animation, col);
    delete_cinemaDB(hollywood, col);
    return 0;
}