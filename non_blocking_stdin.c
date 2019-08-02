#include <stdlib.h>
#include <string.h>
#include <sys/select.h>

#include "non_blocking_stdin.h"

static const int size = 30;
static char *buffer;
static struct timeval tv;
static fd_set fds;
static int fd = 0;

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

const char *read_stream(FILE *file, int removeNewline)
{
  memset(buffer, size, 0);

  int i = 0;
  char c = 0;

  while (c != '\n' && i < size - 1) {
    c = fgetc(file);
    if (c != '\n' || removeNewline == 0) {
      buffer[i] = c;
      i++;
    }
  }

  buffer[i] = '\0';

  return buffer;
}
