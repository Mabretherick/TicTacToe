/****************************************************************************************
*My weak attempt at a two player tic-tac-toe program. 
*Works sorta.
*No real testing done. 
*No win condition made
*
* 4/13/2016 done while internet was down and I was SOOOO BORED.
*
****************************************************************************************/
#include <iostream>

void printBoard(char currentBoard[]);		//Prints values in the board array
void boardInit(char currentBoard[]);		//For reseting the board for another game
void drawBoard(char currentBoard[]);		//Roughly draws the current board
void gameLoop(char currentBoard[]);

int main() {
	char boardArray[9] = {'1','2','3','4','5','6','7','8','9'};
	std::cout << "Welcome to Tic Tac Toe!" << std::endl
		<< "To play enter a number to choose your position. X goes first." << std::endl;
	gameLoop(boardArray);
	return 0;
}


void printBoard(char currentBoard[]) {
	for (int i = 0; i < 9; i++) {
		std::cout << currentBoard[i] << " ";
	}
	std::cout << std::endl;
}

void boardInit(char currentBoard[]) {
	strcpy_s(currentBoard,9, "123456789");
}

void drawBoard(char currentBoard[]) {
	std::cout << std::endl;
	std::cout << currentBoard[0] << "|" << currentBoard[1] << "|" << currentBoard[2] << std::endl;
	std::cout << "-" << "|" << "-" << "|" << "-" << std::endl;
	std::cout << currentBoard[3] << "|" << currentBoard[4] << "|" << currentBoard[5] << std::endl;
	std::cout << "-" << "|" << "-" << "|" << "-" << std::endl;
	std::cout << currentBoard[6] << "|" << currentBoard[7] << "|" << currentBoard[8] << std::endl;
	std::cout << std::endl;
}

void gameLoop(char currentBoard[]) {
	drawBoard(currentBoard);
	int userChoice = 99;
	for (int i = 0; i < 9; i++) {
		std::cin >> userChoice;
		while (userChoice < 1 || userChoice > 9) {
			std::cout << "Invalid Entry, Please try again." << std::endl;
			std::cin >> userChoice;
		}

		if (i % 2 == 0) {
			currentBoard[userChoice-1] = 'X';
		}
		else {
			currentBoard[userChoice-1] = 'O';
		}
		drawBoard(currentBoard);
	}
}