#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arrayRandomFill(double array[], int size)
{
    for(int i = 0; i < size; i++)
        array[i] = (double) rand() / RAND_MAX;
}

void matrixRandomFill(double *matrix[], int order)
{
    for(int i = 0; i < order; i++)
        arrayRandomFill(matrix[i], order);
}


void dgemm1(double *matrix1[], double *matrix2[], double *resultmatrix[], int order)
{
    for(int i = 0; i < order; i++)
    {
        for(int k = 0; k < order; k++)
        {
            for(int j = 0; j < order; j++)
                resultmatrix[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
}

void dgemm2(double matrix1[], double matrix2[], double resultMatrix[], int order, int blockSize)
{
    int i0, k0, j0;
    double *a0, *c0, *b0;
    for (int i = 0; i < order; i += blockSize) {
        for (int j = 0; j < order; j += blockSize) {
            for (int k = 0; k < order; k += blockSize) {
                for (i0 = 0, c0 = (resultMatrix + i * order + j), a0 = (matrix1 + i * order + k);
                     i0 < blockSize; ++i0, c0 += order, a0 += order) {
                    for (k0 = 0, b0 = (matrix2 + k * order + j); k0 < blockSize; ++k0, b0 += order) {
                        for (j0 = 0; j0 < blockSize; ++j0) {
                            c0[j0] += a0[k0] * b0[j0];
                        }
                    }
                }
            }
        }
    }
}

double simpleMultiplicationTimer(int order)
{
    double *matrix1[order];
    double *matrix2[order];
    double *resultMatix[order];

    for(int i = 0; i < order; i++)
    {
        matrix1[i] = malloc(order * sizeof(double));
        matrix2[i] = malloc(order * sizeof(double));
        resultMatix[i] = calloc(order, sizeof(double));
    }

    matrixRandomFill(matrix1, order);
    matrixRandomFill(matrix2, order);

    clock_t start = clock();
    dgemm1(matrix1, matrix2, resultMatix, order);
    clock_t finish = clock();

    for(int i = 0; i < order; i++)
    {
        free(matrix1[i]);
        free(matrix2[i]);
        free(resultMatix[i]);
    }
    return (double) (finish - start) / CLOCKS_PER_SEC;
}

double blockMultiplicationTimer(int order, int blockSize)
{
    int size = order * order;
    double *matrix1 = malloc(size * sizeof(double));
    double *matrix2 = malloc(size * sizeof(double));
    double *resultMatrix = calloc(size, sizeof(double));

    clock_t start = clock();
    dgemm2(matrix1, matrix2, resultMatrix, order, blockSize);
    clock_t finish = clock();

    free(matrix1);
    free(matrix2);
    free(resultMatrix);

    return (double) (finish - start) / CLOCKS_PER_SEC;
}

int main()
{
    int order, blockSize;
    printf("Enter matrix order:\n");
    scanf("%d", &order);

    //printf("String multiplication took: %f sec.\n", simpleMultiplicationTimer(order));
    //for(int blockSize = 1; blockSize <= order; blockSize *= 2)
        printf("Multiplication for %d blocks took: %f sec.\n", 512, blockMultiplicationTimer(order, 512));
    return 0;
}