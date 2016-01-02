A simple p2p hangman game using c sockets and signals.

Usage:

- use makefile to compile

- for server mode: ./a4

- for client mode: ./a4 "type ip address (in the format ###.###.###.###) here without the quotation marks."
   
Game Objective:

- The oracle may type in any word for guessing except "Guesser Pressed CTRL+C" as its used by the program to indicate a signal interupt from the guessers end.

- Word entering by the oracle or guesser is handled by keyboard input

- Game starts with oracle typing a word which will be hidden to the guesser.

- Guesser tries to guess the word by inputting letters or the whole word itself

- If the guesser gets more than 12 misses, then the oracle wins, otherwise the guesser wins.

- The winner decides if the game should continue or end

- If the game continues, if the guesser won, the two players switch roles 

- If winner decided not to play again then the game ends for the winner, but the loser's game process begain again with him waiting for a player to connect.
