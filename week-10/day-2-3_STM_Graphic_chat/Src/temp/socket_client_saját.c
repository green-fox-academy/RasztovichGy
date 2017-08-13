/* TASK - Client side
The client connects to the server with a TCP socket and sends
touch screen data to the server.
*/

/* Includes ------------------------------------------------------------------*/
#include "socket_client.h"
#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"
#include "stm32746g_discovery_ts.h"
#include <string.h>
#include <stdio.h> 	// printf(), gets()

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define SERVER_IP         	"10.27.6.128" 	// Server Board's IP address
#define SERVER_PORT      	54545			// Common port between boards to connect !
#define SERVER_BUFF_LEN		64 				// length of msg buffer !
#define SERVER_QUEUE_SIZE	2

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
int clientsocket;					// var for client's socket (client socket descriptor)
struct sockaddr_in serveraddress;	// server's address
char msgtosend[SERVER_BUFF_LEN];	// a buffer containing the data to be transmitted.
char buffer[SERVER_BUFF_LEN];		// buffer for in- and outgoing data.
int receiveddatasize;				// Size of received message

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* How to create client
The  typical TCP client  goes  through  four  basic  steps:
1.   Create  a  TCP  socket  using  socket().
2.   Establish  a  connection  to  the  server  using  connect().
3.   Communicate  using  send()  and  recv().
4.   Close  the  connection  with  close().
*/

// TODO:
// Implement this function!
void socket_client_thread(void const *argument)
{
	// Create client socket
		clientsocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
		printf("Socket client - socket created\n");
	// Server address structure initialization
		serveraddress.sin_family = PF_INET;                   	// This address is an internet address
		serveraddress.sin_port = htons(SERVER_PORT);            // Server port. htons function make it readable.
		serveraddress.sin_addr.s_addr = inet_addr(SERVER_IP);	// server IP. inet_addr function makes the SERVER IP format readable.

	// Establish connection to the server
		connect(clientsocket, (struct sockaddr*)&serveraddress, sizeof(serveraddress));

	// Send string to the server
		printf("\nType message to send: ");
		gets(msgtosend);
		send(clientsocket, msgtosend, sizeof(msgtosend),0);

	// Receive message from server
		receiveddatasize = recv(clientsocket, buffer, sizeof(buffer), 0);
		printf("\nMessage from server: %s", buffer);
		wссссссссwссс

}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
