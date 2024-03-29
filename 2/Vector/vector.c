#include <stdlib.h>
#include <math.h>
#include "vector.h"

vector* vector_new(double x, double y, double z) {
    vector* v = (vector*) malloc(sizeof(vector));

    v->x = x;
    v->y = y;
    v->z = z;

    return v;
}

vector* vector_add(vector* v1, vector* v2) {
    return vector_new(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
}

vector* vector_sub(vector* v1, vector* v2) {
    return vector_new(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
}

vector* vector_scale(double c, vector* v) {
    return vector_new(c * v->x, c * v->y, c * v->z);
}

vector* vector_vprod(vector* u, vector* v) {
    return vector_new((u->y * v->z) - (u->z * v->y), -((u->x * v->z) - (u->z * v->x)), (u->x * v->y) - (u->y * v->x));
}

double vector_sprod(vector* u, vector* v) {
    return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z)); 
}

double vector_mod(vector* v) {
    return sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
}