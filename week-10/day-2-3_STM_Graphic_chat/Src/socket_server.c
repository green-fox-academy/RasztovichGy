/* TASK - server
 *
Server side
The server accepts connection from the client and receives touch
screen data via TCP sockets.
Based on the touch data it draws filled circles.
 */

/* Includes ------------------------------------------------------------------*/
#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"
#include "stm32746g_discovery_ts.h"
#include <string.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define SERVER_IP         	"10.27.6.19" 	// Server Board's IP address
#define SERVER_PORT      	54545			// Common port between boards to connect !
#define SERVER_BUFF_LEN		64 				// length of msg buffer !
#define SERVER_QUEUE_SIZE	2

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
int serversocket;
struct sockaddr_in serveraddress;
int clientsocket;
struct sockaddr_in clientaddress;
socklen_t clientaddresslength;	// Length of client address data structure
char buffer[SERVER_BUFF_LEN];	// buffer for in- and outgoing data. bufflen is defined in socket_server.h, value = 64
int receiveddatasize;			// Size of received message

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

// TODO:
// Implement this function!
void socket_server_thread(void const *argument)
{
	// Create server socket
	serversocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	printf("Socket server - socket created\n");
	// Server address structure initialization
	serveraddress.sin_family = PF_INET;                   	// This address is an internet address
	serveraddress.sin_port = htons(SERVER_PORT);            // Server port. htons function make it readable.
	serveraddress.sin_addr.s_addr = inet_addr(SERVER_IP);	// server IP. inet_addr function makes the SERVER IP format readable.

	// Start binding the socket
	bind(serversocket, (struct sockaddr*)&serveraddress, sizeof(serveraddress));
	printf("Socket server - socket bind ok\n");

	// Start listening
	listen(serversocket, SERVER_QUEUE_SIZE);
	printf("Socket server - listening...\n");

	// Feedback for the user
	printf("Server is initialized, waiting for connections at %s:%d\n", SERVER_IP, SERVER_PORT);

	// Receive data sent by client; store it; print it, send back to client
	while (1) {
		clientaddresslength = sizeof(clientaddress);
		clientsocket = accept(serversocket, (struct sockaddr*)&clientaddress, &clientaddresslength);
		printf("Socket server - connection accepted\n");
		do {
			receiveddatasize = recv(clientsocket, buffer, sizeof(buffer), 0);
			buffer[receiveddatasize] = '\0';	// basics concat.c !
			printf("Received message: %s \n", buffer);
			send(clientsocket, buffer, receiveddatasize, 0);
		} while (receiveddatasize > 0);

		// Cleaning up used memory
		printf("Closing client socket\n");
		closesocket(clientsocket);
	}
	// Close server socket
	closesocket(serversocket);

}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
