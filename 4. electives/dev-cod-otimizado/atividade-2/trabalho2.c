#include<stdio.h>
#include<stdlib.h>
#define ARR_SIZE 100000

/* Code to remove data from the processor caches. */
#define KB (1024)
#define MB (1024 * KB)
#define GB (1024 * MB)
#define LARGEST_CACHE_SZ (12 * MB)
static unsigned char dummy_buffer[LARGEST_CACHE_SZ];

void clean_cache() {
    unsigned long long i;
    for (i=0; i<LARGEST_CACHE_SZ; i++)
        dummy_buffer[i] += 1;
}


void bubble_sort(int* vet, int n){
    for(int j = n;j>0;j--){
        for(int i = 0;i<j-1;i++){
            if(vet[i]>vet[i+1]){
                int aux = vet[i+1];
                vet[i+1] = vet[i];
                vet[i] = aux;
            }
        }
    }
}

void insertion_sort(int* vet, int n){
    for(int i = 0;i < n-1; i++){
        if(vet[i]>vet[i+1]){
            int j = i; 
            while(j>=0 && vet[j+1] < vet[j]){
                int aux = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = aux;
                j--; 
            }
        }
    }
} 

void selection_sort(int *v, int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[min])
                min = j;
        }
        int aux=v[i];
        v[i]=v[min];
        v[min]=aux;
    }
}

int main() {
    int n = ARR_SIZE;
    int* a = (int*)malloc(sizeof(int)*n);
    int* b = (int*)malloc(sizeof(int)*n);
    int* c = (int*)malloc(sizeof(int)*n);
    srand(2);

    for (int i = 0; i < n; i++) {
        int randvalue = rand();
        a[i] = randvalue;
        b[i] = randvalue;
        c[i] = randvalue;
    }

    bubble_sort(a, n);
    clean_cache();
    insertion_sort(b, n);
    clean_cache();
    selection_sort(c, n);
    
    
    // for(int i = 0;i<n;i++){
    //     printf("%d ",a[i]);
    // }
    // printf("\n");
}