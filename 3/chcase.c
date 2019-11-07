#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[2], "r");

    int i, v=1;
    char c;

    // letras maiusculas
    if (strcmp(argv[1], "-u") == 0) {
        FILE *newfM = fopen("maiu", "w");
        while ((c = fgetc(f)) != EOF) {
            if (v==1) {
                fclose(f);
                f = fopen(argv[2], "r");
                v=0;
            }
            
            else
                fputc(c, newfM);

            char palavra[100];
            fscanf(f, "%s", palavra);
            
            char maiuscula[100];
            for (i=0; i<strlen(palavra); i++)
                maiuscula[i] = toupper(palavra[i]);

            for (i=0; i<strlen(palavra); i++)
                fputc(maiuscula[i], newfM);
        }
    }

    // letras minusculas
    else if (strcmp(argv[1], "-l") == 0) {
        FILE *newfm = fopen("min", "w");
        v=1;
        while ((c = fgetc(f)) != EOF) {
            if (v==1) {
                fclose(f);
                fopen(argv[2], "r");
                v=0;
            }
            else
                fputc(c, newfm);

            char palavra[100];
            fscanf(f, "%s", palavra);
            
            char minuscula[100];
            for (i=0; i<strlen(palavra); i++)
                minuscula[i] = tolower(palavra[i]);

            for (i=0; i<strlen(palavra); i++)
                fputc(minuscula[i], newfm);
        }
    }

    else {
        FILE *newf = fopen("file", "w");
        v=1;
        while ((c = fgetc(f)) != EOF) {
            if (v==1) {
                fclose(f);
                fopen(argv[2], "r");
                v=0;
            }
            else
                fputc(c, newf);

            char palavra[100];
            fscanf(f, "%s", palavra);
            
            fputs(palavra, newf);
        }
    }

    return 0;
}