#pragma once
class Battleship
{
private:
	int x;//координати х
	int y;//координати у
	char** map;//двовимірний масив-гральне поле 
	char** mapE;//двовимірний масив-приховане гральне поле 
	int n;//межі грального поля
	int sum;//змінна -підраховує кількість кораблів
public:
	int getX() { return this->x; }//геттери
	int getY() { return this->y; }
	int getN() { return this->n; }
	int getSum() { return this->sum; }
	void setX(int x) { this->x = x; }//сеттери
	void setY(int y) { this->y = y; }
	void setN(int n) { this->n = n; }
	void setSum(int sum) { this->sum = sum; }
	Battleship();//конструктор
	void printMap();// метод виводу грального поля для противника (комп'ютера)
	void printMapEnemy();// метод виводу грального поля для гравця
	void placingShips();//метод рандомного розташування кораблів
	void placingShipsMyself();//метод самостійного розташування кораблів
	void hittingTarget();// метод для попадання в ціль гравцем
	void hittingTargetEnemy();// метод для попадання в ціль противником
	~Battleship();//деструктор
};
