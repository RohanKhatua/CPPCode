#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
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

    //Create file
    FILE *client_side;
    client_side = fopen("client_side_file.txt", "w");

    while (true)
    {

        // Receive server's message length
        int server_message_length;
        valread = read(client_fd, &server_message_length,
                       sizeof(int));
        if (valread < 0)
        {
            printf("Failed to receive server message length\n");
            exit(EXIT_FAILURE);
        }
        // Receive server's message
        valread = read(client_fd, buffer, server_message_length);
        if (valread < 0)
        {
            printf("Failed to receive server message\n");
            exit(EXIT_FAILURE);
        }
        buffer[server_message_length] = '\0';
        if (strcmp(buffer, "//99")==0) break;
        
        fprintf(client_side, "%s\n", buffer);
    }

    fclose(client_side);

    close(client_fd);
    return 0;
}