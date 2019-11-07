#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PP_RD 0
#define PP_WR 1

int main(int argc, char* argv[]) {
    int n, r, fd[2];
    pid_t pid;
    char line[BUFSIZ];
    
    if (pipe(fd) < 0) {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }
   
    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(EXIT_FAILURE);
    }

    else if (pid > 0) {
        /* parent */
        close(fd[PP_RD]);

        FILE *f = fopen(argv[1], "r");
        char c;
        int i=0;
        while ((c=fgetc(f)) != EOF) {
            line[i] = c;
            i++;
        }
       
        if ((r = write(fd[PP_WR], line, strlen(line))) < 0) {
            fprintf(stderr, "Unable to write to pipe: %s\n", strerror(errno));
        }

        close(fd[PP_WR]);
        
        /* wait for child and exit */
        if (waitpid(pid, NULL, 0) < 0) {
            fprintf(stderr, "Cannot wait for child: %s\n", strerror(errno));
        }

        exit(EXIT_SUCCESS);
    }

    else {
        /* child */
        close(fd[PP_WR]);
        
        if ((n = read(fd[PP_RD], line, sizeof(line))) < 0 ) {
            fprintf(stderr, "Unable to read from pipe: %s\n", strerror(errno));
        }

        close(fd[PP_RD]);
        /* write message from parent */
        write(STDOUT_FILENO, line, strlen(line));
        
        /* exit gracefully */
        exit(EXIT_SUCCESS);
    }
}