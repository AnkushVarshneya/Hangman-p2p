/* Header file
 * Revision Date: 2012-12-02
 */
 
// required dependencies
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>

// pre processor definitions
#define MY_PORT				60002	// Port used
#define MAX_OUTPUT_BUFFER	50		// output buffer length
#define MAX_INPUT_BUFFER	50		// input buffer length
#define MAX_WORD_BUFFER		50		// guess word length
#define MAX_GUESSED_BUFFER	500		// guesses list length
#define WORD_COMPLETE		-1		// word complete
#define WORD_INCOMPLETE		-2		// word incomplete
#define INTERRUPT_TURN		-3		// indicates some one pressed ctrl+c
#define NORMAL_TURN			-4		// indicates no one pressed ctrl+c
#define GUESS_OK			-5		// guessed word was correct
#define GUESS_NOK			-6		// guess word was incorrect
#define GAME_LOST			-7		// game lost
#define GAME_WON			-8		// game won
#define GAME_QUIT			-9		// quit game and program
#define GAME_QUIT_CONTINUE	-10		// quit game but resume program as server

// Function prototypes
int		server(void);
int		client(char*);
int		oracle(const int*);
int		guesser(const int*);
void	oraclePenalty();
void	guesserPenalty();
int		guessTheWord(char*, char*, char*);
int		wordComplete(char*);
void	revealHint(char*, char*);
void	drawFigure(const int*);
void	clearScreen (void);

// global variable to keep track of interrupt turn vs normal turn (for next guess)
volatile int turnStatus;