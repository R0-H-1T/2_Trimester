#ifndef MATRIX_H
#define MATRIX_H

int** initialize_matrix(int** , int , int );

void delete_matrix(int** , int , int );

void get_matrix(int** , int , int );

void display_matrix(int** , int , int );

int** add_matrix(int** matrix1, int** matrix2, int** res, int row, int col);

int** subtract_matrix(int** matrix1, int** matrix2, int** res, int row, int col);

#endif