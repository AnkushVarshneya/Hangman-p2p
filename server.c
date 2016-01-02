/* Server functions
 * Revision Date: 2012-12-02
 * contains:
 * server();
 */
 
#include "header.h"

/* handles server mode
 * @param=""
 */
int server() {	
	int 	mySocket, clientSocket;
	struct 	sockaddr_in  myAddr, clientAddr;
	int 	i, addrSize;

	// create socket
	mySocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (mySocket < 0) {
		printf("eek! couldn't open socket\n");
		exit(-1);
	}
	
	// setup my server address
	memset(&myAddr, 0, sizeof(myAddr));
	myAddr.sin_family = AF_INET;
	myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	myAddr.sin_port = htons((unsigned short) MY_PORT);

	// bind my listen socket
	i = bind(mySocket, (struct sockaddr *) &myAddr, sizeof(myAddr));
	if (i < 0) {
		printf("eek! couldn't bind socket\n");
		exit(-1);
	}

	// listen for clients
	i = listen(mySocket, 5);
	if (i < 0) {
		printf("eek! couldn't listen\n");
		exit(-1);
	}
	
	// If no error promt user to wait for clients
	printf("Waiting for client to connect...\n");
	
	// Wait for connection request
	addrSize = sizeof(clientAddr);
	clientSocket = accept(mySocket, (struct sockaddr *) &clientAddr, &addrSize);
	if (clientSocket < 0) {
		printf("eek! couldn't accept the connection\n");
		exit(-1);
	}
	
	// The server is originally a oracle
	int decision = oracle(&clientSocket);
		
	while(1) {
		// if server won it stays the oracle
		if(decision == GAME_WON) {
			decision = oracle(&clientSocket); 
		}
		// if server lost its now the guesser
		else if(decision == GAME_LOST) {
			decision = guesser(&clientSocket);
		}
		// get out of loop
		else {
			break;
		}	
	}
	
	// close sockets
	close(mySocket);
	close(clientSocket);
	
	// return the type of quit ie. either continue as server or close
	return decision;
}
