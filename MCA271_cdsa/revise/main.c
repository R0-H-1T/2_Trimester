#include"matrix.h"
#include"hr.h"
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char **argv){
    int row, col;
    line('-', 7);
    printf("\nEnter rows and cols of the matrix: ");
    scanf("%d %d", &row, &col);

    int** matrix;
    printf("%p",&matrix);


    matrix = initialize_matrix(matrix, row, col);
    printf("\n\nAddress of matrix: %ld\n\n", sizeof(int*));
    get_matrix(matrix, row, col);
    
    // for(int i=0; i<row; i++){
    //     printf("\nmatrix[%d]: %p,Size %ld",i, (matrix+i), sizeof(matrix+i));
        
    // }
    // printf("\n");
    display_matrix(matrix, row, col);
    delete_matrix(matrix, row, col);
    return 0;
}
