#ifndef MATRIX_H
#define MATRIX_H

double** createMatrix(int rows, int cols);
void inputMatrix(double **A, int rows, int cols);
void printMatrix(double **A, int rows, int cols);
void freeMatrix(double **A, int rows);

#endif