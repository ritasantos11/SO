#include <stdio.h>
#include <stdlib.h>
#include <bsd/stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
#include <string.h>

#define MAX_STR_SIZE 64

int isD(const char *path) {
    struct stat statbuf;
    if (stat(path,&statbuf)!=0)
    return 0;
    return S_ISDIR(statbuf.st_mode);
}
// FUNCIONA PARA FICHEIROS E DIRETÓRIOS

void permissoes(char* p1, struct stat info) {    
    DIR *q;
    q = opendir(p1);

    // directory
    if (isD(p1)) {
        printf("d");

        // owner
        printf((info.st_mode & S_IRUSR)? "r":"-");
        printf((info.st_mode & S_IWUSR)? "w":"-");
        printf((info.st_mode & S_IXUSR)? "x":"-");
        // group
        printf((info.st_mode & S_IRGRP)? "r":"-");
        printf((info.st_mode & S_IWGRP)? "w":"-");
        printf((info.st_mode & S_IXGRP)? "x":"-");
    // others
        printf((info.st_mode & S_IROTH)? "r":"-");
        printf((info.st_mode & S_IWOTH)? "w":"-");
        printf((info.st_mode & S_IXOTH)? "x":"-");

        

    }

    else
        printf("-");
    
    // owner
    printf((info.st_mode & S_IRUSR)? "r":"-");
    printf((info.st_mode & S_IWUSR)? "w":"-");
    printf((info.st_mode & S_IXUSR)? "x":"-");
    // group
    printf((info.st_mode & S_IRGRP)? "r":"-");
    printf((info.st_mode & S_IWGRP)? "w":"-");
    printf((info.st_mode & S_IXGRP)? "x":"-");
   // others
    printf((info.st_mode & S_IROTH)? "r":"-");
    printf((info.st_mode & S_IWOTH)? "w":"-");
    printf((info.st_mode & S_IXOTH)? "x":"-");

    closedir(q);
}

void numFiles(char* p1) {
    struct dirent *p;
    DIR *q;
    q = opendir(p1);

    if (q == NULL)
        // é um ficheiro, imprime 1
        printf(" 1 ");
    else {
        // é um diretório, imprime número de ficheiros que tem dentro
        int count=0;
        while ((p = readdir(q)) != NULL)
            if (p->d_type == DT_REG || p->d_type == DT_DIR)
                count++;

        printf(" %d ", count);
    }

    closedir(q);
}

void userName(struct stat info) {
    struct passwd *pw = getpwuid(info.st_uid);
    printf("%s ", pw->pw_name);
}

void groupName(struct stat info) {
    struct group  *gr = getgrgid(info.st_gid);
    printf("%s ", gr->gr_name);
}

void size(struct stat info) {
    printf("%ld ", info.st_size);
}

void datehour(struct stat info) {
    char date[100] = "";
    strftime(date, 100, "%b %d %H:%M", localtime(&info.st_mtime));
    printf("%s ", date);
}

void fileName(char* p1) {
    printf("%s\n", p1);
}

void print(struct stat info, char* p1) {    
    DIR *k;
    k = opendir(p1);

    struct dirent *p;

    if (k != NULL)  {
        printf("%s: \n", p1);
        p = readdir(k);

        while (p != NULL) {
            char* p2 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
            strcpy(p2, p->d_name);

            
            
            printf("\t%s ", p2);
            printf("\n");
            
            p = readdir(k);
        }
    }

    closedir(k);
}


int main(int argc, char* argv[]) {
    char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));
    strcpy(p1, argv[1]);

    struct stat info;
    if(lstat(p1,&info)==-1) {
        printf("Error Occurred\n");
        return EXIT_FAILURE;
    }

    // Permissões
    permissoes(p1, info);

    // numero de ficheiros dentro
    numFiles(p1);

    // nome do user
    userName(info);

    // nome do grupo
    groupName(info);

    // tamanho do ficheiro
    size(info);

    // mes dia hora:minutos
    datehour(info);

    // nome do ficheiro
    fileName(p1);
    
    // imprimi o que está dentro do diretório
    print(info, p1);

    return EXIT_SUCCESS;
}