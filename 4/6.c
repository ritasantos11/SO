// gcc -Wall 6.c -o 6 -lbsd

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <bsd/stdlib.h>

int main (int argc, char** argv) {
    int len;
    struct dirent *p;
    DIR *q;
    
    if (argc != 2) {
        fprintf (stderr, "usage: %s dirname\n", getprogname());
        return EXIT_FAILURE;
    }

    q = opendir (argv[1]);
    if (q == NULL) {
        fprintf (stderr, "%s: Cannot open directory ’%s’\n",
        getprogname(), argv[1]);
        return EXIT_FAILURE;
    }

    printf ("%s/\n", argv[1]);
    
    p = readdir(q);
    while (p != NULL) {
        printf ("\t%s\n", p->d_name);
        p = readdir(q);
    }
    closedir (q);
    
    return EXIT_SUCCESS;
}