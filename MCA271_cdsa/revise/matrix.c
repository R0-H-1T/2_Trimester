#include "matrix.h"
#include<stdio.h>
#include<stdlib.h>
#include "hr.h"


int** initialize_matrix(int** matrix, int row, int col){
    matrix = (int**)malloc(sizeof(int*) * row);

    if( matrix == NULL){
        fprintf(stderr, "No space allocated for matrix");
    }

    for(int i=0; i<col; i++){
        matrix[i] = malloc(sizeof(int) * col);
        if ( matrix[i] == NULL){
            fprintf(stderr, "Cannot allocate that much space.");
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
    matrix = initialize_matrix(matrix, row, col);
    get_matrix(matrix, row, col);
    display_matrix(matrix, row, col);

    return 0;
}
