#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (strcmp(argv[1], "-u") == 0) {
        // maiusculas
        FILE *f = fopen(argv[2], "r");
        char line[1000];
        char palavra[1000];
        while (fgets(line, sizeof(line), f) != NULL) {
            for (int i=0; i<sizeof(line); i++)
                palavra[i] = toupper(line[i]);

            printf("%s", palavra);
        }
    }
    
    
    return EXIT_SUCCESS;
}