#include <stdio.h>

int kbhit();
void init_buffer(int fd_to_check);
void free_buffer();
const char *read_stream(FILE *file, int removeNewLine);
