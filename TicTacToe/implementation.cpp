//tic tac toe implementation file

#include <iostream>
#include <iomanip>
#include "ticTacToe.h"
#include <string>

using namespace std;

int PLAYER1WINS = 0;
int PLAYER2WINS = 0;
double PLAYER1KDRAT = 0.00;
double PLAYER2KDRAT = 0.00;

void ticTacToe::play() {
	bool done = false;
	char player1 = ' ';
	char player = ' ';
	char again = ' ';
	char choice = ' ';
	string player1Name = " ";
	string player2Name = " ";

	if (player1Name == " ") {
		cout << "Enter the name of player 1: " << endl;
		cin >> player1Name;
		cout << "Enter the name of player 2: " << endl;
		cin >> player2Name;
	}
	
	cout << player1Name << " enter X/x or O/o" << endl;
	cin >> player;
	if (player == 'x' || player == 'X') {
		player = 'X';
		player1 = 'X';
	}
	else if (player == 't') {
		ticTacToe game;
		game.stats(player1Name, player2Name);
	}
	else {
		player = 'O';
		player1 = 'O';
	}

	system("CLS");
	displayBoard();

	while (!done) {
		done = getXOMove(player, player1, player1Name, player2Name);
		if (player == 'X')
			player = 'O';
		else
			player = 'X';
	}
}

void ticTacToe::displayBoard() const {
	cout << "   1    2    3" << endl << endl;
	
	for (int row = 0; row < 3; row++) {
		cout << row + 1;

		for (int col = 0; col < 3; col++) {
			cout << setw(3) << board[row][col];

			if (col != 2)
				cout << " |";
		}

		cout << endl;

		if (row != 2) {
			cout << " ____|____|____" << endl
			<< "     |    |   " << endl;
		}
	}
	cout << endl;
}

bool ticTacToe::isValidMove(int row, int col) const
{
	if (0 <= row && row <= 2 && 0 <= col && col <= 2 && board[row][col] == ' ')
		return true;
	else
		return false;
}

bool ticTacToe::getXOMove(char playerSymbol, char firstPlayer, string name1, string name2) {
	int row, col;
	char again = ' ';

	do {
		if (playerSymbol == firstPlayer) {
			cout << name1 << " enter move, row first, space, then column: ";
			cin >> row >> col;
			cout << endl;
			
			while (board[row - 1][col - 1] != ' ') {
				cout << "Invalid input, try again. Row first, space, then column: ";
				cin >> row >> col;
			}
		}
		else {
			cout << name2 << " enter move, row first, space, then column: ";
			cin >> row >> col;
			cout << endl;

			while (board[row - 1][col - 1] != ' ') {
				cout << "Invalid input, try again. Row first, space, then column: ";
				cin >> row >> col;
			}
		}
	} while (!isValidMove(row - 1, col - 1));

	row--;
	col--;
	noOfMoves++;
	board[row][col] = playerSymbol;

	system("CLS");
	displayBoard();

	// check each play for a winner
	status gStatus = gameStatus();

	if (gStatus == WIN) {
		if (playerSymbol == firstPlayer) {
			cout << name1 << " wins!" << endl;
			PLAYER1WINS += 1;
			
			ticTacToe::stats(name1, name2);
		}
		else {
			cout << name2 << " wins" << endl;
			PLAYER2WINS += 1;
			cout << PLAYER2WINS;
			ticTacToe::stats(name1, name2);
		}
		return true;
	}
	else if (gStatus == DRAW) {
		cout << "This game is a draw!" << endl;
		return true;
	}
	else
		return false;
}

status ticTacToe::gameStatus() {
	// check rows for a win
	for (int row = 0; row < 3; row++)
		if (board[row][0] != ' ' && (board[row][0] == board[row][1]) && 
			(board[row][1] == board[row][2]))
			return WIN;
	for (int col = 0; col < 3; col++) {
		if (board[0][col] != ' ' && (board[0][col] == board[1][col]) && 
			(board[1][col] == board[2][col]))
			return WIN;
	}

	// check diagnosis for a win
	if (board[0][0] != ' ' && (board[0][0] == board[1][1]) && (board[1][1] && board[1][1] == board[2][2])) {
		return WIN;
	}

	if (board[2][0] != ' ' && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])) {
		return WIN;
	}

	if (noOfMoves < 9)
		return CONTINUE;

	return DRAW;
}

void ticTacToe::reStart() {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			board[row][col] = ' ';
		}
	}
	noOfMoves = 0;
}
void ticTacToe::stats(string name1, string name2) {
	char choice = ' ';

	cout << "Would you like to view stats? y/n" << endl;
	cin >> choice;

	if (choice == 'y' || choice == 'Y') {
		if (PLAYER2WINS != 0) {
			PLAYER1KDRAT = PLAYER1WINS / PLAYER2WINS;
		}
		else
			PLAYER1KDRAT = PLAYER1WINS;
		if (PLAYER1WINS != 0)
			PLAYER2WINS = PLAYER2WINS / PLAYER1WINS;
		else
			PLAYER2KDRAT = PLAYER2WINS;
		cout << "   Name:   " << setw(10) << left << name1 << setw(11) << name2 << endl
			<< "   Wins:   " << setw(5) << right << PLAYER1WINS << setw(9) << right << PLAYER2WINS << endl
			<< "K/D Ratio: " << setw(5) << right << PLAYER1KDRAT << setw(9) << right << PLAYER2KDRAT << endl;
		cout << "Would you like to play again? ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			system("CLS");
			ticTacToe();
		}
	}
	else {
		cout << "Would you like to play again? ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
			ticTacToe();
		else
			exit(0);
	}
}
ticTacToe::ticTacToe() {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			board[row][col] = ' ';
		}
	}
	noOfMoves = 0;

	ticTacToe::play();
}
