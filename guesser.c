/* Guesser functions
 * Revision Date: 2012-12-02
 * Contains:
 * guesser();
 * guesserPenalty();
 */

#include "header.h"

/* handles guesser code
 * @param="mySocket" this is the socket used to send/receive messages
 * @return = returns if how game ended, ie player won = GAME_LOST, player lost = GAME_WON, player quit = GAME_QUIT
 */ 
 int guesser(const int *mySocket) {
	clearScreen();
	printf("Waiting for new game to begin!\n");
	
 	char	wordsGuessed[MAX_GUESSED_BUFFER],
			wordHint[MAX_WORD_BUFFER],
			outgoingBuffer[MAX_INPUT_BUFFER],
			incomingBuffer[MAX_OUTPUT_BUFFER];

	int	bytesRcv, penalty;
	
	//make everything null
	wordsGuessed[0]		= 0;	// this contain the words guessed so far delimited by ","
	wordHint[0]		= 0;	// this contains the hints from the oracle
	outgoingBuffer[0]	= 0;	// this will contain outgoing messages that will be sent to the oracle
	incomingBuffer[0]	= 0;	// this will contain incoming messages sent from the oracle
	bytesRcv		= 0;	// this variables will be used to deal with the incoming message
 	penalty			= 0;	// keeps track of hang man	

	//set up interrupt handle for guesser ie. Ignore Ctrl+C
	signal(SIGINT, guesserPenalty);

	while (1) {
		// first check if game is over	
		if((penalty == GAME_WON)||(penalty == GAME_LOST)) {
			signal(SIGINT,SIG_DFL); //Restores Ctrl+C functionality
			if(penalty == GAME_LOST) {
				// listen for the actual word from the oracle
				bytesRcv = recv(*mySocket, incomingBuffer, sizeof(incomingBuffer),0);
				incomingBuffer[bytesRcv] = 0;
				strcpy(wordHint,incomingBuffer);				
				printf("Actual word was: %s\n",wordHint); //Print the actual word
				
				// listen for Winner Decision
				bytesRcv = recv(*mySocket, incomingBuffer, sizeof(incomingBuffer), 0);
				incomingBuffer[bytesRcv] = 0;
				
				// if the winner want to play another game return GAME_LOST so another game is played as guesser
				if(strcmp(incomingBuffer, "yes") == 0) {
					return GAME_LOST;
				}
				// else return GAME_QUIT_CONTINUE to quit the game ie the winner does not what to play again
				// but you as the loser must start the game again as a server and wait for a client to connect	
				return GAME_QUIT_CONTINUE;
			}
			else if(penalty == GAME_WON) {
				// if guesser won the game ask if it wants to play again
				printf("You won! Play Again? (yes or no):");
				gets(outgoingBuffer);				
				send(*mySocket, outgoingBuffer, strlen(outgoingBuffer), 0); // tell the loser of the winners decision
				
				// if it want to play another game return GAME_WON so another game is played as oracle
				if(strcmp(outgoingBuffer, "yes") == 0) {
					return GAME_WON;
				}
				return GAME_QUIT; // else return GAME_QUIT to quit the game ie the winner does not what to play again
			}			
		}
		
		// listen for the word you are given to guess
		bytesRcv = recv(*mySocket, incomingBuffer, sizeof(incomingBuffer), 0);
		incomingBuffer[bytesRcv] = 0;
		
		// if guess incorrect add a part to the hangman
		if((incomingBuffer[0]=='-')&&(incomingBuffer[1]=='1')) {
			penalty++;
			
			// if there is something after the -1 that means the oracle is trying to reveal a word so copy it over
			if(incomingBuffer[2]!=0) {
				strcpy(wordHint, &incomingBuffer[2]);
			}
		}
		//Otherwise, copy string over to the wordHint
		else{
			strcpy(wordHint, incomingBuffer);
		}		
		
		// the reason both are if(rather then if .. else if) is because: if the guesser ran 
		// out of all attempts and there was only one word remaining but the oracle pressed 
		// ctrl+c hence completing the word then the winning should be reassessed
		
		// if guesser makes more than 12 penalties, guesser lost
		if(penalty>12) {
			penalty = GAME_LOST;
		}
		//if guesser gets the word, guesser won
		if(wordComplete(wordHint)==WORD_COMPLETE) { 
			penalty = GAME_WON;
		}
		
		drawFigure(&penalty); // update hang man figure
		// Header
		printf("Guesser                        \n");
		printf("-------------------------------\n");
		printf("Words Guessed: %s\n", wordsGuessed);		
		printf("Guess this word: %s\n", wordHint);
		
		// If game is not over continue asking user for guess and then send the guess
		if((penalty != GAME_WON)&&(penalty != GAME_LOST)) {
			printf("Guess a letter or guess the whole word:");
			gets(outgoingBuffer);		
		
			// if we are on a interrupt turn ie the guesser pressed Ctrl+C
			// then sent oracle a '*', over writing what the guesser guessed this will 
			// automatically add a part to the hang man, else ask the guesser for a guess
			if(turnStatus == INTERRUPT_TURN) {
				// Ignore what the guesser guesser and replace with Guesser Pressed CTRL+C
				// its highly unlikly that the actual word if "Guesser Pressed CTRL+C" so the oracle will mark you wrong
				strcpy(outgoingBuffer, "Guesser Pressed CTRL+C"); 
				turnStatus = NORMAL_TURN; // make next turn normal
			}
			
			// if first word, start by copying else concatenate from what you have
			if(wordsGuessed[0]==0) {		
				strcpy(wordsGuessed, outgoingBuffer);
			}
			else {
				strcat(wordsGuessed, ", "); //delimit by a ","
				strcat(wordsGuessed, outgoingBuffer);
			}
			
			// send your guess to the oracle
			send(*mySocket, outgoingBuffer, strlen(outgoingBuffer), 0);
		}
	}
	// all cases should have been dealt with,if you got here something went wrong so quit game!
	return GAME_QUIT;
 }
 
/* handles CTRL+C from guesser
 * @param="x" what caused this signal, in this case its SIGINT
 * make global turnStatus INTERRUPT_TURN indicating that interupt has been detected
 */ 
void guesserPenalty(int x){
	printf("\nGuesser Penalty! Your guess will not be sent to the Oracle.\n");
	printf("One more body part to the hang man's noose, Press any key to continue...\n");
	turnStatus = INTERRUPT_TURN;
}
