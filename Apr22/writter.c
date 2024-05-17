#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_MSG_SIZE 128
#define FIFO_NAME "/tmp/fifo_1"

int main() {
  char message[MAX_MSG_SIZE];
  int fd;

  mkfifo(FIFO_NAME, 0666);

  fd = open(FIFO_NAME, O_WRONLY);

  while (1) {
    printf("Enter a message: ");
    fgets(message, MAX_MSG_SIZE, stdin);
    write(fd, message, strlen(message) + 1);
  }

  close(fd);
  return 0;
}
