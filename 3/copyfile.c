#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "w");
    
    char c;
    while ((c = fgetc(f)) != EOF)
        fputc(c, f2);

    return 0;
}