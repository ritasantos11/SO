#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// são criados 8 processos

int main(int argc, char* argv[]) {
    /* fork a child process */
    fork();
    // 2 processos


    /* fork another child process */
    // vai ser executado tanto pelo pai como pelo filho
    fork();
    // 4 processos


    /* and fork another */
    // faz fork aos 4 processos existentes
    fork();
    // 8 processos


    printf("%d\n", getpid());

    return EXIT_SUCCESS;
}