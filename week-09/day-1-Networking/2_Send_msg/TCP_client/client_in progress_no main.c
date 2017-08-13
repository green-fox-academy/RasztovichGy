/**********/
/* Client */
/**********/

/* Task description
    Create Server and Client Applications that send and receive messages.

    Create the server app that responds to the communication from the client app. It
    simply sends back what it has received.

    Create a client app that connects to your server app. It sends a message to the server,
    waits for the response and prints out the response. Yepp, the server app
    is running on your computer also, but the message goes out and comes in from the internet.
*/

/* Header includings
*/
#include <stdio.h>		// printf, sizeof
#include <stdlib.h>		// basics
#include <winsock2.h>	// socket(), connect(), recv(), send(), close()

/* Steps for creating a Client
ref: D:\GFA\Networking\Practical_Guide_for_Programmers.pdf
2.3 TCP Client (p29)

The  typical TCP client  goes  through  four  basic  steps:
1.   Create  a  TCP  socket  using  socket().
2.   Establish  a  connection  to  the  server  using  connect().
3.   Communicate  using  send()  and  recv().
4.   Close  the  connection  with  close().

We are now using windows, so we need to create socket according to winsock2.h
which is needed to be #included and initialised first of all.

Another briefing:
http://www.tenouk.com/Winsock/Winsock2example.html
Client side programs:
    Initialize WSA – WSAStartup().
    Create a socket – socket().
    Connect to the server – connect().
    Send and receive data – recv(), send(), recvfrom(), sendto().
    Disconnect – closesocket().
*/

/* Expected structure of the code
Create individual functions (which may outsourced to a separated .c file
later) and in the main() function just call them.
But, first of all, define the Client's IP and port no.
*/

// Define IP address and port no of the server
#define SERVER_IP "127.0.0.1"; 	// Localhost; check https://hu.wikipedia.org/wiki/Localhost
#define SERVER_PORT 10001;		// any free number beetween 1001-65535


// Declare variables
struct sockaddr_in myserversaddress;
char bufferfordatatotransfer[300]; // a buffer containing the data to be transmitted.
char bufferforincomingdata[300]; // a buffer to receive incoming the data



/* Init winsock
reference: http://www.winsocketdotnetworkprogramming.com/winsock2programming/winsock2advancedcode1.html
There is no need to deal with the method in deeper details.
That's the way it works. Apply it and do not give more effort to understand.
Another ref: http://ex3llo.tistory.com/47
*/
void wsa_Init()
{
	WSAData wsadata; //wsadata is a WSAData typed variable
	WSAStartup(MAKEWORD(2,2), &wsadata); // Initialize Winsock version 2.2
}

/* Create a socket
general format: int socket(address family, type, protocol); //PGdP.pdf p26
Declaration of socket() function:
typedef u_int	SOCKET; //line 44 @ winsock2.h; SOCKET is a var type, its an unsigned int
WINSOCK_API_LINKAGE SOCKET PASCAL socket(int,int,int); //line 553 @ winsock2.h
In winsock2.h, there is no description what are the 3 arguments.
So check https://msdn.microsoft.com/en-us/library/windows/desktop/ms740506(v=vs.85).aspx
SOCKET WSAAPI socket(
  _In_ int af, 			// The address family specification. Set to AF_INET (The Internet Protocol version 4 (IPv4) address family.)
  _In_ int type,		// The type specification for the new socket. Set to SOCK_STREAM (This socket type uses the TCP for the AF_INET address family.
  _In_ int protocol		// The protocol to be used. Set to IPPROTO_TCP. This is a possible value when the af is AF_INET and the type is SOCK_STREAM.
);
Give a name for the created socket while defining!
//ez amolyan int *ptr = b + c; formátum. Mivel késõbb kell a változó memcíme, egybõl a pointerét is megadom. De most nem írjuk elé hogy int mert a kód elején már beírtam hogy int a (helyett: line 57
*/
*myclientssocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

