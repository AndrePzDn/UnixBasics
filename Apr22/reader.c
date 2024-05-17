#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_MSG_SIZE 128
#define FIFO_NAME "/tmp/fifo_1"

int main() {
  char message[MAX_MSG_SIZE];
  int fd;

  fd = open(FIFO_NAME, O_RDONLY);

  while (1) {
    read(fd, message, MAX_MSG_SIZE);
    printf("Received: %s\n", message);
  }

  close(fd);

  return 0;
}
