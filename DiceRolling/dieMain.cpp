/*
	Name: Urmomanym
	Date: 11.5.18
	Description: The user program that uses class die
*/

#include <iostream>
#include "die.h" //class file inclusion

using namespace std;

const int NUMOFDIE = 10;

int main()
{
	int hold;
	die diceList[NUMOFDIE];//class array
	int numOfDiceRolled;
	int sum;
	int desiredSum;

	int minDiceSum;
	int maxDiceSum;

	int desiredSumCount = 0;

	minDiceSum = NUMOFDIE;
	maxDiceSum = 6 * NUMOFDIE;

	cout << "Enter the nmber of times the dice are to be rolled: ";
	cin >> numOfDiceRolled;
	cout << endl;

	cout << " Enter the desired sum of the dice, between "
		<< minDiceSum << " and " << maxDiceSum << " (inclusive): ";
	cin >> desiredSum;
	cout << endl;

	while (desiredSum < minDiceSum || desiredSum > maxDiceSum)//confirms that their choice was valid
	{
		cout << "The desired sum should be between " << minDiceSum << " and " << maxDiceSum;
		cout << "Reenter the desired sum of the dice: ";
		cin >> desiredSum;
		cout << endl;
	}

	for (int rollCount = 1; rollCount <= numOfDiceRolled; rollCount++)//goes through each die
	{
		sum = 0;

		for (int dieCount = 0; dieCount < NUMOFDIE; dieCount++)//rolls each die the right amount
		{
			diceList[dieCount].roll();
			sum = sum + diceList[dieCount].getNum();
		}

		if (sum == desiredSum)
			desiredSumCount++;
	}

	cout << "The number of times the desired sum occured: " << desiredSumCount << endl;
	
	cin >> hold;
	return 0;
}