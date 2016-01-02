OBJ = main.o server.o client.o oracle.o guesser.o wordUtils.o figure.o 
DEBUG = -g
TARNAME = hangman.tar

a4:				$(OBJ)
				gcc $(DEBUG) -o a4 $(OBJ)

main.o:			header.h main.c
				gcc $(DEBUG) -c main.c
				
server.o:		header.h server.c
				gcc $(DEBUG) -c server.c

client.o:		header.h client.c
				gcc $(DEBUG) -c client.c
			
oracle.o:		header.h oracle.c
				gcc $(DEBUG) -c oracle.c
			
guesser.o:		header.h guesser.c
				gcc $(DEBUG) -c guesser.c
			
wordUtils.o:	header.h wordUtils.c
				gcc $(DEBUG) -c wordUtils.c
			
figure.o:		header.h figure.c
				gcc $(DEBUG) -c figure.c
				
clean:
				rm -f $(OBJ) a4 $(TARNAME)

package:	
				tar -cvf $(TARNAME) *.c *.h Makefile