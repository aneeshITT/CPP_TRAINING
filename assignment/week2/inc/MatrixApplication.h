#ifndef MATRIX_APPLICATION_H
#define MATRIX_APPLICATION_H

typedef double** (*AddFunc)(double**, double**, int, int);
typedef double** (*MulFunc)(double**, double**, int, int, int);

void runMatrixApplication(AddFunc addMatrices, MulFunc multiplyMatrices);

#endif
