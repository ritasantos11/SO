/* definition of new type matrix */
typedef struct {
    int n;
    int m;
    int* vals;
} matrix;

/* definition of the matrix API */
matrix* matrix_new(int, int);
matrix* matrix_new_random(int, int, int, int);

void matrix_print(matrix*);
int matrix_get(int, int, matrix*);
void matrix_set(int, int, int, matrix*);

matrix* matrix_add(matrix *, matrix *);
matrix* matrix_sub(matrix *, matrix *);
matrix* matrix_mul(matrix *, matrix *);
matrix* matrix_trans(matrix *);