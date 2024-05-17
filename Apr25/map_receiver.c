#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define MESSAGE_SIZE 128

int main(int argc, char** argv) {

  void* mmap_ptr;
  int fd = open("/tmp/mmap-test", O_RDWR, 0666);

  mmap_ptr = mmap(NULL, MESSAGE_SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);

  if (mmap_ptr == -1) {
    perror("Error getting mmap\n");
    return 1;
  }

  printf("mmap_ptr: %p\n", mmap_ptr);

  char msg[MESSAGE_SIZE];
  memcpy(msg, mmap_ptr, MESSAGE_SIZE);
  printf("Message received: %s\n", msg);
}
