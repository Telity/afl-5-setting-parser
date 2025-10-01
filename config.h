#ifndef FILESYS_CONFIG_H
#define FILESYS_CONFIG_H
#include <stddef.h>

struct setting_t {
    char *name;
    char *value;
};

struct config_t {
    struct setting_t *lines[20];
    size_t count;
};

// Sådan er det rigtigt:
// struct foo {};
// typedef struct foo foo_t;
// foo_t get_foos(void);

struct config_t *read_config(char *filename);
void print_config(struct config_t *config);
void free_config(struct config_t *config);

#endif //FILESYS_CONFIG_H