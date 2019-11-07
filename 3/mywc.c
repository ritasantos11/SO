#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char c;
    if (argc==3) {
        FILE *f = fopen(argv[2], "r");

        // contar caracteres
        int countChar=0;
        if (strcmp(argv[1], "-c") == 0) {
            while ((c = fgetc(f)) != EOF) {
                if (c != '\n' && c != ' ')
                    countChar++;
            }
            
            printf("NumChar: %d\n", countChar);
        }

        ////////////////////////////////////////////////////////////////////////////////
        
        // contar palavras
        int countPalavras=0;
        if (strcmp(argv[1], "-w") == 0) {
            int v=1;
            while ((c = fgetc(f)) != EOF) {
                if (v==1) {
                    fclose(f);
                    f = fopen(argv[2], "r");
                    v=0;
                }

                char palavra[100];
                fscanf(f, "%s", palavra);

                countPalavras++;
            }

            printf("NumPalavras: %d\n", countPalavras);
        }

        ///////////////////////////////////////////////////////////////////////////////////

        // contar linhas
        int countLinhas=1;
        if (strcmp(argv[1], "-l") == 0) {
            while ((c = fgetc(f)) != EOF) {
                if (c == '\n')
                    countLinhas++;
            }

            printf("NumLinhas: %d\n", countLinhas);
        }
    }

    ///////////////////////////////////////////////////////////////////////

    // contar caracteres
    else {
        FILE *f = fopen(argv[1], "r");
        int countChar=0;
        
        while ((c = fgetc(f)) != EOF) {
            if (c != '\n' && c != ' ')
                countChar++;
        }
            
        printf("NumChar: %d\n", countChar);
    }

    return 0;
}