#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdbool.h>
#define PORT 8080
#define MAX_MESSAGE_LENGTH 5000
int main(int argc, char const *argv[])
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[MAX_MESSAGE_LENGTH] = {0};
	char message[MAX_MESSAGE_LENGTH];
	// Create socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Socket Creation Failed");
		exit(EXIT_FAILURE);
	}
	// Set socket options
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt,
				   sizeof(opt)) < 0)
	{
		perror("Setting Socket options failed");
		exit(EXIT_FAILURE);
	}

	// Define address parameters
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	// Bind socket to specified address and port
	if (bind(server_fd, (struct sockaddr *)&address,
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
	inet_ntop(AF_INET, &(address.sin_addr), clientAddress, INET_ADDRSTRLEN);
	printf("Client connected from address: %s\n", clientAddress);

	// Read file contents and place it in a string 'buffer'
	FILE *textfile;

	textfile = fopen("/home/CPPCode/networks/server_side_file.txt", "r");
	if (textfile == NULL)
	{
		perror("File Does not exist");
		exit(EXIT_FAILURE);
	}

	char line[1000];

	while (fgets(line, 1000, textfile))
	{

		strcpy(buffer, line);
		buffer[strcspn(buffer, "\n")] = '\0'; // replace newline with terminator

		// Send the message length to the client
		int server_message_length = strlen(buffer);
		send(new_socket, &server_message_length, sizeof(int), 0);
		// Send the message to the client
		send(new_socket, buffer, server_message_length, 0);
	}

	//send final message
	char last_message[4] = "//99";
	int last_message_length =4;
	send(new_socket, &last_message_length, sizeof(int), 0);
	send(new_socket, last_message, last_message_length, 0);

	// Close all sockets
	close(new_socket);
	close(server_fd);
	return 0;
}