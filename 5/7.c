#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    char buf[1024];
    char* command;
    pid_t pid;
    char *comandos[100];
    int i=1;
    
    /* do this until you get a ^C or a ^D */
    for( ; ; ) {
        /* give prompt, read command and null terminate it */
        fprintf(stdout, "$ ");

        if((command = fgets(buf, sizeof(buf), stdin)) == NULL)
            break;
        
        command[strlen(buf)-1]='\0';

        if (strcmp(command, "exit") == 0) {
            system("exit");
            return EXIT_SUCCESS;
        }
            

        comandos[i] = strdup(command);
        i++;
         
        /* call fork and check return value */
        if((pid = fork()) < 0) {
            fprintf(stderr, "%s: can’t fork command: %s\n", argv[0], strerror(errno));
            continue;
        }
        
        else if(pid == 0) {
            /* child */
           
            // cmd = ls -l
            char* cmd = command;
            char* agv[100];

            // agv[0] = ls
            agv[0] = strtok(cmd, " ");
            // agv[1] = -l
            agv[1] = strtok(NULL, " ");
            agv[2] = NULL;

            if (strcmp(agv[0], "myhistory") == 0) {
                for (int j=0; j<=atoi(agv[1]); j++) {
                    printf("history %s\n", comandos[i-1]);
                    i--;
                }
            }
            else {
                execvp(cmd, agv);
                /* if I get here "execlp" failed */
                fprintf(stderr, "%s: couldn’t exec %s: %s\n", argv[0], buf, strerror(errno));
                /* terminate with error to be caught by parent */
                exit(EXIT_FAILURE);
            }
        }

        if (strcmp(command, "myhistory") < 0)
            /* shell waits for command to finish before giving prompt again */
            if ((pid = waitpid(pid, NULL, 0)) < 0)
                fprintf(stderr, "%s: waitpid error: %s\n", argv[0], strerror(errno));
    }

   

    exit(EXIT_SUCCESS);
}