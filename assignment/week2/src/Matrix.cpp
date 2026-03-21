#include <iostream>
#include "Matrix.h"
#include "ValidInput.h"

double** createMatrix(int rows, int cols) {
    double **A = new double*[rows];
    for(int i = 0; i < rows; i++) {
        A[i] = new double[cols];
    }
    return A;
}

void inputMatrix(double **A, int rows, int cols) {
    std::cout << "Enter matrix values:\n";

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            A[i][j] = getValidInt();
        }
    }
}

void printMatrix(double **A, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void freeMatrix(double **A, int rows) {
    for(int i = 0; i < rows; i++) {
        delete[] A[i];
    }
    delete[] A;
}