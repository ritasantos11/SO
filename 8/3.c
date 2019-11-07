#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define READ 0
#define WRITE 1
#define LINESIZE 10000

int main(int argc, char* argv[]) {
    int n, r, fd[2];
    pid_t pid;
    char line[LINESIZE];
    
    if (pipe(fd) < 0) {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }
    
    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(EXIT_FAILURE);
    }
    
   else if (pid == 0) {
        printf("FILHO\n");
        close(fd[READ]);

        FILE *f = fopen(argv[1], "r");
        char c;
        int i=0;
        while ((c=fgetc(f)) != EOF) {
            line[i] = c;
            i++;
        }
       
        if ((r = write(fd[WRITE], line, strlen(line))) < 0) {
            fprintf(stderr, "Unable to write to pipe: %s\n", strerror(errno));
        }

        close(fd[WRITE]);

        exit(EXIT_SUCCESS);
    }

    else {
        close(fd[WRITE]);
        printf("PAI: ");
        fflush(stdout);

        if (waitpid(pid, NULL, 0) < 0) {
            fprintf(stderr, "Cannot wait for child: %s\n", strerror(errno));
        }
        
        if ((n = read(fd[READ], line, sizeof(line))) < 0 ) {
            fprintf(stderr, "Unable to read from pipe: %s\n", strerror(errno));
        }

        close(fd[READ]);
        
        write(STDOUT_FILENO, line, n);
       
        /* exit gracefully */
        exit(EXIT_SUCCESS);
    }
}