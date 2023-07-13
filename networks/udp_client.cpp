#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
using namespace std;

#define PORT 8080
#define MAXLINE 1024

int main()
{
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    bool exitFlag = false;
    while (!exitFlag)
    {
        string message;
        cout << "Enter a message to send to the server : ";
        getline(cin, message);

        if (message == "exit")
        {
            exitFlag = true;
            continue;
        }

        sendto(sockfd, message.c_str(), message.length(), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));

        int n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, nullptr, nullptr);
        buffer[n] = '\0';
        cout << "Server: " << buffer << endl;
    }

    close(sockfd);
    cout << "Connection closed. Client program terminated." << endl;
    return 0;
}
