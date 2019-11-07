#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // recebe como argumento os nomes de vários ficheiros e imprime o conteúdo de todos eles sequencialmente
    int i;
    FILE *f;
    for (i=1; i<argc; i++) {       
        f = fopen(argv[i], "r");

        char c;
        while ((c = fgetc(f)) != EOF) {
            printf("%c", c);
        }

        printf("\n");
        
    }

    return 0;
}