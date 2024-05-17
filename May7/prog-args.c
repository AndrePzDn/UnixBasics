#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  printf("argc: %d\n:", argc);

  for (int i = 0; i < argc; i++) {
    printf("argv[%d]: %s\n", i, argv[i]);
  }

  if (argc != 3) {
    printf("Invalid number of arguments\n");
    printf("Usage: \n\t./prog -p <port>\n");
    return 1;
  }

  if (strcmp(argv[1], "-p") != 0) {
    printf("Invalid argument\n");
    printf("Usage: \n\t./prog -p <port>\n");
    return 1;
  }

  int port = atoi(argv[2]);
  if (port == 0) {
    printf("Invalid port %s\n", argv[2]);
    return 1;
  }

  if (port < 1024 || port > 65535) {
    printf("Invalid port %d\n", port);
    return 1;
  }

  printf("Running at port %d\n", port);

  return 0;
}
