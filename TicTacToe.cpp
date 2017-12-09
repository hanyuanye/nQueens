#include "Game.h"
#include <iostream>

using namespace std;

int main()
{
	int player;
	cout << "Enter 1 to go first and enter 2 to go second." << endl;
	cin >> player;
	Game game;
	game.gamePlay(player);
}