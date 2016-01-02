/* Client functions
 * Revision Date: 2012-12-02
 * contains:
 * client();
 */
 
#include "header.h"

/* handles client mode
 * @param="server_ip" the ip address of the server specified as a command line argument 
 */
int client(char *server_ip) { 
	int 	mySocket;
	struct 	sockaddr_in  addr;
	int 	i, addrSize;
	
	// create socket
	mySocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (mySocket < 0) {
		printf("eek! couldn't open socket\n");
		exit(-1);
	}

	// setup address
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(server_ip);
	addr.sin_port = htons((unsigned short) MY_PORT);

	// connect to server
	i = connect(mySocket, (struct sockaddr *) &addr, sizeof(addr));
	if (i<0) {
		printf("client could not connect!\n");
		exit(-1);
	}
	
	// the client is originally the guesser
	int decision = guesser(&mySocket);
	
	while(1) {
		// if client won it's now the oracle
		if(decision == GAME_WON) {
			decision = oracle(&mySocket); 
		}
		// if client lost it stays the guesser
		else if(decision == GAME_LOST) {
			decision = guesser(&mySocket);
		}
		// get out of loop
		else {
			break;
		}		
	}
	
	// close the socket
	close(mySocket);
	
	// return the type of quit ie. either continue as server or close
	return decision;
}