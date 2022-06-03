#include <iostream>
#include "Battelship.h"
#include <conio.h>
using namespace std;
int main()
{
	srand(time(NULL));
	Battleship I, Enemy;
	Enemy.placingShips();
	I.placingShips();
	cout << "Hi!Welcome to Battleship. Let's play a game" << endl;
	while (true) {
		cout << "\tMY SHIP" << endl;
		I.printMapEnemy();
		I.hittingTargetEnemy();
		cout << "\tENEMY SHIP" << endl;
		Enemy.printMap();
		Enemy.hittingTarget();
		system("cls");
		if (I.getSum() == 0)break;
		if (Enemy.getSum() == 0)break;
	}
	if (I.getSum() == 0)cout << "Congratulations!!You win!!!!!!!!" << endl;
	if (Enemy.getSum() == 0)cout << "You lost!!!!!!!!" << endl;
	cout << "Game over" << endl;
}
