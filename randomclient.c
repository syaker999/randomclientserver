#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // define socket
    int sockfd;
    char buffer[256];

    struct sockaddr_in serv_addr = {AF_INET, htons(8888)};
    inet_pton(AF_INET, "192.168.85.132", &serv_addr.sin_addr);

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // connect to server
    connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    // read from server
    read(sockfd, buffer, 255);

    // print random number get from server
    printf("Random number: %s\n", buffer);

    // close socket
    close(sockfd);
    return 0;
}
 
