#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "non_blocking_stdin.h"

int main()
{
  int stdin_fd = fileno(stdin);
  int kbhit_result = 0;
  const char *buf;

  init_buffer(stdin_fd);
  while (!kbhit_result) {
    sleep(1);
    kbhit_result = kbhit();
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
