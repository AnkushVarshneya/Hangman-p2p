/* Word Utility functions
 * Revision Date: 2012-12-02
 * contains:
 * guessTheWord();
 * wordComplete();
 * revealHint();
 */

#include "header.h"

/* checks to see if the search term is in the gues word
 * @param="actualWord"	the initial word
 * @param="searchTerm"	the term to search in the guessWord
 * @param="guessWord"	if search term in word display fill that part of guessWord as the searchTerm
 * @return = returns if a letter was found, ie. GUESS_NOK = not found, GUESS_OK = found
 */ 
 int guessTheWord(char *actualWord, char *searchTerm, char *guessWord) {
	int guessLen, searchLen, i, found; 
	
	// actualWord length
	guessLen = strlen(actualWord);
	
	//search term length if its null make the lenth 0
	searchLen = (searchTerm==0)? 0:strlen(searchTerm);
	
	// no letter has been found yet!
	found = GUESS_NOK;
	
	if(searchLen==0) {
		for(i=0; i<guessLen; i++) {
			guessWord[i]='*'; // fill the guessWord with '*'
		}
		guessWord[guessLen]=0; // null terminate guessWord
	}
	else if (searchLen==1) { // if a char was given search for it
		for(i=0; i<guessLen; i++) {
			if(actualWord[i]==searchTerm[0]) {
				found = GUESS_OK; // indicating a letters been found
				guessWord[i]=searchTerm[0]; // fill guessWord with search terms
			}
			guessWord[guessLen]=0; // null terminate guessWord
		}
	}
	else { //the search term was a guess of entire word probably
		if(strcmp(actualWord, searchTerm)==0) {
			strcpy(guessWord, actualWord); // reveal the guess word as the guesser guessed it correctly
			found = GUESS_OK; //indicating a words been found
		}
	}
	
	return found;
 }
 
/* check to see is word is complete
 * @param="guessWord" check if guess word is complete is does it contain any '*'
 * @return = return if word is complete, ie no '*' found = WORD_COMPLETE, '*' found = WORD_INCOMPLETE
 * the reason this function is used instead of comparing with actual word is because
 * the guesser does not have access to the acutal word so we must scan the guess/hint word
 */ 
 int wordComplete(char *guessWord){
	int guessLen, i;
	
 	// actualWord length
	guessLen = strlen(guessWord);
	
	for(i=0; i<guessLen; i++) {
		if(guessWord[i]=='*') {
			return WORD_INCOMPLETE; //if '*' found return as WORD_INCOMPLETE
		}
	}
	
	return WORD_COMPLETE; // no '*' found return WORD_COMPLETE
 }
  
/* find the first hidden letter in output find out what it is and reveal it
 * @param="actualWord"	the initial word
 * @param="guessWord"	the guess Word so far
 */ 
 void revealHint(char *actualWord, char *guessWord) {
	if(strcmp(actualWord, guessWord)==0) {
		// the words already been fully solved
		// do not bother revealing anything just get out of the function
		return;	
	}
	 
	int guessLen, i;
	char hintLetter[2];
	
	// make it null
	hintLetter[0]=0;
	
	// actualWord length
	guessLen = strlen(actualWord);
	
	// find the index of first hidden 	
	for(i=0; i<guessLen; i++) {
		if(guessWord[i]=='*') {
			break;
		}
	}
	
	//get the hint letter
	hintLetter[0]=actualWord[i];
	hintLetter[1]=0;
	
	// only guess with hint letter if its not null!
	if(hintLetter[0]!=0) {
		// reveal that word with hint letter, if the oracle is unable to reveal a letter print error message
		if(guessTheWord(actualWord, hintLetter, guessWord)==GUESS_NOK) { 
			printf("Well this is kind of embarrassing... the Oracle had some trouble trying to reveal a word.\n"); 
		}
	}
}
 