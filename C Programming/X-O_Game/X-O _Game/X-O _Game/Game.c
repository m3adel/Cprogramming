/*****************************************************************************************************************************************/
/* main.c (main flow function)
Author : Mohamed Abdelsalam
X-O game is a fun, traditional, 
and online browser game where you have to use your own strategies 
of placing 3 marks in a horizontal, vertical, or diagonal row. 
To win, you must be the first to get three of your marks in a row.
*/
/*****************************************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
/*****************************************************************************************************************************************/
//typedefs
typedef unsigned char uint8_t;
/*****************************************************************************************************************************************/
//Global Variables
uint8_t count = 0;
uint8_t GS = 2;
uint8_t board[9] = { '1','2','3','4','5','6','7','8','9' };
uint8_t ConfigArray[2];
uint8_t position;
/*****************************************************************************************************************************************/
/*APIs*/
/*****************************************************************************************************************************************/
/*Implement and draw your board:
1. A board will be initialized with numbers from 1 to 9, which state each position number
2. Implement draw board function
*/
/*****************************************************************************************************************************************/
void drawBoard(uint8_t* board);					// This function will take a board as an input and prints it on the console
void updateBoard(uint8_t* board, uint8_t position, uint8_t value);	//This function will take the board, position to update and value to set in this position
/*****************************************************************************************************************************************/
/*Implement Players Config
1. Only two players (Player 1 and Player 2)
2. Implement the get player symbol function
- This function will take the player's number and asks the player to choose between X and O (case insensitive)
- This function will return 0 when the input symbol is not wrong and/or was not chosen before
- This function will return 1 when the input symbol is wrong and/or was chosen before
*/
/*****************************************************************************************************************************************/
uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol);
/*****************************************************************************************************************************************/
/*Implement Set Players Config
*  This function will prompt and asks each user about their preferred symbols and saves it in the configArray*/
/*****************************************************************************************************************************************/
void setPlayerConfig(uint8_t* configArray);
/*****************************************************************************************************************************************/
/*Implement selected player move
This function will take the player's number then load his config, ask him for the position then updates the board
*/
/*****************************************************************************************************************************************/
void loadAndUpdate(uint8_t playerNumber);
/*****************************************************************************************************************************************/
/*Implement winning condition check
- This function will check after each move if there is a win, draw or continue playing.
- Returns 0 for winning
- Returns 1 for a draw
- Returns 2 to continue
*/
/*****************************************************************************************************************************************/
void getGameState(uint8_t* board, uint8_t* gameState);		// Implement a function to check if there is a winning, draw, or continue playing.
/*****************************************************************************************************************************************/

int main()
{



	setPlayerConfig(&ConfigArray);
	drawBoard(&board);
	for (int z = 0; z < 9; z++) {
		
		uint8_t s = (z % 2) + 1;
		loadAndUpdate(z % 2);
		drawBoard(&board);
		getGameState(&board, &GS);
		if (GS == 0) {
			printf("The Winner Is %c-Player (Player %d) !!! Congrats\n", ConfigArray[s - 1], s);
			break;
		}
		else if (GS == 1) {
			printf("The game is Draw\n");
			break;
		}
		else {
			printf("The game is Continue\n");

		}
	}


	return 0;
}






void drawBoard(uint8_t* board) {

	printf(" ___________\n");
	printf("| %c | %c | %c |\n", board[0], board[1], board[2]);
	printf("------------\n");
	printf("| %c | %c | %c |\n", board[3], board[4], board[5]);
	printf("------------\n");
	printf("| %c | %c | %c |\n", board[6], board[7], board[8]);
	printf(" -----------\n");


}



void updateBoard(uint8_t* board, uint8_t position, uint8_t value) {
	int i = position - 1;
	board[i] = value;

}




uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol) {
	uint8_t temp;
	uint8_t i = playerNumber - 1;
	printf("Player No.%i Please Enter The symbol (X or O) ....:", playerNumber);

	scanf("%c", &temp);
	getchar();

	if ((temp == 'X') || (temp == 'O')) {

		if (temp != symbol[1] && temp != symbol[0]) {

			symbol[i] = temp;


			return 0;
		}
		else {
			return 1;
		}

	}
	else {
		return 1;
	}
}


void setPlayerConfig(uint8_t* configArray) {
	int pno;


	printf("please enter your No. (1 or 2).......:");
	scanf("%d", &pno);
	getchar();
	if (pno == 1) {
		for (pno = 1; pno < 3; pno++) {
			uint8_t b = getPlayerSymbol(pno, configArray);


			while (b == 1) {

				printf("Try another symbol. .......:\n");
				b = getPlayerSymbol(pno, configArray);

			}


		}
	}
	else if (pno == 2) {
		for (pno = 2; pno > 0; pno--) {
			uint8_t b = getPlayerSymbol(pno, configArray);


			while (b == 1) {

				printf("Try another symbol. .......:\n");
				b = getPlayerSymbol(pno, configArray);
			}

		}


	}



	else {
		printf("you enter Wrong No.!!!\n");

	}

}
void loadAndUpdate(uint8_t playerNumber) {
	uint8_t m = playerNumber + 1;
	printf("Player no.%d .. choose your move position (1 to 9)...: ", m);
	int y;
	scanf("%i", &y);
	getchar();



	updateBoard(&board, y, ConfigArray[playerNumber]);

}
void getGameState(uint8_t* board, uint8_t* gameState) {
	count++;
	if (board[0] == board[1] && board[0] == board[2]) { *gameState = 0; } //horizontal Row
	else if ((board[3] == board[4]) && (board[3] == board[5])) { *gameState = 0; } //horizontal Row
	else if (board[6] == board[7] && board[6] == board[8]) { *gameState = 0; } //horizontal Row
	else if (board[0] == board[3] && board[0] == board[6]) { *gameState = 0; } //vertical Row
	else if (board[1] == board[4] && board[1] == board[7]) { *gameState = 0; } //vertical Row
	else if (board[2] == board[5] && board[2] == board[8]) { *gameState = 0; } //vertical Row
	else if (board[0] == board[4] && board[0] == board[8]) { *gameState = 0; } //diagonal 1 Row
	else if (board[2] == board[4] && board[2] == board[6]) { *gameState = 0; } //diagonal 1 Row
	else if (count < 9) { *gameState = 2; } //continue Game
	else if (count == 9 && *gameState != 1){ *gameState = 1; } //Draw Game
	
}
