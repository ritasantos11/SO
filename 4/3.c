// gcc -Wall 3.c -o 3 -lbsd

#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <bsd/stdlib.h>
#include <pwd.h>

int main(int argc, char* argv[]) {
    struct stat info;
    char date[100] = "";
 
    if (argc<2) {
        fprintf(stderr, "usage: %s file\n", getprogname());
        return EXIT_FAILURE;
    }

    int i;
    for (i=1; i<argc; i++) {
        if (lstat(argv[i], &info) == -1) {
            fprintf(stderr, "fsize: Can’t stat %s\n", argv[i]);
            return EXIT_FAILURE;
        }

        printf("%s size: %d bytes, disk_blocks: %d\n", argv[i], (int)info.st_size, (int)info.st_blocks);

        // data da última modificação do ficheiro
        strftime(date, 100, "%d/%m/%Y", localtime(&info.st_mtime));
        printf("%s\n", date);

        // nome do utilizador dono do ficheiro
        struct passwd *pw = getpwuid(info.st_uid);
        printf("%s\n", pw->pw_name);
    }

    return EXIT_SUCCESS;
}