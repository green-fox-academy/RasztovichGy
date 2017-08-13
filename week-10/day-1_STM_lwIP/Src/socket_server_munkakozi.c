/* Includes ------------------------------------------------------------------*/
#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"
#include "lwip/inet.h"			// struct in_addr definition at line 58
#include <stdio.h>			// printf
//#include <conio.h>			// kbhit

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define SERVER_IP           "10.27.6.128" 	//ide amit a board ki�r!
#define SERVER_PORT         54545
#define DATABUFFER			256
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
int serversocket;
int flag;	// a variable needed for error handling
struct sockaddr_in serveraddress;
struct sockaddr serveraddr;
int clientsocket;
struct sockaddr_in clientaddress;
struct sockaddr clientaddr;	// Client address structure
char buffer[DATABUFFER];	// buffer for in- and outgoing data
socklen_t clientaddresslength;	// Length of client address data structure
int receiveddatasize;		// Size of received message


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/



// TODO:
// Implement this function!
void socket_server_thread(void const *argument)
{
	/* Steps for making a server
 * Function descripitons: http://www.nongnu.org/lwip/2_0_x/group__socket.html#gade2b17671b5a4b18e941fbf7e1060310

0.	Server address structure initialization
1.  Create  a  TCP  socket  using  socket().
2.  Assign  a  port  number  to  the  socket  with  bind().
3.  Tell  the  system  to  allow  connections  to  be  made  to  that  port,  using  l i s t e n ( ) .
4.  Repeatedly  do  the  following:
		Call  accept ()  to  get  a  new  socket  for  each  client  connection.
		Communicate  with  the  client  via  that  new  socket  using  send()  and  recv().
		Close  the  client  connection  using  close().
   */

	// Server address structure initialization
	serveraddress.sin_family = AF_INET;                               // This address is an internet address
	serveraddress.sin_port = htons(SERVER_PORT);                      // Server port. htons function make it readable.
	serveraddress.sin_addr.s_addr = inet_addr(SERVER_IP);			  // server IP. inet_addr function makes the SERVER IP format readable.

	struct sockaddr *serveraddr = (struct sockaddr*)&serveraddress;
	//struct sockaddr *clientaddr = (struct sockaddr*)&clientaddress;
			/*	*serveraddr = (struct sockaddr *)&serveraddress;
			 * z�r�jel: castol�s, hogy a serveraddress var �s addr vart�pus �ssze legyen gy�rva,
	mert bind fgv argumentum�ba sockaddr strukt�pust kell adni, viszont IP c�met �s
	port sz�mot csak sockaddr_in strukt�rat�pusba tudok megadni.

	*addr: ez egy v�ltoz�, aminek �rt�ke van, de m�g nincs elnevezve.
	addr: egy pointer (olyan v�ltoz�, aminek az �rt�ke egy mem�riac�m)
	&serveraddress: a serveraddress v�ltoz� mem�riac�me (ami egy kor�bban m�r �rt�kkel felt�lt�tt strukt)
	 	 	 	 	 kb mint a servedress �rt�k�re mutat� pointer

	*addr = (struct sockaddr *)&serveraddress;
	*ptr = (vartype) *ptr

	L�NYEG�BEN:: �t kell alak�tani az IP c�met is tartalmaz� adatstrukt�r�t */
			/* felhaszn�lt adatstrukt�r�k
  struct sockaddr_in {	/sockets.h line70
  u8_t            sin_len;
  sa_family_t     sin_family;
  in_port_t       sin_port;
  struct in_addr  sin_addr;

  struct in_addr {  //inet.h line58
  in_addr_t s_addr;

  struct sockaddr {
  u8_t        sa_len;
  sa_family_t sa_family;
  char        sa_data[14];
}; */

	// Create server socket
	serversocket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);

	// Start binding the socket
	bind(serversocket, serveraddr, sizeof(*serveraddr));

	// Start listening
	listen(serversocket, 1);
		/* The listen function enables the socket socket to accept
 connections, thus making it a server socket.
The argument n specifies the length of the queue for pending
 connections. When the queue fills, new clients attempting to
 connect fail with ECONNREFUSED until the server calls accept to
 accept a connection from the queue. */

	// Feedback for the user
	printf("Server is initialized, waiting for connections at %s:%d\n", SERVER_IP, SERVER_PORT);

	// Receive data sent by client; store it; print it, send back to client
//	while (!kbhit()) {
	while (1) {
		clientaddresslength = sizeof(clientaddress);
		//clientsocket = accept(serversocket, clientaddr, sizeof(*clientaddr));
		clientsocket = accept(serversocket, (struct sockaddr*)&clientaddress, &clientaddresslength);
		receiveddatasize = recv(clientsocket, buffer, DATABUFFER, 0);
		printf("Received message: %s \n", buffer);
		send(clientsocket, buffer, receiveddatasize, 0);

	} while (receiveddatasize > 0);

	// Cleaning up used memory
	printf("Closing server and client socket\n");
	closesocket(clientsocket);
	closesocket(serversocket);
	while (1) {
			osDelay(10);
	}
}



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
