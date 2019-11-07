#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    /* check if argv[2] can be opened and is readable */
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("%s: cannot open %s\n", argv[0], argv[2]);
        return EXIT_FAILURE;
    }

    char c;
    int countChar=0, lines=1;
    /* get one char at a time and print upper or lower case */
    while(fread(&c, 1, 1, fp) != 0) {
        if (c != '\n' && c != ' ')
            countChar++;
        else if (c == '\n')
            lines++;
    }
    
    /* close file */
    fclose(fp);

    printf("%d %d\n", countChar, lines);
    
    return EXIT_SUCCESS;
}