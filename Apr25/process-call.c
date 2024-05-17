#include <stdio.h>

int main(int argc, char** argv) {
  
  FILE* sort_pipe;

  char* chars[5] = {"And", "now", "for", "something", "different"};
  char* sort = "/usr/bin/sort";

  for (int i = 0; i < 5; i++) {
    printf("%s\n", chars[i]);
  }

  sort_pipe = popen(sort, "w");

  for (int i = 0; i < 5; i++) {
    fprintf(sort_pipe, "%s\n", chars[i]);
  }


  pclose(sort_pipe);

  return 0;
}
