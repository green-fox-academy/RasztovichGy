/* Includes ------------------------------------------------------------------*/
#include "socket_client.h"
#include "socket_server.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "app_ethernet.h"
#include "lwip/sockets.h"
#include "stm32746g_discovery_ts.h"
#include <string.h>
#define DATA_BUFFER_SIZE    100
#define SERVER_IP           "10.27.6.13"
#define SERVER_PORT         54545

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*void handle_error(const char *error_string)
{
	printf("Error: %s\nError code: %d\n", error_string, WSAGetLastError());
	WSACleanup();
	printf("Press any key to exit from the program...");
	while (!kbhit());
	exit(EXIT_FAILURE);
}*/


/*void connect_to_server(int *client_sock, unsigned int server_port, char *server_ip)
{
	// Creating client socket
	(*client_sock) = socket(PF_INET, SOCK_STREAM, IPPROTO_IP);
	if (client_sock < 0)
		//handle_error("socket() ");
		terminate_thread();
		printf("nono");

	// Creating server address
	struct sockaddr_in addr_in;
	addr_in.sin_family = AF_INET;
	addr_in.sin_port = htons(server_port);
	addr_in.sin_addr.s_addr = inet_addr(server_ip);

	// Connecting the client socket to the server
	int connect_retval = connect(*client_sock, (struct sockaddr *)&addr_in, sizeof(addr_in));
	if (connect_retval < 0)
		//handle_error("connect() ");
		terminate_thread();

	printf("Connected to %s:%d\n", SERVER_IP, SERVER_PORT);
}*/

/*int send_message(SOCKET *socket)
{
	// Get the message from the user
	char msg[DATA_BUFFER_SIZE];
	printf("\nEnter the message to send: ");
	gets(msg);
	// Send the message to the servers
	int sent_bytes = send(*socket, msg, strlen(msg), 0);
	if (sent_bytes < 0)
		//handle_error("send() ");
		terminate_thread();

	return sent_bytes;
}*/

// TODO:
// Implement this function!

void terminate_thread()
{
	while (1)
		osThreadTerminate(NULL);
}

void socket_client_thread(void const *argument)
{
	printf("hello socket\n");
	// Connect to server
		//int client_socket;
		//connect_to_server(&client_socket, SERVER_PORT, SERVER_IP);
		int client_sock;
		//struct sockaddr_in server;
		client_sock = socket(AF_INET, SOCK_STREAM, 0);
		if (client_sock < 0) {
			//handle_error("socket() ");
			printf("nono");
			terminate_thread();
		}
		printf("int client\n");
		// Creating server address
		struct sockaddr_in addr_in;
		addr_in.sin_family = AF_INET;
		addr_in.sin_port = htons(54545);
		addr_in.sin_addr.s_addr = inet_addr(SERVER_IP);
		printf("Creating server address\n");

		// Connecting the client socket to the server
		int connect_retval = connect(client_sock, (struct sockaddr *)&addr_in, sizeof(addr_in));
		if (connect_retval < 0) {
			//handle_error("connect() ");
			printf("nonono2");
			terminate_thread();
		}

		//printf("Connected to %s:%d\n", SERVER_IP, SERVER_PORT);
		printf("connect ok");
		// Local variables used in the do-while loop
		int sent_bytes;
		TS_StateTypeDef TS_State;
		TS_StateTypeDef *TS_State_ptr = &TS_State;
		do {
			if (BSP_PB_GetState(BUTTON_KEY) == 1) {
			  BSP_LCD_Clear(LCD_COLOR_WHITE);
			}

			// Send data to the server
			BSP_TS_GetState(TS_State_ptr);
				if (TS_State.touchDetected == 1) {
					sent_bytes = send(client_sock, TS_State_ptr, sizeof(TS_State), 0);
					osDelay(50);
					BSP_LCD_FillCircle(TS_State_ptr->touchX[0], TS_State_ptr->touchY[0], 10);
				}
		} while (sent_bytes > 0);

		printf("Closing the socket...\n");
		closesocket(client_sock);
		printf("Cleaning up memory...\n");
		//WSACleanup();
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
