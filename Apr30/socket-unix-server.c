#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <string.h>

#define MAX_CONNECTION 5
#define MESSAGE_SIZE 256

int main(int argc, char *argv[]) {
  
  int server_socket_fd;
  char* socket_path = "/tmp/ipc_socket";

  int unlink_status = unlink(socket_path);
  if (unlink_status == -1) {
    perror("Error at unlink");
    return 7;
  }

  server_socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (server_socket_fd == -1) {
    perror("Error at socket init.");
      return 1;
  }

  struct sockaddr_un server_addr;

  server_addr.sun_family = AF_UNIX;
  strcpy(server_addr.sun_path, socket_path);


  int bind_status = bind(server_socket_fd,
       (struct sockaddr*) &server_addr, 
       sizeof(server_addr));
  if (bind_status == -1) {
    perror("Error at bind");
    return 2;
  }
  
  int listen_status = listen(server_socket_fd, MAX_CONNECTION);
  if (listen_status == -1) {
    perror("Error at listening");
    return 3;
  }

  struct sockaddr_un client_addr;
  int client_addr_size = sizeof(client_addr);
  int client_socket_fd = accept(server_socket_fd,
         (struct sockaddr*) &client_addr,
         (socklen_t *) &client_addr_size);
  if (client_socket_fd == -1) {
    perror("Error at requiest");
    return 4;
  }

  char buffer[MESSAGE_SIZE];
  int read_status = read(client_socket_fd, &buffer, MESSAGE_SIZE);
  if (read_status == -1) {
    perror("Error at read");
    return 5;
  }
  printf("Message from client: %s\n", buffer);

  int write_status = write(client_socket_fd, "Hello from server", 18);
  if (write_status == -1) {
    perror("Error at write");
    return 6;
  }

  close(client_socket_fd);
  close(server_socket_fd);

  return 0;

}
