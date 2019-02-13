//main program

#include <iostream>
#include <Windows.h>
#include "ticTacToe.h"

using namespace std;

int main()
{
	int hold = 0;

	ticTacToe game;
	game.play();

	cin >> hold;
	return 0;
}

