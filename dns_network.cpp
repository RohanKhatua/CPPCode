#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

struct hostent* my_gethostbyaddr(const char* addr, int len, int type) {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock." << std::endl;
        return nullptr;
    }

    struct in_addr ipAddr{};
    memcpy(&ipAddr, addr, len);
    struct hostent* host = gethostbyaddr(reinterpret_cast<const char*>(&ipAddr), len, type);
    if (host == nullptr) {
        std::cerr << "Failed to get host information for the address." << std::endl;
        WSACleanup();
        return nullptr;
    }

    WSACleanup();
    return host;
}

struct hostent* my_gethostbyname(const char* name) {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock." << std::endl;
        return nullptr;
    }

    struct hostent* host = gethostbyname(name);
    if (host == nullptr) {
        std::cerr << "Failed to get host information for " << name << std::endl;
        WSACleanup();
        return nullptr;
    }

    WSACleanup();
    return host;
}

int main() {
    //Getting the IP addresses for www.google.com
    std::cout << "Testing gethostbyname : "<<std::endl;
    const char* hostname = "www.google.com";
    struct hostent* host1 = my_gethostbyname(hostname);
    if (host1 != nullptr) {
        std::cout << "Hostname: " << host1->h_name << std::endl;

        std::cout << "IP Addresses:" << std::endl;
        char** p = host1->h_addr_list;
        while (*p != nullptr) {
            struct in_addr addr{};
            memcpy(&addr, *p, sizeof(struct in_addr));
            std::cout << inet_ntoa(addr) << std::endl;
            ++p;
        }
    }

    //Getting the hostname for a given IP Address
    std::cout << "Testing gethostbyaddr : "<<std::endl;
    const char* ipAddress = "202.165.107.50";
    // Example IP address (found by nslookup of www.yahoo.com)
    struct hostent* host2 = my_gethostbyaddr(ipAddress, sizeof(struct in_addr), AF_INET);
    if (host2 != nullptr) {
        std::cout << "Hostname: " << host2->h_name << std::endl;

        std::cout << "IP Addresses:" << std::endl;
        char** p = host2->h_addr_list;
        while (*p != nullptr) {
            struct in_addr addr{};
            memcpy(&addr, *p, sizeof(struct in_addr));
            std::cout << inet_ntoa(addr) << std::endl;
            ++p;
        }
    }

    return 0;
}