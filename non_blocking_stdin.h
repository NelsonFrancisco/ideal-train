#include <stdio.h>

int kbhit(int fd);
void init_buffer();
void free_buffer();
const char *read_stream(FILE *file);