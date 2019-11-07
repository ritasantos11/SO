#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    list* l1 = list_new_random(3, 10);
    list_print(l1);
    
    list_add_first(4, l1);
    list_print(l1);
    
    int a = list_get_last(l1);
    printf("%d\n", a);

    list_remove_last(l1);
    list_print(l1);
    
    int size = list_size(l1);
    printf("%d\n", size);

    return 0;
}
