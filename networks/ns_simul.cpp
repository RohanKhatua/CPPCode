#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h> // Added this header file
#include <iostream>
using namespace std;

int main() {
    //in_addr is just a 32 bit integer similar to uint32_t
    //hostent represents an entry in the hosts database


    struct hostent *he;
    struct in_addr **addr_list;

    he = gethostbyname("www.google.com");
    if (he == NULL) {
        cout<<"gethostbyname() error\n";
        return 1;
    }

    //print host info

    cout<<"Host name: "<<he->h_name<<endl;
    //inet_ntoa takes a struct in_addr and returns an IP address in dotted-decimal format
    //so we type cast the first element of the list of addresses to struct in_addr
    //h_addr is just the first address in the list of addresses
    //can also be accessed via h_addr_list[0]
    // cout<<"First IP address: "<<inet_ntoa(*(struct in_addr *)he->h_addr)<<endl;
    cout<<"All addresses : "<<endl;
    //get the list of addresses for the host
    addr_list = (struct in_addr **)he->h_addr_list;
    //convert every address to dotted-decimal format and print it
    for (int i=0; addr_list[i] != NULL; i++) {
        cout<<inet_ntoa(*addr_list[i])<<" ";
        cout<<endl;
    }

    //convert an IP address in dotted-decimal format to struct in_addr

    //get the host name for a given IP address

    struct in_addr addr;
    inet_aton("142.251.42.36", &addr);


    struct hostent *he2;
    he2 = gethostbyaddr(&addr, sizeof(addr), AF_INET);    
    if (he2 == NULL) {
        cout<<"gethostbyaddr() error\n";
        return 1;
    }   
    cout<<"Host name: "<<he2->h_name<<endl;
}