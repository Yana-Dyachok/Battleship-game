#include <iostream>
#include "Battleship.h"
#include <conio.h>
using namespace std;
int main()
{
	char chose;
	srand(time(NULL));
	Battleship I, Enemy;
	cout << "Hi!Welcome to Battleship. Let's play a game" << endl;
	Enemy.placingShips();
	cout << "Choose the way ships are arranged: 1- randomly or 2-place yourself" << endl;
	cin >> chose;
	switch (chose) {
	case '1':I.placingShips(); break;
	case '2':I.placingShipsMyself(); break;
	default: cout << "That was a bad chose, please try again"<<endl; break;
	}
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
