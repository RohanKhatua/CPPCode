#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
// #include <unistd.h>
#include <stdbool.h>

#define PORT 8080
#define MAX_MESSAGE_LENGTH 1024

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;

    struct sockaddr_in address;

    int addrlen = sizeof(address);
    char buffer[MAX_MESSAGE_LENGTH] = {0};
    char message[MAX_MESSAGE_LENGTH];

    // Create socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt,
                   sizeof(opt)) < 0)
    {
        perror("Setting Socket options failed");
        exit(EXIT_FAILURE);
    }

    //Define address parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to specified address and port
    if (bind(server_fd, (struct sockaddr *)(&address),
             sizeof(address)) < 0)
    {
        perror("Bind Failed");
        exit(EXIT_FAILURE);
    }
    // Listening for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("Listen Failed");
        exit(EXIT_FAILURE);
    }
    printf("Server is running. Waiting for incoming connections...\n");
    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("Accepting new connections failed");
        exit(EXIT_FAILURE);
    }
    // Print client address
    char clientAddress[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(address.sin_addr), clientAddress,
              INET_ADDRSTRLEN);

    printf("Client connected from address: %s\n", clientAddress);
    // Receiving and sending messages in a loop
    while (true)
    {
        // Receive message length from client
        int message_length;
        valread = read(new_socket, &message_length, sizeof(int));
        if (valread < 0)
        {
            printf("Failed to receive client message length\n");
            break;
        }
        // Check if client is exiting
        if (message_length == 0)
        {
            printf("Client Disconnected via exit\n");
            break;
        }
        // Receive client message
        valread = read(new_socket, message, message_length);
        if (valread < 0)
        {
            printf("Failed to receive client message\n");
            break;
        }
        message[message_length] = '\0';
        printf("Client: %s\n", message);

        // Server enters message
        printf("Server: ");
        fgets(buffer, sizeof(buffer), stdin);
        int buffer_length = strcspn(buffer, "\n"); //size of server message
        
        buffer[buffer_length] = '\0'; // replace newline with terminator

        // If server wishes to close the connection
        if (strcmp(buffer, "close") == 0)
        {
            printf("Server closed connection via close\n");
            break;
        }
        // Send the message length to the client
        int server_message_length = strlen(buffer);
        send(new_socket, &server_message_length, sizeof(int), 0);
        // Send the message to the client
        send(new_socket, buffer, server_message_length, 0);
     
    }
    // Close all sockets
    close(new_socket);
    close(server_fd);
    return 0;
}