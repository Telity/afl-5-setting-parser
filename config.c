#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct config_t *read_config(char *filename) {
    // TODO: Åbne filen med filnavnet 'filename'
    FILE *fr = fopen(filename, "r");
    if (fr == NULL) {
        fprintf(stderr, "Could not open hello.txt\n");
        return NULL;
    }

    // struct config_t stak_allokeret_config;

    struct config_t *config = malloc(sizeof(struct config_t));
    config->count = 0;

    // TODO: Loope over linjerne i filen
    char buf1[256];
    while (fgets(buf1, sizeof(buf1), fr) != NULL) {
        fprintf(stdout, "Jeg fik: %s\n", buf1);
        // TODO: Gemme hver linje i et array af linjer
        // TODO: - Lave en ny allokering for hver linje
        // TODO: - Den allokering kender jeg længden af: strlen(buf1) + 1
        char *buf2 = malloc(strlen(buf1) + 1);

        // TODO: - Kopiere indholdet fra buf1 over i den
        strcpy(buf2, buf1);

        // TODO: - Gemme denne allokering i config's lines array
        config->lines[config->count] = buf2;

        // TODO: - Forøge tællevariablen med 1 så næste linje bliver gemt rigtigt
        config->count += 1;
    }

    // return &stak_allokeret_config;
    return config;
}

void print_config(struct config_t *config) {
    // TODO: Loop over linjerne i config-objektet og print dem
}

void free_config(struct config_t *config) {
}
