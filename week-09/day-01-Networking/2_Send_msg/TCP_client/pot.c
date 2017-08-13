/* Task: Create a socket server
    - It listens on a predefined port
    - If a connection arrives
		+ Receives a voltage
		+ Prints the voltage on the screen
        + Sends back the following message to the client: ADC voltage has arrived
        + Waits until the connection closes (tries to receive a message)
    - Waits for another connection
***********************************/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define _WIN32_WINNT 0x0501
#include <winsock2.h>

// Private includes
#include <conio.h>
#include <math.h>

// Define IP address and port nr of the server
#define SERVER_IP "10.27.6.93" 	// Server's Wi-Fi IP address
#define SERVER_PORT 21212
#define SERVER_BUFFER_LEN 64
#define SERVER_QUEUE_SIZE 2

// Private variables
WSADATA wsadata;
SOCKET serversocket;
struct sockaddr_in serveraddress;
int flag;
SOCKET clientsocket;
struct sockaddr_in clientaddress;
int clientaddresslength;
char buffer[SERVER_BUFFER_LEN];
int receiveddatasize;

// Private functions
// Error handling
void handle_error(const char *error_string)
{
	printf("Error: %s\nError code: %d\n", error_string, WSAGetLastError());
	WSACleanup();
	printf("Press any key to exit from the program...");
	while (!kbhit());
	exit(EXIT_FAILURE);
}

int main()
{
	printf("TOTORO - Foundation exam\n");

	int iResult = WSAStartup(MAKEWORD(2, 2), &wsadata);
	if (iResult != NO_ERROR) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	// Server address structure initialization
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port = htons(SERVER_PORT);
	serveraddress.sin_addr.s_addr = inet_addr(SERVER_IP);

	// Create server socket
	serversocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	// Socket error handling
	if (serversocket < 0)
		handle_error("socket() ");
	printf("Socket server - socket created\n");

	// Start binding the socket
	flag = bind(serversocket, (struct sockaddr*)&serveraddress, sizeof(serveraddress));
	// Bindind error handling
	if (flag < 0)
		handle_error("bind() ");
	printf("Socket server - socket bind ok\n");

	// Start listening
	flag = listen(serversocket, SERVER_QUEUE_SIZE);
	// Listening error handling
	if (flag < 0)
		handle_error("listen() ");
	printf("Socket server - listening...\n");

	// User feedback from server initialization
	printf("Server is initialized, waiting for connections at %s:%d\n", SERVER_IP, SERVER_PORT);

	// Receive data sent by client; store it; print it, send back to client
	while (!kbhit()) {
		clientaddresslength = sizeof(clientaddress);

		// Accept connection
		clientsocket = accept(serversocket, (struct sockaddr*)&clientaddress, &clientaddresslength);
		// Connection error handling
		if (clientsocket < 0)
			handle_error("accept()");

		printf("Client connection accepted\n");

		do {
			receiveddatasize = recv(clientsocket, buffer, sizeof(buffer), 0);
			if (receiveddatasize == 0) {
				printf("Connection closed, waiting for an other connection!\n");
			} else if (receiveddatasize == SOCKET_ERROR) {
				printf("Client socket error, closing...\n");
				break;
			} else {
				buffer[receiveddatasize] = '\0';
				// Print received data
				printf("Received message: %s \n", buffer);
				// Send back received data to client
				send(clientsocket, buffer, receiveddatasize, 0);
			}
		} while (receiveddatasize > 0);

		// Close client socket
		closesocket(clientsocket);
		printf("Client socket closed.\n");
	}
	// Close server socket
	closesocket(serversocket);
	printf("Server socket closed.\n");

	// Cleaning up used memory
	WSACleanup();
	return 0;
}

