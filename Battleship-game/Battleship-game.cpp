#include <iostream>
#include "Battleship.h"
#include <conio.h>
using namespace std;
int main()
{
	srand(time(NULL));
	//int sum = 0;
	Battleship I, Enemy;
	I.placingShips();
	Enemy.placingShips();
	//cout<<I.placingShips();
	//cout<<I.ship_rotate();

	while (true) {
		cout << "\tENEMY SHIP" << endl;
		I.printMap();
		I.hittingTarget();
		system("cls");
		cout << "\tMY SHIP" << endl;
		Enemy.printMapEnemy();
		Enemy.hittingTargetEnemy();
		if (I.getSum() == 0)break;
		if (Enemy.getSum() == 0)break;
	}
	if (I.getSum() == 0)cout << "You win!!!!!!!!" << endl;
	if (Enemy.getSum() == 0)cout << "You lost!!!!!!!!" << endl;
	else {
		cout << "Game over" << endl;
	}
}