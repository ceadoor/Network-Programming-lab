#include <sys/types.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int clientsocket, serversocket;
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t len;
    char message[50], writeMsg[20] = "hello client";
    serversocket = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(5030);
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    bind(serversocket, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    bzero((char *)&clientaddr, sizeof(clientaddr));
    len = sizeof(clientaddr);
    listen(serversocket, 5);
    printf("\n[S]: Waiting for client connectivity\n");
    clientsocket = accept(serversocket, (struct sockaddr *)&clientaddr, &len);
    printf("\n[S]: Client connected \n");
    printf("\n[S]: Reading message from client \n");
    read(clientsocket, message, sizeof(message));
    printf("\n[S]: The client has send: %s\n", message);
    printf("\n[S]: Sending message to client \n");
    write(clientsocket, writeMsg, sizeof(writeMsg));
    printf("\n[S]: Message sent. \n");
    close(clientsocket);
    close(serversocket);
}