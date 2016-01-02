/* Oracle functions:
 * Revision Date: 2012-12-02
 * contains:
 * oracle();
 * oraclePenalty();
*/

#include "header.h"

/* handles oracle code
 * @param="mySocket" this is the socket used to send/recive messages
 * @return = returns if how game ended, ie player won = GAME_LOST, player lost = GAME_WON, player quit = GAME_QUIT
 */ 
 int oracle(const int *mySocket) {
	char	wordsGuessed[MAX_GUESSED_BUFFER],
			actualWord[MAX_WORD_BUFFER],
			wordHint[MAX_WORD_BUFFER],
			outgoingBuffer[MAX_OUTPUT_BUFFER],
			incommingBuffer[MAX_INPUT_BUFFER];

	int bytesRcv, penalty, result;
	
	//make everything null
	wordsGuessed[0] 	= 0;	// this contain the words guessed so far delimited by ","
	actualWord[0] 		= 0;	// this will word the actual word
	wordHint[0]			= 0;	// this contains the hints
	outgoingBuffer[0] 	= 0;	// this will contain outgoing messages to sent to the guesser
	incommingBuffer[0] 	= 0;	// this will contain incomming messages sent from the guesser
	bytesRcv			= 0; 	// this variables will be used to deal with the incomming message
	penalty				= 0; 	// keeps track of hang man
	result				= 0;	// keeps tract of if guesser made correct guess and for error checking of actualword input
	
	char notToBeUsed[] = "Guesser Pressed CTRL+C\0"; // this string indacates what can not be used as guess word
	
	// Title
	drawFigure(&penalty);
	// Header
	printf("Oracle                         \n");
	printf("-------------------------------\n");
	
	while(1) {
		// prompt oracle for guess word
		printf("Please type word for guesser:");
		gets(actualWord);
		
		// do some error on the actualWord inputed as it call not be "Guesser Pressed CTRL+C" as that word
		// is used by the program to indicate a signal interupt from the guessers end, tell the user to enter another word
		result = (strcmp(actualWord, notToBeUsed));
		if(result == 0) {
			printf("Error: \"%s\" can not be used as the guess word\n", notToBeUsed);
			printf("As its used by the program to indicate a signal interupt from the guessers end\n");
		}
		else{
			break; // if the actual word is passed error checking than get out of the while loop
		}
	}
	
	// initilize the output by '0' guess so the output will be filled with '*'
	guessTheWord(actualWord, 0, wordHint);
	
	// copy to outgoingBuffer and sent the word hint as output filled with '*'
	strcpy(outgoingBuffer, wordHint); 
	send(*mySocket, outgoingBuffer, strlen(outgoingBuffer), 0);	
 
	//set up interupt handle for oracle ie. Ignore Ctrl+C
	signal(SIGINT, oraclePenalty);
	 
	while (1) {
		// first check if game is over
		if((penalty == GAME_WON)||(penalty == GAME_LOST)) {
			signal(SIGINT,SIG_DFL); //Restores Ctrl+C functionality
			if(penalty == GAME_LOST) {
				// listen for Winner Decision
				bytesRcv = recv(*mySocket, incommingBuffer, sizeof(incommingBuffer), 0);
				incommingBuffer[bytesRcv] = 0;
				
				// if the winner want to play another game return GAME_LOST so another game is played as guesser
				if(strcmp(incommingBuffer, "yes") == 0) {
					return GAME_LOST;
				}
				// else return GAME_QUIT_CONTINUE to quit the game ie the winner does not what to play again
				// but you as the looser must start the game again as a server and wait for a client to connect	
				return GAME_QUIT_CONTINUE;				
			}
			else if(penalty == GAME_WON) { 
				//Send the actual word over to the guesser
				strcpy(outgoingBuffer,actualWord);
				send(*mySocket,outgoingBuffer,strlen(outgoingBuffer),0);
				
				// if guesser won the game ask if it wants to play again
				printf("You won! Play Again? (yes or no):");
				gets(outgoingBuffer);
				send(*mySocket, outgoingBuffer, strlen(outgoingBuffer), 0); // tell the losser of the winners decision
				
				// if it want to play another game return GAME_WON so another game is played as oracle
				if(strcmp(outgoingBuffer, "yes") == 0) {
					return GAME_WON;
				}
				return GAME_QUIT; // else return GAME_QUIT to quit the game ie the winner does not what to play again
			}			
		}
		
		// get the guesser's guess and validate it
		bytesRcv = recv(*mySocket, incommingBuffer, sizeof(incommingBuffer), 0);
		incommingBuffer[bytesRcv] = 0;
		
		// if first word, start by copying else concatenate from what you have
		if(wordsGuessed[0]==0) {		
			strcpy(wordsGuessed, incommingBuffer);
		}
		else {
			strcat(wordsGuessed, ", "); //delimit by a ","
			strcat(wordsGuessed, incommingBuffer);
		}

		result = guessTheWord(actualWord, incommingBuffer, wordHint); // remember the results of the guess
		
		// if guess incorrect add a part to the hangman and send a signal to the guesser that he was wrong
		if(result==GUESS_NOK) {
			strcpy(outgoingBuffer, "-1"); //this tells the guesser he guessed wrong!
			penalty++;
		}
		else {
			strcpy(outgoingBuffer, wordHint); // sent the word hint as output
		}
				
		// if we are on a interrupt turn ie the oracle pressed Ctrl+C
		// then make oracle reveal a letter if possible
		if(turnStatus == INTERRUPT_TURN) {
			// reveal hint on wordHint by peaking at actual word
			revealHint(actualWord, wordHint);
			
			// sent the revealed word hint as output, if -1 present then concat to
			// show guesser his guess was bad else just copy over the revealed word
			if((outgoingBuffer[0]=='-')&&(outgoingBuffer[1]=='1')) {
				strcat(outgoingBuffer, wordHint);
			}
			else {
				strcpy(outgoingBuffer, wordHint); 
			}
			
			turnStatus = NORMAL_TURN; // make next turn normal
		}
		
		// the reason both are if(rather then if .. else if) is because: if the guesser ran 
		// out of all attemts and there was only one word remaining but the oracle pressed 
		// ctrl+c hence completing the word then the winning should be reassessed
		
		// if guesser makes more than 12 penalty, oracle won
		if(penalty>12) {
			penalty = GAME_WON;
		}
		//if guesser gets the word, oracle lost
		if(wordComplete(wordHint)==WORD_COMPLETE) { 
			penalty = GAME_LOST;
		}
		
		drawFigure(&penalty); // update hang man figure
		// Header
		printf("Oracle                         \n");
		printf("-------------------------------\n");		
		printf("Words Guessed: %s\n", wordsGuessed);
		printf("guesser's progress: %s\n", wordHint);
		printf("Actual word: %s\n", actualWord);
		
		// send the guessed string to guesser
		send(*mySocket, outgoingBuffer, strlen(outgoingBuffer), 0);
	}
	
	// all cases should have been dealt with,if you got here something went wrong so quit game!
	return GAME_QUIT;
 }
 
/* handles CTRL+C from oracle
 * @param="x" what caused the this signal, in this case its SIGINT
 * make global turnStatus INTERRUPT_TURN indicating that interupt has been detected
 */ 
void oraclePenalty(int x){
	printf("\nOracle has tried to quit mid-game!\n");
	printf("A letter will be revealed the next time guesser guesses a letter...\n");
	turnStatus = INTERRUPT_TURN;
}