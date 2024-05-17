/*
- three levels of process
 p1 -> print PID, parent PID and counter every second staring from 0 until 10 (i.e. "main process PID(123), PPID(12), counter at 0")
    |
    p2 -> print PID, parent PID and counter every second starting from 10 until 20 (i.e. "child process PID(233), PPID(123), counter at 10")
       |
        p3 -> print PID, parent PID and counter every second starting from 20 until 40 (i.e. "child of child process PID(333), PPID(233), counter at 200")
      
p2 needs to wait for p3 to finish
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv) {

  for (int i = 0; i < 10; i++) {
    printf("Main Process PID: %d, PPID: %d, Counter: %d\n", getpid(), getppid(), i);
    sleep(1);
  }
  printf("Main Process ended\n");

  pid_t child = fork();

  if (child == 0) {
    pid_t child2 = fork();

    if (child2 == 0) {
      for (int i = 20; i < 40; i++) {
        printf("Child child Process PID: %d, PPID: %d, Counter: %d\n", getpid(), getppid(), i);
        sleep(1);
      }
      printf("Child child Process ended\n");
    } else {
      wait(NULL);
    }

    if (child == 0) {
    for (int i = 10; i < 20; i++) {
        printf("Child Process PID: %d, PPID: %d, Counter: %d\n", getpid(), getppid(), i);
        sleep(1);
      }
      printf("Child Process ended\n");
    } else {
      wait(NULL);
    }
  }
}
