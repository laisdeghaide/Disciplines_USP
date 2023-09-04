#include <stdlib.h>
#include <string.h>
#include <stdio.h> 

/* Array data type. */
#ifndef DATATYPE
#define DATATYPE int
#endif


int main(int argc, char *argv[]) {
    const int MATRIX_N = argc > 1 ? atoi(argv[1]) : 1000;
    
    DATATYPE *ma = (DATATYPE *)malloc(MATRIX_N * MATRIX_N * sizeof(DATATYPE));
    DATATYPE *mb = (DATATYPE *)malloc(MATRIX_N * MATRIX_N * sizeof(DATATYPE));
    DATATYPE *mc = (DATATYPE *)calloc(MATRIX_N * MATRIX_N, sizeof(DATATYPE));
    
    
    for(int i = 0; i < MATRIX_N; i++) {
        for(int j = 0; j < MATRIX_N; j++) {
            ma[i * MATRIX_N + j] = i * MATRIX_N + j;
            mb[i * MATRIX_N + j] = i * MATRIX_N + j;
        }
    }

    for(int i = 0; i < MATRIX_N; i++) {
        for(int j = 0; j < MATRIX_N; j++) {
            for(int k = 0; k < MATRIX_N; k += 10) {
                mc[i * MATRIX_N + j] += ma[i * MATRIX_N + k] * mb[k * MATRIX_N + j];
                mc[i * MATRIX_N + j] += ma[i * MATRIX_N + k + 2] * mb[(k + 1) * MATRIX_N + j];
                mc[i * MATRIX_N + j] += ma[i * MATRIX_N + k + 1] * mb[(k + 2) * MATRIX_N + j];
                mc[i * MATRIX_N + j] += ma[i * MATRIX_N + k + 3] * mb[(k + 3) * MATRIX_N + j];
                mc[i * MATRIX_N + j] += ma[i * MATRIX_N + k + 4] * mb[(k + 4) * MATRIX_N + j];
                mc[i * MATRIX_N + j] += ma[i * MATRIX_N + k + 5] * mb[(k + 5) * MATRIX_N + j];
                mc[i * MATRIX_N + j] += ma[i * MATRIX_N + k + 6] * mb[(k + 6) * MATRIX_N + j];
                mc[i * MATRIX_N + j] += ma[i * MATRIX_N + k + 7] * mb[(k + 7) * MATRIX_N + j];
                mc[i * MATRIX_N + j] += ma[i * MATRIX_N + k + 8] * mb[(k + 8) * MATRIX_N + j];
                mc[i * MATRIX_N + j] += ma[i * MATRIX_N + k + 9] * mb[(k + 9) * MATRIX_N + j];
            }
        }
    }

    free(ma);
    free(mb);
    free(mc);

    return 0;
}