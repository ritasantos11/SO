#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

/* implementation of the matrix API */
matrix* matrix_new(int n, int m) {
    matrix* u = (matrix*) malloc(sizeof(matrix));
    
    u->n = n;
    u->m = m;
    u->vals = (double*) malloc ((u->n * u->m) * sizeof(double));
    
    return u;
}

matrix* matrix_new_random(int n, int m, double min, double max) {
    matrix* u = (matrix*) malloc(sizeof(matrix));
    
    u->n = n;
    u->m = m;
    u->vals = (double*) malloc ((u->n * u->m) * sizeof(double));
    
    int i, j;
    double range = max - min;
    double div = RAND_MAX / range;
    
    for(i = 0; i < u->n; i++)
        for(j = 0; j < u->m; j++)
            matrix_set(i, j, min + (rand() / div), u);
    
    return u;
}

void matrix_print(matrix* u) {
    int i, j;

    for (i=0; i<u->n; i++) {
        for (j=0; j<u->m; j++) 
            printf("%f ", matrix_get(i, j, u));
        printf("\n");
    }
}

double matrix_get(int i, int j, matrix* u){
    return *(u->vals + i * u->m + j);
}

void matrix_set(int i, int j, double val, matrix* u){
    int a, b;

    for (a=0; a<u->n; a++)
        for (b=0; b<u->m; b++)
            *(u->vals + i * u->m + j) = val;
}

matrix* matrix_add(matrix* u, matrix* v){
    int i, j;
    
    matrix* w = matrix_new(u->n, u->m);
    
    for (i = 0; i < u->n; i++ )
        for (j = 0; j < u->m; j++ )
            matrix_set(i, j, matrix_get(i, j, u) + matrix_get(i, j, v), w);
    
    return w;
}

matrix* matrix_sub(matrix* u, matrix* v){
    matrix* w = matrix_new(u->n,u->m);
    
    int i, j;

    for (i=0; i<u->n; i++)
        for (j=0; j<u->m; j++)
            matrix_set(i, j, matrix_get(i, j, u) - matrix_get(i, j, v), w);

    return w;
}

matrix* matrix_mul(matrix* u, matrix* v){
    matrix* w = matrix_new(u->n, v->m);

    int i, j, k;
    int valor = 0;

    for (i=0; i<u->n; i++)
        for (j=0; j<v->m; j++) {
            for (k=0; k<u->m; k++)
                valor += matrix_get(i, k, u) * matrix_get(k, j, v);
            matrix_set(i, j, valor, w);
        }

    return w;    
}

matrix* matrix_trans(matrix* u){
    matrix* w = matrix_new(u->m, u->n);

    int i, j;

    for (i=0; i<u->n; i++)
        for (j=0; j<u->m; j++)
            matrix_set(i, j, matrix_get(j, i, u), w);

    return w;
}