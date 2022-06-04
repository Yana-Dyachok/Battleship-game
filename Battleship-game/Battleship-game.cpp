#include <iostream>
#include "Battleship.h"
#include <conio.h>
using namespace std;
int main()
{
	char chose;//змінна вибору методу розташування кораблів
	srand(time(NULL));
	Battleship I, Enemy;//об'єкти класу Battleship, де I-відповідає гравцю, Enemy-противнику-комп'ютеру
	cout << "Hi!Welcome to Battleship. Let's play a game" << endl;
	Enemy.placingShips();//розташування кораблів противника
	cout << "Choose the way ships are arranged: 1- randomly or 2-place yourself" << endl;
	cin >> chose;//вибір методу розташування
	switch (chose) {
	case '1':I.placingShips(); break;//розташування кораблів гравця рандомно
	case '2':I.placingShipsMyself(); break;//розташування кораблів гравця самостійно
	default: cout << "That was a bad chose, please try again"<<endl; break;
	}
	while (true) {
		cout << "\tMY SHIP" << endl;
		I.printMapEnemy();//вивід грального поля гравця
		I.hittingTargetEnemy();//постріл противника
		cout << "\tENEMY SHIP" << endl;
		Enemy.printMap();//вивід грального поля противника
		Enemy.hittingTarget();//постріл гравця 
		system("cls");//очищення екрану косолі 
		if (I.getSum() == 0)break;//якщо кількість кораблів рівна нулю - гра закінчується
		if (Enemy.getSum() == 0)break;
	}
	if (I.getSum() == 0)cout << "Congratulations!!You win!!!!!!!!" << endl;//якщо кількість кораблів закінчиться -виграв гравець
	if (Enemy.getSum() == 0)cout << "You lost!!!!!!!!" << endl;//якщо кількість кораблів закінчиться -виграв противник
	cout << "Game over" << endl;
}
