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
        for(int j = 0; j < MATRIX_N; j++) {
            for(int k = 0; k < MATRIX_N; k += 10) {
                mc[i][j] += ma[i][k] * mb[k][j];
                mc[i][j] += ma[i][k + 1] * mb[k + 1][j];
                mc[i][j] += ma[i][k + 2] * mb[k + 2][j];
                mc[i][j] += ma[i][k + 3] * mb[k + 3][j];
                mc[i][j] += ma[i][k + 4] * mb[k + 4][j];
                mc[i][j] += ma[i][k + 5] * mb[k + 5][j];
                mc[i][j] += ma[i][k + 6] * mb[k + 6][j];
                mc[i][j] += ma[i][k + 7] * mb[k + 7][j];
                mc[i][j] += ma[i][k + 8] * mb[k + 8][j];
                mc[i][j] += ma[i][k + 9] * mb[k + 9][j];
            }
        }
    }

    return 0;
}