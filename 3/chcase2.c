#include <stdio.h>
#include <ctype.h>
#include <string.h>

void maiuscula(char *file) {
    FILE *f = fopen(file, "r");
    char c;
    char u;
    while ((c = fgetc(f)) != EOF) {
        u = toupper(c);
        printf("%c", u);
    } 
}

void minuscula(char *file) {
    FILE *f = fopen(file, "r");
    char c;
    char m;
    while ((c = fgetc(f)) != EOF) {
        m = tolower(c);
        printf("%c", m);
    } 
}

int main(int argc, char *argv[]) {
    // um nome de um ficheiro e uma “flag”, e envie para o standard output o conte´udo do ficheiro dado:

    if (argc > 2) {
        // com todas as letras mai´usculas se a flag for -u;
        if (strcmp(argv[2], "-u") == 0) {
            maiuscula(argv[1]);
        }

        // com todas as letras minusculas se a flag for -l;
        else if (strcmp(argv[2], "-l") == 0)
            minuscula(argv[1]);
    }

    // inalterado, se nenhuma das anteriores
    else {
        FILE *f = fopen(argv[1], "r");
        char c;
        while ((c = fgetc(f)) != EOF) {
            printf("%c", c);
        }
    } 

    return 0;
}