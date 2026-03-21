#include <iostream>

#include "MatrixApplication.h"
#include "Matrix.h"
#include "Menu.h"
#include "ValidInput.h"

void runMatrixApplication(AddFunc addMatrices, MulFunc multiplyMatrices)
{
    while (true) {
        int choice = showMenu();

        if (choice == 3) {
            break;
        }

        if (choice == 1) {
            std::cout << "Enter rows of Matrix A: ";
            int rowsA = getValidInt();

            std::cout << "Enter cols of Matrix A: ";
            int colsA = getValidInt();

            std::cout << "Enter rows of Matrix B: ";
            int rowsB = getValidInt();

            std::cout << "Enter cols of Matrix B: ";
            int colsB = getValidInt();

            if (rowsA != rowsB || colsA != colsB) {
                std::cout << "Error: Addition requires same dimensions.\n";
                continue;
            }

            double **A = createMatrix(rowsA, colsA);
            double **B = createMatrix(rowsB, colsB);

            inputMatrix(A, rowsA, colsA);
            inputMatrix(B, rowsB, colsB);


            double **C = addMatrices(A, B, rowsA, colsA);

            printMatrix(C, rowsA, colsA);

            freeMatrix(A, rowsA);
            freeMatrix(B, rowsB);
            freeMatrix(C, rowsA);
        }
        else {
            std::cout << "Enter rows of Matrix A: ";
            int rowsA = getValidInt();

            std::cout << "Enter cols of Matrix A: ";
            int colsA = getValidInt();

            std::cout << "Enter rows of Matrix B: ";
            int rowsB = getValidInt();

            std::cout << "Enter cols of Matrix B: ";
            int colsB = getValidInt();

            if (colsA != rowsB) {
                std::cout << "Error: Multiplication requires colsA == rowsB\n";
                continue;
            }

            double **A = createMatrix(rowsA, colsA);
            double **B = createMatrix(rowsB, colsB);

            inputMatrix(A, rowsA, colsA);
            inputMatrix(B, rowsB, colsB);

        
            double **C = multiplyMatrices(A, B, rowsA, colsA, colsB);

            printMatrix(C, rowsA, colsB);

            freeMatrix(A, rowsA);
            freeMatrix(B, rowsB);
            freeMatrix(C, rowsA);
        }
    }
}
