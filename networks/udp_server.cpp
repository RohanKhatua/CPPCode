#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
using namespace std;

#define PORT	 8080
#define MAXLINE 1024

int main() {
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    socklen_t len;
    int n;
    bool exitFlag = false;
    while (!exitFlag) {
        len = sizeof(cliaddr); //len is value/result
        n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';
        printf("Client: %s\n", buffer);

        string message;
        cout << "Enter a message to send to the client : ";
        getline(std::cin, message);

        if (message == "exit") {
            exitFlag = true;
            continue;
        }

        sendto(sockfd, message.c_str(), message.length(), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
        // cout << "Message sent to the client." << endl;

        // // cout << "Waiting for client's message..." << endl;
        // n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
        // buffer[n] = '\0';
        // printf("Client: %s\n", buffer);
    }

    close(sockfd);
    cout << "Connection closed. Server program terminated." << endl;
    return 0;
}
