#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
    FILE *f = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "w");

    char line[1000];
    while (fgets(line, sizeof(line), f) != NULL) {
        fputs(line,f2);
    }

    return EXIT_SUCCESS;
}