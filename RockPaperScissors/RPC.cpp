/*
	Name: bill
	Date: 09.17.18
	Description: Functions sample using the program for Rock, Paper, Scissors
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

// function prototypes
// enum is an abbreviation for enumeration, an unchangeable list
enum objectType { ROCK, PAPER, SCISSORS };
void displayRules();
objectType retrievePlay(char selection);
void convertEnum(objectType object);
bool validSelection(char selection);
objectType winningObject(objectType play1, objectType play2);
void gameResult(objectType play1, objectType play2, int& winner);
void displayResult(int gCount, int wCount1, int wCount2);

int main() {
	// variables
	int gameCount = 0;
	int winCount1 = 0;
	int winCount2 = 0;
	int gameWinner = 0;
	int hold;
	char response = ' ';
	char selection1 = ' ';
	char selection2 = ' ';
	objectType play1; // player 1's selection
	objectType play2; // player 2's selection

	displayRules();

	cout << endl << "Enter Y/y to play the game: ";
	cin >> response;
	cout << endl;

	while (response == 'Y' || response == 'y') {
		cout << "Player 1 enter your choice: ";
		cin >> selection1;
		cout << endl;

		system("CLS");

		cout << "Player 2 enter your choice: ";
		cin >> selection2;
		cout << endl;

		system("CLS");

		if (validSelection(selection1) && validSelection(selection2)) {
			play1 = retrievePlay(selection1);
			play2 = retrievePlay(selection2);
			gameCount++;
			gameResult(play1, play2, gameWinner);

			if (gameWinner == 1) {
				winCount1++;
			}
			else if (gameWinner == 2) {
				winCount2++;
			}

		}
		cout << "Enter Y/y to play the game: ";
		cin >> response;
		cout << endl;
	}
	displayResult(gameCount, winCount1, winCount2);
	cin >> hold;
	return 0;
}

// functions

void displayRules() {
	cout << "A player who decides to play rock will beat another player who has chosen scissors\n"
		<< "(\"rock crushes scissors\" or sometimes \"blunts scissors\"), but will lose to one\n"
		<< "who has played paper (\"paper covers rock\"); a play of paper will lose to a play of scissors (\"scissors cuts paper\").";
}

bool validSelection(char selection) {
	switch (selection) {
		case 'R':
		case 'r':
		case 'P':
		case 'p':
		case 'S':
		case 's':
			return true;
		default:
			return false;
	}
}

objectType retrievePlay(char selection) {
	objectType object;

	switch (selection) {
		case 'R':
		case 'r':
			object = ROCK;
			break;
		case 'P':
		case 'p':
			object = PAPER;
			break;
		case 'S':
		case 's':
			object = SCISSORS;
			break;
	}
	return object;
}

void convertEnum(objectType object) {
	switch (object) {
		case ROCK:
			cout << "Rock";
			break;
		case PAPER:
			cout << "Paper";
			break;
		case SCISSORS:
			cout << "Scissors";
	}
}

objectType winningObject(objectType play1, objectType play2) {
	if ((play1 == ROCK && play2 == SCISSORS) || (play2 == ROCK && play1 == SCISSORS))
		return ROCK;
	else if ((play1 == ROCK && play2 == PAPER) || (play2 == ROCK && play1 == PAPER))
		return PAPER;
	else
		return SCISSORS;
}

void gameResult(objectType play1, objectType play2, int& winner) {
	objectType winnerObject;
	if (play1 == play2) {
		cout << "SUCKAHS! y'all's choosed da same tang!";
	}
	else {
		winnerObject = winningObject(play1, play2);

		cout << "Player 1 selected ";
		convertEnum(play1);
		cout << " and player 2 selected ";
		convertEnum(play2);
		cout << ". ";

		if (play1 == winnerObject)
			winner = 1;
		else if (play2 == winnerObject)
			winner = 2;

		cout << "Player " << winner << " wins this game";
	}
}

void displayResult(int gCount, int wCount1, int wCount2) {
	cout << "The total number of plays: " << gCount << endl;
	cout << "The number of plays won by player 1: " << wCount1 << endl;
	cout << "The number of plays won by player 2: " << wCount2 << endl;
}
