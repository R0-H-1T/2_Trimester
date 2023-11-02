#include "matrix.h"
#include<stdio.h>
#include<stdlib.h>
// #include "hr.h"


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

void add_matrix(int** matrix1, int** matrix2, int** res, int row, int col){
    res = initialize_matrix(res, row, col);
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            res[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtract_matrix(int** matrix1, int** matrix2, int** res, int row, int col){
    if( res==NULL){
        res = initialize_matrix(res, row, col);
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            res[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

