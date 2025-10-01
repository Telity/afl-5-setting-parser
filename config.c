#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct setting_t *setting_converter(char *line) {
    // TODO: Allokér en struct setting_t (vha. malloc())
    struct setting_t *setting = malloc(sizeof(struct setting_t));

    // Jeg skal bygge en lille parser der laver "name = Simon" om til to strings.

    // TODO: Find navnet på setting'en i *line
    setting->name = NULL; // skal ændres

    // TODO: Find værdien på setting'en i *line
    setting->value = NULL; // skal ændres

    // TODO: return den setting hvor felterne er sat
    return setting;
}

struct config_t *read_config(char *filename) {
    FILE *fr = fopen(filename, "r");
    if (fr == NULL) {
        fprintf(stderr, "Could not open %s\n", filename);
        return NULL;
    }

    // struct config_t stak_allokeret_config;

    struct config_t *config = malloc(sizeof(struct config_t));
    config->count = 0;

    char buf1[256];
    while (fgets(buf1, sizeof(buf1), fr) != NULL) {
        // fprintf(stdout, "Jeg fik: %s\n", buf1);
        char *buf2 = malloc(strlen(buf1) + 1);
        strcpy(buf2, buf1);
        // TODO: Den her linje virker ikke længere.
        config->lines[config->count] = buf2; // brug setting_converter()
        config->count += 1;
    }

    // return &stak_allokeret_config;
    return config;
}

void print_setting(struct setting_t *setting) {
    // TODO: Print en enkelt setting's name og value
}

void print_config(struct config_t *config) {
    for (int i = 0; i < config->count; i++) {
        print_setting(config->lines[i]);
    }
}

void free_config(struct config_t *config) {
    // TODO: Den behøver du ikke lave.
}
