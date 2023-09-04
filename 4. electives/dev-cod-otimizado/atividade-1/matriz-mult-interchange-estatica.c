#include <float.h> 
#include <stdio.h> 

/* Matrix size = MATRIX_N x MATRIX_N. */
#ifndef MATRIX_N
#define MATRIX_N 1000
#endif

/* Array data type. */
#ifndef DATATYPE
#define DATATYPE int
#endif

/* Matrices. */
DATATYPE ma[MATRIX_N][MATRIX_N];
DATATYPE mb[MATRIX_N][MATRIX_N];
DATATYPE mc[MATRIX_N][MATRIX_N];

int main() {
    for(int i = 0; i < MATRIX_N; i++) {
        for(int j = 0; j < MATRIX_N; j++) {
            ma[i][j] = i * MATRIX_N + j;
            mb[i][j] = i * MATRIX_N + j;
        }
    }

    for(int i = 0; i < MATRIX_N; i++) {
        for(int k = 0; k < MATRIX_N; k++) {
            for(int j = 0; j < MATRIX_N; j++) {
                mc[i][j] += ma[i][k] * mb[k][j];
            }
        }
    }

    return 0;
}