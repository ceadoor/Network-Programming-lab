
#include <sys/types.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main()
{
    int clientsocket;
    struct sockaddr_in serveraddr;
    socklen_t len;
    struct hostent *server;
    char message[50];
    clientsocket = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *)&serveraddr, sizeof(serveraddr));
    len = sizeof(serveraddr);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(5030);
    server = gethostbyname("127.0.0.1");
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, sizeof(server->h_addr));
    printf("\n[C]: PRESS ENTER TO START THE CONNECTION PROCESS.\n");
    fgets(message, 2, stdin);
    connect(clientsocket, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    printf("\n[C]: Sending message for server connection... \n");
    write(clientsocket, "hi i am client", sizeof("hi i am client"));
    printf("\n[C]: Message sent. \n");
    printf("\n[C]: Receiving message from server...\n");
    read(clientsocket, message, sizeof(message));
    printf("\n[C]: Message recieved: %s", message);
    close(clientsocket);
}