#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char* argv[]) {
    int fd[2];
    pid_t pid;
    
    char *command = argv[1];
    char *cmd[1000];
    char *cmd1[1000];
    char *cmd2[1000];

    cmd[0] = strtok(command, "|");

    int i=0;
    while ((cmd2[i] = strtok(NULL, " ")) != NULL) i++;

    cmd1[0] = strtok(cmd[0], " ");
    i=1;
    while ((cmd1[i] = strtok(NULL, " ")) != NULL) i++;
    
    
    if (pipe(fd) < 0) {
    /* pipe error */
    }

    if ((pid = fork()) < 0) {
    /* fork error */
    }

    if (pid > 0) {
        close(fd[0]);
        
        dup2(fd[1], STDOUT_FILENO); // stdout to pipe
        
        close(fd[1]);
        
        // parent writes to the pipe
        if (execvp(cmd1[0], cmd1) < 0) {
        /* exec error */
        }
    }
    
    else {
        close(fd[1]);
        
        dup2(fd[0], STDIN_FILENO); // stdin from pipe
        
        close(fd[0]);
        
        if (execvp(cmd2[0], cmd2) < 0) {
        /* exec error */
        }
    }
}