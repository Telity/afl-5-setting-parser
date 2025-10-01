#ifndef FILESYS_CONFIG_H
#define FILESYS_CONFIG_H

struct config_t {};

struct config_t *read_config(char *filename);
void print_config(struct config_t *config);

#endif //FILESYS_CONFIG_H