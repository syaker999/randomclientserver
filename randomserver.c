#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // define socket, new connection and port
    int sockfd, new_sock, port = 8888;
    char buffer[256];

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr = {AF_INET, htons(port), INADDR_ANY};
    printf("Server started at 192.168.85.132 \n");
    // bind socket to port
    bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    printf("Socket bind to port: %d \n", port);

    // listen for incoming connections
    listen(sockfd, 5);
    printf("Waiting for incoming connection \n");

    while(1) {

            struct sockaddr_in cli_addr;
            socklen_t clilen = sizeof(cli_addr);

            // accept new connection
            new_sock = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
            if (new_sock < 0) {
                printf("Error incoming connection \n");
                return -1;
            }
            else {
                printf("Connection accepted \n");
            }

            // random number generator
            int random_number = rand() % 900 + 100;
            printf("Random number been generated \n");

            // int to string converter
            sprintf(buffer, "%d", random_number);

            // send to client
            write(new_sock, buffer, strlen(buffer));
            printf("Packet Sent \n");

            // close connection
            close(new_sock);
            printf("Disconnected\n\n");

    }

    close(sockfd);

}
