#include <signal.h>
#include <stdio.h>

main () {
    int pid1;
    int pid2;
    
    pid1 = fork();
    if (pid1 == 0) {
        // primeiro filho
        while (1) {
            printf ("pid1 is alive\n");
            sleep (1);
        }
    }
 
    pid2 = fork (); /* Second child */
    if (pid2 == 0) {
        while (1) {
            printf ("pid2 is alive\n");
            sleep (1);
        }
    }
    
    sleep (3);
    kill (pid1, SIGSTOP); /* Suspend first child */
    sleep (3);
    kill (pid1, SIGCONT); /* Resume first child */
    sleep (3);
    kill (pid1, SIGINT); /* Kill first child */
    kill (pid2, SIGINT); /* Kill second child */
}