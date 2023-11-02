#include "matrix.h"
#include<stdio.h>
#include<stdlib.h>
#include "hr.h"


int** initialize_matrix(int** matrix, int row, int col){
    matrix = (int**)malloc(sizeof(int*) * row);

    if( matrix == NULL){
        fprintf(stderr, "No space allocated for matrix");
        abort();
    }

    for(int i=0; i<row; i++){
        matrix[i] = (int *)malloc(sizeof(int) * col);
        if ( matrix[i] == NULL){
            fprintf(stderr, "Cannot allocate that much space.");
            abort();
        }
    }

    return matrix;
}

void delete_matrix(int** matrix, int row, int col){
    for(int i=0; i<col; i++){
        free(matrix[i]);
    }
    free(matrix);
}

void get_matrix(int** matrix, int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }
}

void display_matrix(int** matrix, int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

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
