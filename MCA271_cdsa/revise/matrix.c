#include "matrix.h"
#include<stdio.h>
#include<stdlib.h>
// #include "hr.h"


/**
 *  matrix      --->   [ptr1]  --->  [int1, int2, int3, ...]
               |       |       |  
               |       |       |
               |   [ptr2]  --->  [int1, int2, int3, ...]
               |       |       |
               |       |       |
               |   [ptr3]  --->  [int1, int2, int3, ...]
               |       |       |
               |       |       |
               |       ...
  matrix contains the address of the pointer that contains the array
  so *pointer will give the address of the first element in the array
  *(matrix + 1) + 0 will give the address of the 1 element in the 2nd pointer

  Another way of accessing the elements of 2d array are:
  matrix[i][j]
  Getting the elements are:
  &matrix[i][j]
*/

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
            scanf("%d", *(matrix + i) + j);
        }
        printf("\n");
    }
}

void display_matrix(int** matrix, int row, int col){
    if( matrix == NULL){
        fprintf(stderr, "Matrix not initialized");
        abort();
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ",*(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int** add_matrix(int** matrix1, int** matrix2, int** res, int row, int col){
    res = initialize_matrix(res, row, col);
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            res[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return res;
}

int** subtract_matrix(int** matrix1, int** matrix2, int** res, int row, int col){
    res = initialize_matrix(res, row, col);

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            res[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return res;
}

