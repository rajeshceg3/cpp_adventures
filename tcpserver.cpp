#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
 
using namespace std;
 
int main()
{
    // New socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
	{
        cerr << "socket call failed" << endl;
        return -1;
    }
 
    // Bind the ip address and port to a socket
    sockaddr_in port_data;
    port_data.sin_family = AF_INET;
    port_data.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &port_data.sin_addr);
    bind(socket_fd, (sockaddr*)&port_data, sizeof(port_data));
 
    // Listen for connections on ths socket
    listen(socket_fd, SOMAXCONN);
 
    // Wait for a connection
    sockaddr_in client;
    int clientSocket = accept(socket_fd, (sockaddr*)&client, &sizeof(client));
 
	// Client implementation
    char host[NI_MAXHOST];      // Client name
    char service[NI_MAXSERV];   // Client service
 
    memset(host, 0, NI_MAXHOST); 
    memset(service, 0, NI_MAXSERV);
 
    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
        cout << host << " connected on port " << service << endl;
  
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }
 
    // Close socket_fd socket
    close(socket_fd);
 
    // Wait for incoming messages from client in a loop
    char buf[4096]; 
    while (true)
    {
        memset(buf, 0, 4096);
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            cerr << "Problem in recv call" << endl;
            break;
        }
 
        if (bytesReceived == 0)
        {
            cout << "Client connection dropped " << endl;
            break;
        }
 
        cout << string(buf, 0, bytesReceived) << endl;
 
        // Send the message back to client
        send(clientSocket, buf, bytesReceived + 1, 0);
    }
 
    // Close the socket
    close(clientSocket);
    return 0;
}
