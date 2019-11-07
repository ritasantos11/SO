#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// são criados 16 processos

// os processos que podem comunicar entre si diretamente são processos c relacao pai/filho usando um pipe

int main(int argc, char* argv[]) {
    for (int i = 0; i < 4; i++)
        fork();

    printf("%d\n", getpid());
    
    return EXIT_SUCCESS;
}