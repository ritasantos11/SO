#include <sys/wait.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SOCK0 0
#define SOCK1 1

/* by John Muir */
int main(int argc, char* argv[]) {
    int sockets[2];
    char buf[10240];
    pid_t pid;

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0) {
        perror("opening stream socket pair");
        exit(1);
    }

    if ((pid = fork()) < 0) {
        perror("fork");
        return EXIT_FAILURE;
    }

    else if (pid == 0) {
        /* this is the child */
        close(sockets[SOCK0]);
        
        if (read(sockets[SOCK1], buf, sizeof(buf)) < 0)
            perror("reading stream message");
        
        char line[10240];
        for (int i=0; i<sizeof(buf); i++) {
            line[i] = toupper(buf[i]);
        }
        
        if (write(sockets[SOCK1], line, sizeof(line)) < 0)
            perror("writing stream message");
        
        close(sockets[SOCK1]);
        
        /* leave gracefully */
        return EXIT_SUCCESS;
    }

    else {
        /* this is the parent */
        close(sockets[SOCK1]);

        FILE *f = fopen(argv[1], "r");
        char c;
        int i=0;
        while ((c = fgetc(f)) != EOF) {
            buf[i] = c;
            i++;
        }
        
        if (write(sockets[SOCK0], buf, sizeof(buf)) < 0)
            perror("writing stream message");
        
        if (read(sockets[SOCK0], buf, sizeof(buf)) < 0)
            perror("reading stream message");        
        
        close(sockets[SOCK0]);
       
        /* wait for child and exit */
        if (waitpid(pid, NULL, 0) < 0) {
            perror("did not catch child exiting");
            return EXIT_FAILURE;
        }

        write(STDOUT_FILENO, buf, strlen(buf));

        return EXIT_SUCCESS;
    }
}