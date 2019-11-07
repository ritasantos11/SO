// man 2 stat

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h> // open
#include <time.h>

int main(int agrc, char* argv[]) {
    // cria um novo ficheiro vazio com permissões 644 se não existir um ficheiro com o nome dado
    int f = open(argv[1], O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    /////////////////////////////////////////////////////////////////////////////////////////////////

    // altera a data de última alteração do ficheiro para a data actual, caso o ficheiro já exista
    struct stat info;
    if (lstat(argv[1], &info) == -1) {
            fprintf(stderr, "fsize: Can’t stat %s\n", argv[1]);
            return EXIT_FAILURE;
    }
    
    char date[100] = "";
    strftime(date, 100, "%d/%m/%Y", localtime(&info.st_mtime));
    printf("%s\n", date);

    // alterar data do ficheiro para data atual
    char command[256];
    snprintf(command, sizeof command, "touch -m %s", argv[1]);
    system(command);

    return EXIT_SUCCESS;
}