#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void sigkill_handler() {
  printf("SIGKILL handling\n");
}

void sigstop_handler() {
  printf("SIGSTOP handling\n");
}

void sigcont_handler() {
  printf("SIGCONT handling\n");
}

void signint_handler() {
  printf("Ctrl+C Detected\n");
}

int main(int argc, char** argv) {

  int child_pid = fork();

  signal(SIGINT, &signint_handler);

  if (child_pid == 0) {
    // Child process
    signal(SIGKILL, &sigkill_handler);
    signal(SIGSTOP, &sigstop_handler);
    signal(SIGCONT, &sigcont_handler);
    int counter = 0;
    while(1) {
      printf("Child counter %d\n", counter++);
      sleep(1);
    }
  } else {
    // Parent process
    sleep(5);
    kill(child_pid, SIGSTOP);
    sleep(5);
    kill(child_pid, SIGCONT);
    sleep(5);
    kill(child_pid, SIGKILL);
    printf("Child process killed\n");
    wait(NULL);
  }

  return 0;
}
