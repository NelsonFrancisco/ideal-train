#include <stdlib.h>
#include <string.h>
#include <sys/select.h>

#include "non_blocking_stdin.h"

const int size = 30;
char *buffer;
struct timeval tv;
fd_set fds;
int fd = 0;

int kbhit()
{
  FD_CLR(fd, &fds);
  FD_SET(fd, &fds);
  select(fd + 1, &fds, NULL, NULL, &tv);
  return FD_ISSET(fd, &fds);
}

void init_buffer(int fd_to_check)
{
  fd = fd_to_check;
  tv.tv_sec = 0;
  tv.tv_usec = 0;

  buffer = (char *)calloc(size, sizeof(char));
}

void free_buffer()
{
  free(buffer);
}

const char *read_stream(FILE *file)
{
  int i = 0;
  char c;

  memset(buffer, size, 0);

  while (c != '\n' && i < size - 1) {
    c = fgetc(file);
    buffer[i] = c;
    i++;
  }

  buffer[i] = '\0';

  return buffer;
}