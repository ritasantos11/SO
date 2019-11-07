#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char pwd[100] = "";
    printf("%s\n", getcwd(pwd, 100));

    return EXIT_SUCCESS;
}