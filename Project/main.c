/*-----------------------------------------------------------------------------
| main.c - Main entry point for the program.
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CONNECTIONS 30

void handle_client(int client_socket_fd) {
  char buffer[1024] = {0};
  int valread;
  valread = read(client_socket_fd, buffer, 1024);
  printf("%s\n", buffer);
  send(client_socket_fd, buffer, valread, 0);
}

int main(int argc, char* argv[]) {
  int server_socket_fd;
  server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket_fd == -1) {
    perror("Error at socket init");
    return 1;
  }

  struct sockaddr_in server_addr;

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  int addr_len = sizeof(server_addr);

  if (bind(server_socket_fd, (struct sockaddr*)&server_addr, addr_len) == -1) {
    perror("Error at bind");
    return 1;
  }

  if (listen(server_socket_fd, MAX_CONNECTIONS) == -1) {
    perror("Error max connections reached");
    return 1;
  }

  int client_socket_fd;
  
  while (1) {
    client_socket_fd = accept(
      server_socket_fd,
      (struct sockaddr*)&server_addr,
      (socklen_t*)&addr_len);

    if (client_socket_fd == -1) {
      perror("Error at accept");
      return 1;
    } 

    pid_t pid = fork();
    if (pid == 0) {
      close(server_socket_fd);
      handle_client(client_socket_fd);
      close(client_socket_fd);
      return 0;
    } else if (pid < 0) {
      perror("Error at fork");
      return 1;
    } else {
      close(client_socket_fd);
    }
  }

  close(server_socket_fd);

  return 0;
}
