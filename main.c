#include <stdio.h>
#include <stdlib.h>
#include "config.h"

int main(void) {
    // fprintf(stdout, "Hello, World!\n");
    // fprintf(stderr, "What what\n");

    // fw og fr er "file descriptors" eller "file handles"
    FILE *fw = fopen("hello.txt", "w");
    if (fw == NULL) {
        fprintf(stderr, "Could not open hello.txt\n");
        return EXIT_FAILURE;
    }

    fprintf(fw, "Hello, World!\nHow are you?\nI'm great!\n");
    fclose(fw);

    FILE *fr = fopen("hello.txt", "r");
    if (fr == NULL) {
        fprintf(stderr, "Could not open hello.txt\n");
        return EXIT_FAILURE;
    }

    // Stak-allokering
    char buf1[256];

    // Heap-allokering
    // char *buf2 = malloc(256);

    // sizeof(buf1) virker kun fordi buf1 er stak-allokeret
    while (fgets(buf1, sizeof(buf1), fr) != NULL) {
        fprintf(stdout, "Jeg fik: %s\n", buf1);
    }

    struct config_t *config = read_config("../config.ini");
    print_config(config);

    return 0;
}
