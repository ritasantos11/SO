#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[]) {
    pid_t pid;
    char *cmd;
    char buf[100];

    for(; ;) {
        cmd = fgets(buf, sizeof(buf),stdin);
        cmd[strlen(buf) - 1] = '\0';

        if (strcmp(cmd, "quit") == 0) {
            system("exit");
            return EXIT_SUCCESS;
        }

        /* fork a child process */
        if ((pid = fork()) < 0 ) {
            printf("%s: cannot fork()\n", argv[0]);
            return EXIT_FAILURE;
        }
        
        else if (pid == 0) {
            /* child process */
            if (execlp(cmd,cmd,NULL) < 0) {
                printf("bummer, did not exec %s\n", cmd);
                return EXIT_FAILURE;
            }
        }
        
        else {
            /* parent process */
            if (waitpid(pid, NULL, 0) < 0) {
                printf("%s: cannot wait for child\n", argv[0]);
                return EXIT_FAILURE;
            }
            
        }
    }
    return EXIT_SUCCESS;
}