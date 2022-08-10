
// Tic-Tac-Toe Header file

#include <string>

using namespace std;

enum status { WIN, DRAW, CONTINUE };

class ticTacToe {
	public:
		void play();
		// function to start the play

		void displayBoard() const;
		// function to print the board

		bool isValidMove(int x, int y) const;
		// function to determine if a move is valid

		bool getXOMove(char moveSymbol, char firstPlayer, string name1, string name2);
		// function to get a move for a player

		status gameStatus();
		// function to determine the current status of the game

		void reStart();
		// function to restart the game

		void stats(string name1, string name2);
		// function to display stats

		void printPatrick();
		// funny

		ticTacToe();
		// default constructor
		// postcondition: initializes the board to an empty state

	private:
		char board[3][3];
		int noOfMoves;
};