#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // dada uma string e um ficheiro na linha de comando
    // imprima todas as ocorrências da string no ficheiro,
    // indicando a linha e a coluna do texto onde começam

    FILE *f = fopen(argv[2], "r");
    int v=1, linhas=1, colunas=1;
    char c;

    while ((c=fgetc(f)) != EOF) {
        if (v==1) {
            fclose(f);
            f = fopen(argv[2], "r");
            v=0;
        }

        else {
            if (c == '\n') {
                linhas++;
                colunas=1;
            }
            else
                colunas++;
        }
        
        char palavra[100];
        fscanf(f, "%s", palavra);
        int size = strlen(palavra);
        colunas += size;

        if (strcmp(argv[1], palavra) == 0) {
            printf("[%d:%d],", linhas, colunas-size);
        }
    }

    return 0;
}