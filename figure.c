/* Figure functions
 * Revision Date: 2012-12-02
 * Contains:
 * clearScreen();
 * drawFigure();
 */
 
#include "header.h"

/* Clear Screen
 * @param=""
 */
void clearScreen (void){
	system ("clear");
}

/* prints out the figure on the hangman based on status
 * @param="status" this gives the status of the game
 */
void drawFigure(const int *status) {
	clearScreen();
	switch(*status) {
		case 0:
						printf(" _   _   ___   _   _  ______   \n");
						printf("| | | | / _ \\ | \\ | ||  ____|\n");
						printf("| |_| || |_| ||  \\| || |  __  \n");
						printf("|  _  ||  _  ||     || | |  |  \n");
						printf("| | | || | | || |\\  || | |_ | \n");
						printf("|_| |_||_| |_||_| \\_||______| \n");
						printf("                               \n");
						printf("                               \n");
						printf("    __   __   ___   _   _      \n");
						printf("   |  \\ /  | / _ \\ | \\ | |  \n");
						printf("   |   v   || |_| ||  \\| |    \n");
						printf("   | |\\_/| ||  _  ||     |    \n");
						printf("   | |   | || | | || |\\  |    \n");
						printf("   |_|   |_||_| |_||_| \\_|    \n");
						printf("                               \n");
						printf("                               \n");
						printf("   Guesser has Full Health!    \n");
						printf(" 			       \n");
						printf("WRITTEN BY:                    \n");
						printf("   Ankush Varshneya            \n");
						printf("   Robert Nguyen               \n");
						break;
		case 1:
						printf(" ___________.._______          \n");
						printf("|  __________))______|         \n");
						printf("| | / /      ||                \n");
						printf("| |/ /       ||		           \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |_______           ___       \n");
						printf("|  _______|_        |_  |      \n");
						printf("| |       \\ \\         | |    \n");
						printf("| |        \\ \\        | |    \n");
						break;
		case 2:
						printf(" ___________.._______          \n");
						printf("|  __________))______|         \n");
						printf("| | / /      ||                \n");
						printf("| |/ /       ||		           \n");
						printf("| | /        ||.-''.           \n");
						printf("| |/         |/  _  \\         \n");
						printf("| |          ||  `/,|          \n");
						printf("| |          (\\`_.'           \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |_______           ___       \n");
						printf("|  _______|_        |_  |      \n");
						printf("| |       \\ \\         | |    \n");
						printf("| |        \\ \\        | |    \n");
						break;
		case 3:
						printf(" ___________.._______          \n");
						printf("|  __________))______|         \n");
						printf("| | / /      ||                \n");
						printf("| |/ /       ||		           \n");
						printf("| | /        ||.-''.           \n");
						printf("| |/         |/  _  \\         \n");
						printf("| |          ||  `/,|          \n");
						printf("| |          (\\`_.'           \n");
						printf("| |         .-`--'.            \n");
						printf("| |         Y     Y            \n");
						printf("| |         |     |            \n");
						printf("| |         |     |            \n");
						printf("| |         |_____|            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |_______           ___       \n");
						printf("|  _______|_        |_  |      \n");
						printf("| |       \\ \\         | |    \n");
						printf("| |        \\ \\        | |    \n");
						break;
		case 4:
						printf(" ___________.._______          \n");
						printf("|  __________))______|         \n");
						printf("| | / /      ||                \n");
						printf("| |/ /       ||		           \n");
						printf("| | /        ||.-''.           \n");
						printf("| |/         |/  _  \\         \n");
						printf("| |          ||  `/,|          \n");
						printf("| |          (\\`_.'           \n");
						printf("| |         .-`--'.            \n");
						printf("| |        /Y     Y            \n");
						printf("| |       //|     |            \n");
						printf("| |      // |     |            \n");
						printf("| |         |_____|            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |_______           ___       \n");
						printf("|  _______|_        |_  |      \n");
						printf("| |       \\ \\         | |    \n");
						printf("| |        \\ \\        | |    \n");
						break;
		case 5:
						printf(" ___________.._______          \n");
						printf("|  __________))______|         \n");
						printf("| | / /      ||                \n");
						printf("| |/ /       ||		           \n");
						printf("| | /        ||.-''.           \n");
						printf("| |/         |/  _  \\         \n");
						printf("| |          ||  `/,|          \n");
						printf("| |          (\\`_.'           \n");
						printf("| |         .-`--'.            \n");
						printf("| |        /Y     Y\\          \n");
						printf("| |       //|     |\\\\        \n");
						printf("| |      // |     | \\\\       \n");
						printf("| |         |_____|            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |_______           ___       \n");
						printf("|  _______|_        |_  |      \n");
						printf("| |       \\ \\         | |    \n");
						printf("| |        \\ \\        | |    \n");
						break;
		case 6:
						printf(" ___________.._______          \n");
						printf("|  __________))______|         \n");
						printf("| | / /      ||                \n");
						printf("| |/ /       ||		           \n");
						printf("| | /        ||.-''.           \n");
						printf("| |/         |/  _  \\         \n");
						printf("| |          ||  `/,|          \n");
						printf("| |          (\\`_.'           \n");
						printf("| |         .-`--'.            \n");
						printf("| |        /Y     Y\\          \n");
						printf("| |       //|     |\\\\        \n");
						printf("| |      // |     | \\\\       \n");
						printf("| |     \')  |_____|           \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |_______           ___       \n");
						printf("|  _______|_        |_  |      \n");
						printf("| |       \\ \\         | |    \n");
						printf("| |        \\ \\        | |    \n");
						break;
		case 7:
						printf(" ___________.._______          \n");
						printf("|  __________))______|         \n");
						printf("| | / /      ||                \n");
						printf("| |/ /       ||		           \n");
						printf("| | /        ||.-''.           \n");
						printf("| |/         |/  _  \\         \n");
						printf("| |          ||  `/,|          \n");
						printf("| |          (\\`_.'           \n");
						printf("| |         .-`--'.            \n");
						printf("| |        /Y     Y\\          \n");
						printf("| |       //|     |\\\\        \n");
						printf("| |      // |     | \\\\       \n");
						printf("| |     \')  |_____| (\'       \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |_______           ___       \n");
						printf("|  _______|_        |_  |      \n");
						printf("| |       \\ \\         | |    \n");
						printf("| |        \\ \\        | |    \n");
						break;
		case 8:
						printf(" ___________.._______          \n");
						printf("|  __________))______|         \n");
						printf("| | / /      ||                \n");
						printf("| |/ /       ||		           \n");
						printf("| | /        ||.-''.           \n");
						printf("| |/         |/  _  \\         \n");
						printf("| |          ||  `/,|          \n");
						printf("| |          (\\`_.'           \n");
						printf("| |         .-`--'.            \n");
						printf("| |        /Y     Y\\          \n");
						printf("| |       //|     |\\\\        \n");
						printf("| |      // |     | \\\\       \n");
						printf("| |     \')  |_____| (\'       \n");
						printf("| |         |  _  |            \n");
						printf("| |         |_| |_|            \n");
						printf("| |                            \n");
						printf("| |                            \n");
						printf("| |_______           ___       \n");
						printf("|  _______|_        |_  |      \n");
						printf("| |       \\ \\         | |    \n");
						printf("| |        \\ \\        | |    \n");
						break;
		case 9:
						printf(" ___________.._______          \n");
						printf("|  __________))______|         \n");
						printf("| | / /      ||                \n");
						printf("| |/ /       ||		           \n");
						printf("| | /        ||.-''.           \n");
						printf("| |/         |/  _  \\         \n");
						printf("| |          ||  `/,|          \n");
						printf("| |          (\\`_.'           \n");
						printf("| |         .-`--'.            \n");
						printf("| |        /Y     Y\\          \n");
						printf("| |       //|     |\\\\        \n");
						printf("| |      // |     | \\\\       \n");
						printf("| |     \')  |_____| (\'       \n");
						printf("| |         |  _  |            \n");
						printf("| |         |_| |_|            \n");
						printf("| |          ||                \n");
						printf("| |          ||                \n");
						printf("| |_______           ___       \n");
						printf("|  _______|_        |_  |      \n");
						printf("| |       \\ \\         | |    \n");
						printf("| |        \\ \\        | |    \n");
						break;
		case 10:
						printf(" ___________.._______          \n");
						printf("|  __________))______|         \n");
						printf("| | / /      ||                \n");
						printf("| |/ /       ||		           \n");
						printf("| | /        ||.-''.           \n");
						printf("| |/         |/  _  \\         \n");
						printf("| |          ||  `/,|          \n");
						printf("| |          (\\`_.'           \n");
						printf("| |         .-`--'.            \n");
						printf("| |        /Y     Y\\          \n");
						printf("| |       //|     |\\\\        \n");
						printf("| |      // |     | \\\\       \n");
						printf("| |     \')  |_____| (\'       \n");
						printf("| |         |  _  |            \n");
						printf("| |         |_| |_|            \n");
						printf("| |          || ||             \n");
						printf("| |          || ||             \n");
						printf("| |_______           ___       \n");
						printf("|  _______|_        |_  |      \n");
						printf("| |       \\ \\         | |    \n");
						printf("| |        \\ \\        | |    \n");
						break;
		case 11:
						printf(" ___________.._______          \n");
						printf("|  __________))______|         \n");
						printf("| | / /      ||                \n");
						printf("| |/ /       ||		           \n");
						printf("| | /        ||.-''.           \n");
						printf("| |/         |/  _  \\         \n");
						printf("| |          ||  `/,|          \n");
						printf("| |          (\\`_.'           \n");
						printf("| |         .-`--'.            \n");
						printf("| |        /Y     Y\\          \n");
						printf("| |       //|     |\\\\        \n");
						printf("| |      // |     | \\\\       \n");
						printf("| |     \')  |_____| (\'       \n");
						printf("| |         |  _  |            \n");
						printf("| |         |_| |_|            \n");
						printf("| |          || ||             \n");
						printf("| |          || ||             \n");
						printf("| |_______  / |      ___       \n");
						printf("|  _______|_`-'     |_  |      \n");
						printf("| |       \\ \\         | |    \n");
						printf("| |        \\ \\        | |    \n");
						break;
		case 12:
						printf(" ___________.._______          \n");
						printf("|  __________))______|         \n");
						printf("| | / /      ||                \n");
						printf("| |/ /       ||	               \n");
						printf("| | /        ||.-''.           \n");
						printf("| |/         |/  _  \\         \n");
						printf("| |          ||  `/,|          \n");
						printf("| |          (\\`_.'           \n");
						printf("| |         .-`--'.            \n");
						printf("| |        /Y     Y\\          \n");
						printf("| |       //|     |\\\\        \n");
						printf("| |      // |     | \\\\       \n");
						printf("| |     \')  |_____| (\'       \n");
						printf("| |         |  _  |            \n");
						printf("| |         |_| |_|            \n");
						printf("| |          || ||             \n");
						printf("| |          || ||             \n");
						printf("| |_______  / | | \\  ___      \n");
						printf("|  _______|_`-' `-' |_  |      \n");
						printf("| |       \\ \\         | |    \n");
						printf("| |        \\ \\        | |    \n");
						break;
		case GAME_LOST:	//if the player lost
						printf("    _     _   ___    _   _     \n");
						printf("   | |   | | / _ \\  | | | |   \n");
						printf("   |  \\_/  || | | | | | | |   \n");
						printf("    \\_   _/ | | | | | | | |   \n");
						printf("      | |   | |_| | | |_| |    \n");
						printf("      |_|    \\___/   \\___/   \n");
						printf("                               \n");
						printf("                               \n");
						printf(" _       ___    _____  _______ \n");
						printf("| |     / _ \\  / ____||__   __|\n");
						printf("| |    | | | || (___     | |   \n");
						printf("| |    | | | | \\___ \\    | | \n");
						printf("| |___ | |_| | ____) |   | |   \n");
						printf("|_____| \\___/ |_____/    |_|  \n");
						printf("                               \n");
						printf("                               \n");
						printf("                               \n");
						printf(" 			                   \n");
						printf("WRITTEN BY:                    \n");
						printf("   Ankush Varshneya            \n");
						printf("   Robert Nguyen               \n");
						break;
		case GAME_WON:	//if the player wins
						printf("    _     _   ___    _   _     \n");
						printf("   | |   | | / _ \\  | | | |   \n");
						printf("   |  \\_/  || | | | | | | |   \n");
						printf("    \\_   _/ | | | | | | | |   \n");
						printf("      | |   | |_| | | |_| |    \n");
						printf("      |_|    \\___/   \\___/   \n");
						printf("                               \n");
						printf("                               \n");
						printf("     _     _   ___   _   _     \n");
						printf("    | |   | | / _ \\ | \\ | |  \n");
						printf("    | | _ | || | | ||  \\| |   \n");
						printf("    | |/ \\| || | | ||     |   \n");
						printf("    |   ^   || |_| || |\\  |   \n");
						printf("    |__/ \\__| \\___/ |_| \\_| \n");
						printf("                               \n");
						printf("                               \n");
						printf("                               \n");
						printf(" 			                   \n");
						printf("WRITTEN BY:                    \n");
						printf("   Ankush Varshneya            \n");
						printf("   Robert Nguyen               \n");
						break;
		default:		break; // do nothing otherwise
	}
	printf("-------------------------------\n\n");
}