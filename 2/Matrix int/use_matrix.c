#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(int argc, char** argv) {
    matrix* m1 = matrix_new_random(3, 3, 0, 50);
    matrix* m2 = matrix_new_random(3, 3, 50, 80);

    matrix* sum = matrix_add(m1, m2);
    matrix* sub = matrix_sub(m1, m2);

    matrix* m3 = matrix_new_random(3, 2, 0, 80);
    matrix* mul = matrix_mul(m1, m3);

    matrix* trans = matrix_trans(m1);
    
    matrix_print(m1);
    printf("\n\n");
    matrix_print(m2);
    printf("\n\n");
    matrix_print(m3);
    printf("\n\n");
    matrix_print(sum);
    printf("\n\n");
    matrix_print(sub);
    printf("\n\n");
    matrix_print(mul);
    printf("\n\n");
    matrix_print(trans);
    printf("\n\n");

    return 0;
}