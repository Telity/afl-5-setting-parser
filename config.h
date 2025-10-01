#ifndef FILESYS_CONFIG_H
#define FILESYS_CONFIG_H
#include <stddef.h>

struct config_t {
    char *lines[20];
    size_t count;
};

struct config_t *read_config(char *filename);
void print_config(struct config_t *config);

#endif //FILESYS_CONFIG_H