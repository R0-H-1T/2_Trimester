#include"matrix.h"
#include"hr.h"
#include<stdio.h>
#include<stdlib.h>



int main(int argc, char **argv){
    int **matrix1, **matrix2, **matrix3;
    int rows, cols;

    printf("%p\n", matrix1);

    printf("Enter rows and cols for matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("\nEnter matrix 1:\n");
    matrix1 = initialize_matrix(matrix1, rows, cols);
    get_matrix(matrix1, rows, cols);
    line('-', 6);
    display_matrix(matrix1, rows, cols);

    printf("\nEnter matrix 2:\n");

    matrix2 = initialize_matrix(matrix2, rows, cols);
    get_matrix(matrix2, rows, cols);
    line('-', 6);
    display_matrix(matrix2, rows, cols);

    printf("\nAddition of matrix:\n");
    matrix3 = add_matrix(matrix1, matrix2, matrix3, rows, cols);
    line('-', 6);
    display_matrix(matrix3, rows, cols);

    printf("\nSubtraction of matrix:\n");
    matrix3 = subtract_matrix(matrix1, matrix2, matrix3, rows, cols);
    line('-', 6);
    display_matrix(matrix3, rows, cols);

    delete_matrix(matrix1, rows, cols);
    delete_matrix(matrix2, rows, cols);
    delete_matrix(matrix3, rows, cols);

    return 0;
}
