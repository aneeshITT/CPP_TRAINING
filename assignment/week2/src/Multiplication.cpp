#include "Multiplication.h"

double** multiplyMatrices(double **A, double **B, int n, int m, int p) {
    double **C = new double*[n];

    for(int i = 0; i < n; i++) {
        C[i] = new double[p];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            C[i][j] = 0;
            for(int k = 0; k < m; k++) {
                C[i][j] += (*(*(A+i)+k)) * (*(*(B+k)+j));
            }
        }
    }

    return C;
}