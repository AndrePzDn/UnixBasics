#include <stdio.h>

int main(int argc, char** argv) {
  
  char buffer[128];
  FILE *ls_command_pipe, *sort_command_pipe;
  char* ls_command = "/usr/bin/ls";
  char* sort = "/usr/bin/sort";

  ls_command_pipe = popen(ls_command, "r");
  sort_command_pipe = popen(sort, "w");
  fgets(buffer, 128, ls_command_pipe);
  fputs(buffer, sort_command_pipe);

  while (fgets(buffer, 128, ls_command_pipe)) {
    fputs(buffer, sort_command_pipe);
  }

  pclose(ls_command_pipe);
  pclose(sort_command_pipe);

  return 0;
}
