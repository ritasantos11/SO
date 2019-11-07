#include <stdio.h>
int main() {
    int i, j, *p, *q;
    
    i = 5;
    p = &i;
    printf("i=%d, j=%d, p=%p, q=%p\n", i, j, p, q);
    *p = 7; // altera o i, porque p aponta para i
    printf("i=%d, j=%d, p=%p, q=%p\n", i, j, p, q);
    j = 3;
    p = &j;
    q = p;
    printf("i=%d, j=%d, p=%p, q=%p\n", i, j, p, q);
    p = &i;
    *q = 2;
    printf("i=%d, j=%d, p=%p, q=%p\n", i, j, p, q);

    return 0;
}