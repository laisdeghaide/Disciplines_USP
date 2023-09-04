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
            for(int k = 0; k < MATRIX_N; k++) {
                mc[i * MATRIX_N + j] += ma[i * MATRIX_N + k] * mb[k * MATRIX_N + j];
            }
        }
    }

    free(ma);
    free(mb);
    free(mc);

    return 0;
}