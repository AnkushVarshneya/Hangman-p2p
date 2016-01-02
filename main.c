/* This a a peer to peer based game of hangman, implemented using TCP sockets
 *
 * Usage:
 * for server mode: ./a4
 * for client mode: ./a4 "type ip address (in the format ###.###.###.###) here without the quotation marks."
 * the oracle may type in any word for guessing except "Guesser Pressed CTRL+C" 
 * as its used by the program to indicate a signal interupt from the guessers end.
 * Word entering by the oracle or guesser is handled by keyboard input
 * Game starts with oracle typing a word which will be hidden to the guesser.
 * Guesser tries to guess the word by inputting letters or the whole word itself
 * If the guesser gets more than 12 misses, then the oracle wins, otherwise the guesser wins.
 * The winner decides if the game should continue or end
 * If the game continues, if the guesser won, the two players switch roles 
 * If winner decided not to play again then the game ends for the winner,
 * but the loser's game process begain again with him waiting for a player to connect.
 *
 * Author: Ankush Varshneya
 * 
 * Version: 1.00
 * Revision Date: 02/12/2012
 */

#include "header.h"

/* main function
 * @param="argc" how many argument were passed
 * @param="argv" as array of arguments
 */
int main(int argc, char *argv[]) {
	// first turn is a normal turn
	turnStatus = NORMAL_TURN;
	
	// keeps result of quit type
	int result; 
	
	//if address was specified start in client mode else start in server mode
	if (argc > 1) {	
		while(1){ 
			// if ip specified run as client with server ip address			
			result = client(argv[1]);
			
			// if the quit type is a continue then turn in to server and wait for a client to connect to you.
			if(result==GAME_QUIT_CONTINUE){
				clearScreen();
				result = server();
			}
			else{
				break; // else break out of while loop and exit the program
			}
		}
	}
	else {	
		while(1) {
			// if no ip specified run as server
			result = server();
			
			// if the quit type is a continue then turn in to server and wait for a client to connect to you.
			if(result==GAME_QUIT_CONTINUE){
				clearScreen();
				result = server();
			}
			else{
				break; // else break out of while loop and exit the program
			}
		}	
	}
	
	// Games over so print out a notification to the user
	printf("Bye...\n");	
	return 0;
}