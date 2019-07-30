#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>

const int size = 30;
char *buffer;

int kbhit(int fd)
{
  struct timeval tv;
  fd_set fds;

  tv.tv_sec = 0;
  tv.tv_usec = 0;

  FD_ZERO(&fds);
  FD_SET(fd, &fds);

  select(fd + 1, &fds, NULL, NULL, &tv);
  return FD_ISSET(fd, &fds);
}

void init_buffer()
{
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

int main()
{
  int stdin_fd = fileno(stdin);
  int kbhit_result = 0;
  const char *buf;

  init_buffer();
  while (!kbhit_result) {
    sleep(1);
    kbhit_result = kbhit(stdin_fd);
    if (kbhit_result == 0) {
      continue;
    }

    buf = read_stream(stdin);
    if (strcmp(buf, "q\n") == 0) {
      kbhit_result = 1;
    } else {
      fprintf(stdout, "Buffer %s", buf);
      kbhit_result = 0;
    }
  }

  free_buffer();
  return 0;
}