/* Fulfill sockaddr_in structure
sockaddr_in is a structure containing an internet address. It is the 2nd argument of connect() function.
Note there is no need to create struct, its done in winsock.h - just fill it up with values!
Struct def: see line 254 or https://msdn.microsoft.com/en-us/library/windows/desktop/ms740496(v=vs.85).aspx
struct sockaddr_in {
	short	sin_family;	// internet protocol, set to AF_INET
	u_short	sin_port;	// any value over 1000, we defined it in line 53
	struct	in_addr sin_addr;	// IP address of server, been defined in line 52
	char	sin_zero[8]; // no need for using this
}; */
myserversaddress.sin_family = AF_INET;
myserversaddress.sin_port = SERVER_PORT;
myserversaddress.in_addr sin_addr = SERVER_IP};


/* Connect to the server
format: int  connect(int  socket, struct  sockaddr  *foreignAddress, unsigned  int  addressLength)
Declaration of connect() function:
WINSOCK_API_LINKAGE int PASCAL connect(SOCKET,const struct sockaddr*,int); line 539
Function arguments: check https://msdn.microsoft.com/en-us/library/windows/desktop/ms737625(v=vs.85).aspx
int connect(
  _In_ SOCKET                s,		// A descriptor identifying an unconnected socket.
  _In_ const struct sockaddr *name,	// A pointer to the sockaddr structure to which the connection should be established.
  _In_ int                   namelen //The length, in bytes, of the sockaddr structure pointed to by the name parameter.
);
Returning value: If no error occurs, connect returns zero.
*/
int connect(*myclientssocket, &myserversaddress, sizeof(myserversaddress));


/*  Communicate  using  send()  and  recv() - send and receive data
general format
int  send(int  socket, const  v o i d   *msg, unsigned  int  msgLength, int flags)
int  recv(int  socket, void  *rcvBuffer, unsigned  int  bufferLength,  int flags)
Declaration of recv() function: WINSOCK_API_LINKAGE int PASCAL recv(SOCKET,char*,int,int); line 547
Declaration of send() function: WINSOCK_API_LINKAGE int PASCAL send(SOCKET,const char*,int,int); line 549
function recv() arguments: https://msdn.microsoft.com/en-us/library/windows/desktop/ms740121(v=vs.85).aspx
int recv(
  _In_  SOCKET s,		// The descriptor that identifies a connected socket:
  _Out_ char   *buf,	// A pointer to the buffer to receive the incoming data.
  _In_  int    len,		// The length, in bytes, of the buffer pointed to by the buf parameter.
  _In_  int    flags	// A set of flags that influences the behavior of this function. leave it! ok for 0.
);
The arguments of send() is the same.
difference is: *buf is A pointer to a buffer containing the data to be transmitted.
(https://msdn.microsoft.com/en-us/library/windows/desktop/ms740149(v=vs.85).aspx)
*/
int recv(myclientssocket, bufferforincomingdata, sizeof(bufferforincomingdata), 0);
int send(myclientssocket, bufferfordatatotransfer, sizeof(bufferfordatatotransfer), 0);

/* Disconnect - close socket
general format: int close(int socket); //PGdP.pdf p27
In winsock2: https://msdn.microsoft.com/en-us/library/windows/desktop/ms737582(v=vs.85).aspx
*/
int closesocket(myclientssocket);

/* Deinit wsa
*/
void wsa_Cleanup() // when the app finishes this wsa_clean is needed to be called
{
	WSACleanup();
}


int main()
{
    // Init wsa
    wsa_Init();

    // Create socket for client
    SOCKET myclientssocket;

    // Connect to server
    connect(*myclientssocket, &myserversaddress, sizeof(myserversaddress));

hm. Kazyé még nehezen érthetõ nekem. Mi lenne ha szarnék bele és mindent idefosnék a main-be?
és akkor mehetne minden elõzetes definiálás nélkül, egybõl meghívva a függvényt a szükséges paraméterekkel.



    return 0;
}






/*
Applied typedefs from  winsock2.h:

at initialising Winsock:
typedef struct WSAData {
	WORD	wVersion;
	WORD	wHighVersion;
	char	szDescription[WSADESCRIPTION_LEN+1];
	char	szSystemStatus[WSASYS_STATUS_LEN+1];
	unsigned short	iMaxSockets;
	unsigned short	iMaxUdpDg;
	char * 	lpVendorInfo;
} WSADATA;

Declaration of WSAStartup:
WINSOCK_API_LINKAGE int PASCAL WSAStartup(WORD,LPWSADATA); //line 591 @ winsock2.h










