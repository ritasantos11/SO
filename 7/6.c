#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void handler_parent() {
    printf("%d: Parent received signal\n", getpid());
}

int main(int argc, char* argv[]) {
    pid_t pid;
    int cont=0;
    int n;
    scanf("%d", &n);
    
    if (signal(SIGUSR1, handler_parent) == SIG_ERR) {
        fprintf(stderr, "Can’t catch SIGUSR1: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) < 0) {
        printf("cannot fork()\n");
        return EXIT_FAILURE;
    }
    
    else if (pid > 0) {
        /* parent’s code */
        for (int i=1;i<=n;i++) {
            pause();
            printf("%d\n", i);
        }
    }
    
    else {
        /* child’s code */// envia o sinal ao pai
        for (int i=0; i<n; i++) {
            kill(getppid(), SIGUSR1);
            sleep(2);
        }

        pause();
    }
}