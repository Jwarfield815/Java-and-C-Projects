/*
	Name: Jonathan Warfield
	Date: 10.9.2018
	Description: Order plane seats simulator
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <windows.h>

using namespace std;

// table that stores plane layout
char planeLayout[9][4] = { { 'O','-','-','O' },{ '+','-','-','+' },{ 'O','-','-','O' },{ 'O','O','-','-' },{ '+','+','-','+' },{ 'O','O','-','+' },{ 'O','-','-','O' },{ 'O','-','-','O' },{ 'O','-','-','O' } };
double subtotal = 0.0;
char seatsOrdered[14];
int seatPositions[28];
int x = 0;
int length = 28;
int counter = 0;
double ftotal = 0.0;

void printMenu();
void pay();

int main() {
	// variables
	int hold;
	
	int y = 0;
	int z = 0;
	int row = 0;
	char column = ' ';
	bool keep = true;
	bool end = false;
	bool validSeat = true;
	bool moreSeats = true;

	char choice = ' ';
	char removeChoice = ' ';
	char changeMind = ' ';
	char notherSeat = ' ';

	system("CLS");
	printMenu();

	do {
		cin >> row >> column;

		switch (column) {
			case 'a':
				y = 0;
				break;
			case 'A':
				y = 0;
				break;
			case 'b':
				y = 1;
				break;
			case 'B':
				y = 1;
				break;
			case 'c':
				y = 2;
				break;
			case 'C':
				y = 2;
				break;
			case 'd':
				y = 3;
				break;
			case 'D':
				y = 3;
				break;
			default:
				cout << "Invalid column choice. Please pick your row and column again." << endl;
				main();
				break;
		}
		
		// checks to make sure the seat isn't a table or empty space
		if (planeLayout[row - 1][y] != 'O' && planeLayout[row - 1][y] != 'X') {
			cout << "That ain't a seat (idiot)";
			Sleep(1000);
			main();
		}

		// checks if the seat has already been bought
		else if (planeLayout[row - 1][y] == 'X') {
			cout << "That seat is already taken";
			Sleep(1000);
			main();
		}

		// if valid seat, they are charged and the seat is marked as taken with an 'X'
		else {
			planeLayout[row - 1][y] = 'X'; // replaces O with X

			// finds which class they bought and charges them
			if (row <= 2) { // first class
				subtotal += 5921;
				x++;
				seatsOrdered[x] = 1;
			}
			else if (row >= 3 && row <= 5) { // business class
				subtotal += 2221;
				x++;
				seatsOrdered[x] = 2;
			}
			else if (row >= 5) { // economy class
				subtotal += 36;
				x++;
				seatsOrdered[x] = 3;
			}
		}
		printMenu();
		cout << "Would you like to buy another seat? y/n" << endl;

		while (keep) {
			cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				main();
			}
			else if (choice == 'n' || choice == 'N') {
				cout << "Have a nice day";
				Sleep(1000);
				pay();
			}
			else {
				cout << "Invalid input, try again" << endl;
			}
		}
	} while (!end);

	cin >> hold;
	return 0;
}

void pay() {
	int hold;
	system("CLS");
	if (subtotal <= 0) {
		cout << "You didn't buy anything! Get out!";
		cin >> hold;
	}
	else {
		cout << "**********************************************" << endl;
		//prints an item to the receipt as long as x doesn't equal 0
		while (x != 0) {
			//each if/else if checks which number is stored in seatsOrdered and prints the corresponding menu item to the reciept
			if (seatsOrdered[x] == 1) {
				cout << "* First class                   " << fixed << setprecision(2) << "$" << setw(10) << "5921" << "  *" << endl;
				x--;
			}
			else if (seatsOrdered[x] == 2) {
				cout << "* Business class                " << fixed << setprecision(2) << "$" << setw(10) << "2221" << "  *" << endl;
				x--;
			}
			else if (seatsOrdered[x] == 3) {
				cout << "* Economy class                 " << fixed << setprecision(2) << "$" << setw(10) << "36" << "  *" << endl;
				x--;
			}
			else {
				x--;
			}
		}
		cout << "* Sub-total                     " << fixed << "$" << setprecision(2) << setw(10) << subtotal << "  *" << endl;

		//calculates random tax
		double tax = 0.42;
		cout << "* Tax is                        " << setw(10) << tax << "%" << "  *" << endl;

		//calculates total
		ftotal = subtotal + subtotal * tax;
		cout << "* Total is                      " << fixed << setprecision(2) << "$" << setw(10) << ftotal << "  *" << endl;
		cout << "**********************************************" << endl;
	}
}
void printMenu() { // prints the table "plane layout"
	int y = 0;
	int row = 0;
	char column = ' ';

	system("CLS");

	for (int yCount = 0; yCount <= 9; yCount++) { // for loop for making rows
		if (yCount >= 1)
			cout << "Row " << setw(2) << yCount << setw(5);
		else
			cout << setw(11);

		for (int xCount = 0; xCount < 4; xCount++) { // for loop for making columns
			if (yCount == 0) { // makes the top row as the name of the column
				// if/else if statements translates y from a letter into a number
				if (xCount == 0)
					cout << setw(12) << "A ";
				else if (xCount == 1)
					cout << "B ";
				else if (xCount == 2)
					cout << "C ";
				else if (xCount == 3)
					cout << "D ";
			}
			// continues making the plane layout
			if (yCount >= 1)
				cout << planeLayout[yCount-1][xCount] << " ";
		}
		// writes the different classes on the right side
		if (yCount == 1)
			cout << "\tFirst Class, this row and below $5921 per ticket";
		else if (yCount == 4)
			cout << "\tBusiness Class, this row and below, $2221 per ticket";
		else if (yCount == 7)
			cout << "\tEconomy Class (Couches), this row and below $36 per ticket";
		cout << endl;
	}
	cout << "Type the seat you want, \"+\" are tables, \"-\" are empty spaces and \"O\" are seats(type the row first, then the column, and put a space between your row and column)" << endl;
	// buySeats(row, column, y);
}
