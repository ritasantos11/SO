#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
    char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    char* p2 = (char*)malloc(MAX_STR_SIZE * sizeof(char));

    strcpy(p1, argv[1]);
    strcpy(p2, argv[2]);
    
    // recebe uma string na linha de comando e a transforma numa string equivalente mas
    // com todos os caracteres em minusculas
    int sizeP1 = strlen(p1);
    char* minusculas = (char*)malloc(sizeP1+1);
    int i, j, k;
    for (i=0; i<sizeP1; i++)
        minusculas[i] = tolower(p1[i]);

    printf("%s\n", minusculas);

/////////////////////////////////////////////////////////////////////////////////////////////////

    // recebe duas strings na linha de comando e indica se a primeira ocorre na segunda
    char* temp = strstr(p2, p1);
    /*if (temp==p2)
        printf("%s ocorre em %s\n", p1, p2);
    else
        printf("%s não ocorre em %s\n", p1, p2);
    */
   
    if (strstr(p2,p1)!=NULL)
        printf("sim\n");
    else
        printf("nao\n");
    
///////////////////////////////////////////////////////////////////////////////////////////////

    // recebe duas strings na linha de comando e indica quantas vezes a primeira ocorre na segunda
    int count=0;
    while ((p2 = strstr(p2, p1)) != NULL) {
        count++;
        p2++;
    }

    printf("%d\n", count);

    return EXIT_SUCCESS;
}