#pragma once
class Battleship
{
private:
	int x;
	int y;
	char** map;
	int n;
	int sum;
public:
	int getX() { return this->x; }
	int getY() { return this->y; }
	int getN() { return this->n; }
	int getSum() { return this->sum; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setN(int n) { this->n = n; }
	void setSum(int sum) { this->sum = sum; }
	Battleship();
	void printMap();
	void printMapEnemy();
	void placingShips();
	void hittingTarget();
	void hittingTargetEnemy();
	~Battleship();
};
