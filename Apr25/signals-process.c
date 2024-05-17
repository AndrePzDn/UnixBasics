#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {

  int child_pid = fork();

  if (child_pid == 0) {
    // Child process
    int counter = 0;
    while(1) {
      printf("Child counter %d\n", counter++);
      sleep(1);
    }
  } else {
    // Parent process
    sleep(5);
    kill(child_pid, SIGKILL);
    printf("Child process killed\n");
    wait(NULL);
  }

  return 0;
}
