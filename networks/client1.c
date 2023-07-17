#include <arpa/inet.h>
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
    int client_fd, valread;
    struct sockaddr_in serv_addr;
    char message[MAX_MESSAGE_LENGTH];
    char buffer[MAX_MESSAGE_LENGTH] = {0};
    // Create Socket
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket Creation Failed\n");
        exit(EXIT_FAILURE);
    }
    // Define server address parameters
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <=
        0)
    {
        perror("Invalid Addresss/Address not supported\n");
        exit(EXIT_FAILURE);
    }
    // Connect to server
    if (connect(client_fd, (struct sockaddr *)&serv_addr,
                sizeof(serv_addr)) < 0)
    {
        perror("Connection to server failed\n");
        exit(EXIT_FAILURE);
    }
    // Print server address
    char serverAddress[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(serv_addr.sin_addr), serverAddress,
              INET_ADDRSTRLEN);
    printf("Connected to server at address: %s\n",
           serverAddress);
    while (true)
    {
        // Client enters message
        printf("Client: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0';
        // Check if client wants to exit
        if (strcmp(message, "exit") == 0)
        {
            printf("Client Disconnected via exit\n");
            break;
        }
        // Send message length to the server
        int message_length = strlen(message);
        send(client_fd, &message_length, sizeof(int), 0);
        // Send message to server
        send(client_fd, message, message_length, 0);
        // Receive server's message length
        int server_message_length;
        valread = read(client_fd, &server_message_length,
                       sizeof(int));
        if (valread < 0)
        {
            printf("Failed to receive server message length\n");
            break;
        }
        // Receive server's message
        valread = read(client_fd, buffer, server_message_length);
        if (valread < 0)
        {
            printf("Failed to receive server message\n");
            break;
        }
        buffer[server_message_length] = '\0';
        printf("Server : %s\n", buffer);
    }
    close(client_fd);
    return 0;
}