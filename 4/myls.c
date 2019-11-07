#include <stdio.h>
#include <stdlib.h>
#include <bsd/stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

// SÓ FUNCIONA PARA FICHEIROS

int main(int argc, char* argv[]) {
    // permissoes qt de ficheiros na pasta user grup tamanho mes dia da ultima modificacao hora:minutos nome_file
    struct stat info;

    if(stat(argv[1],&info)==-1)
        printf("Error Occurred\n");
    
    // Permissões
    printf("-");
    printf((info.st_mode & S_IRUSR)? "r":"-");
    printf((info.st_mode & S_IWUSR)? "w":"-");
    printf((info.st_mode & S_IXUSR)? "x":"-");
    
    printf((info.st_mode & S_IRGRP)? "r":"-");
    printf((info.st_mode & S_IWGRP)? "w":"-");
    printf((info.st_mode & S_IXGRP)? "x":"-");
   
    printf((info.st_mode & S_IROTH)? "r":"-");
    printf((info.st_mode & S_IWOTH)? "w":"-");
    printf((info.st_mode & S_IXOTH)? "x":"-");
   
    
    // numero de ficheiros dentro
    // argv[1] é sempre uma ficheiro , logo é sempre 1
    printf(" 1 ");


    // nome do user
    struct passwd *pw = getpwuid(info.st_uid);
    // nome do group
    struct group  *gr = getgrgid(info.st_gid);

    printf("%s %s ", pw->pw_name, gr->gr_name);


    // tamanho do ficheiro
    printf("%ld ", info.st_size);


    // mes dia hora:minutos
    char date[100] = "";
    strftime(date, 100, "%b %d %H:%M", localtime(&info.st_mtime));
    printf("%s ", date);


    // nome do ficheiro
    printf("%s\n", argv[1]);

    return EXIT_SUCCESS;
}