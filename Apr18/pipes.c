#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char** argv) {
  pid_t child;
  int fd[2];

  char message[50] = "Hello father, I'm your child";
  char read_message[50];

  pipe(fd);

  child = fork();
  if (child == 0) {
    // Child
    printf("Child Process with pid %d and ppid %d\n", getpid(), getppid());

    close(fd[0]);
    write(fd[1], message, strlen(message));

    printf("End child process with pid %d and ppid %d\n", getpid(), getppid());
  } else {
    // Main
    printf("Main Process with pid %d\n", getpid());

    close(fd[1]);
    read(fd[0], read_message, sizeof(read_message));
    printf("Message from child: %s\n", read_message);

    printf("End Main process with pid %d\n", getpid());
  }

  return 0;
}
