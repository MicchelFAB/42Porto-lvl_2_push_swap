#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *arguments[argc];
    int i;

    for (i = 0; i < argc; i++) {
        arguments[i] = argv[i];
    }

    // now you can use the "arguments" array to access the command-line arguments
    // for example:
    printf("The first argument is: %s\n", arguments[i++]);

    return 0;
}

/* 
int main(int argc, char *argv[]) {
    char **arguments = argv;
    int i;

    // now you can use the "arguments" pointer to access the command-line arguments
    // for example:
    printf("The first argument is: %s\n", arguments[0]);

    return 0;
}
 */