#include "Addition.h"

extern double** addMatrices(double **A, double **B, int rows, int cols) {
    double **C = new double*[rows];

    for(int i = 0; i < rows; i++) {
        C[i] = new double[cols];
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            C[i][j] = *(*(A+i)+j) + *(*(B+i)+j);
        }
    }

    return C;
}