#include<stdio.h>
#include"cinema.h"
#include"dlinkedlist.h"
#include<stdlib.h>
#include<string.h>

int main(){



    Movie *ptr = getData();
    

    // printf("FROM MAIN:-> %s\n",ptr[0].movie_cast[2]);

    displayMovie(ptr);

    
    free(ptr);


    return 0;
}
