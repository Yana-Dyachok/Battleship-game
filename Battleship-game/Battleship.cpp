#include <iostream>
#include <ctime>
#include <conio.h>
#include "Battleship.h"
using namespace std;
Battleship::Battleship() {
    this->x = 0;
    this->y = 0;
    this->sum = 0;
    this->n = 10;
    this->map = nullptr;
    this->map = new char* [n];
    for (int i = 0; i < n; i++)
    {
        map[i] = new char[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] = '.';
        }
    }
}


void Battleship::hittingTarget() {
    std::cout << "Enter coordinates x and y:" << endl;
    cin >> x;
    cin >> y;
    if (this->map[this->x - 1][this->y - 1] == 'A') {
        cout << "You hit the target" << endl;
        this->map[this->x - 1][this->y - 1] = '#';
        sum--;
    }
    else {
        this->map[this->x - 1][this->y - 1] = '*';
        cout << "You missed" << endl;
    }
}


void Battleship::hittingTargetEnemy() {
    std::cout << "Enemy step:" << endl;
    x = rand() % n;
    y = rand() % n;
    if (this->map[this->x][this->y] == 'A') {
        cout << "Enemy hit the target" << endl;
        this->map[this->x][this->y] = '#';
        sum--;
    }
    else {
        this->map[this->x][this->y] = '*';
        cout << "Enemy missed" << endl;
    }
}

void Battleship::placingShips() {
    for (int i = 0; i < 10; i++)
    {
        x = rand() % n;
        y = rand() % n;
        this->map[x][y] = 'A';
        sum++;//ï³äðàõóíîê êîðàáë³â
    }
}
void Battleship::placingShips() {
    for (int i = 0; i < 1; i++)
    {
        x = rand() % n;
        y = rand() % n;
        this->map[x][y] = 'A';
        this->map[x + 1][y] = 'A';
        this->map[x + 2][y] = 'A';
        this->map[x + 3][y] = 'A';
        sum++;//підрахунок кораблів
    }
    for (int i = 0; i < 2; i++)
    {
        x = rand() % n;
        y = rand() % n;
            this->map[x][y] = 'A';
            this->map[x][y - 1] = 'A';
            this->map[x][y - 2] = 'A';
            sum++;//підрахунок кораблів
    }
    for (int i = 0; i < 3; i++)
    {
        x = rand() % n;
        y = rand() % n;
            this->map[x][y] = 'A';
            this->map[x + 1][y] = 'A';
            sum++;//підрахунок кораблів
    }

   
    for (int i = 0; i < 4; i++)
    {
        x = rand() % n;
        y = rand() % n;
            this->map[x][y] = 'A';
            sum++;//підрахунок кораблів    
    }
}


Battleship::~Battleship() {
    for (int i = 0; i < n; i++)
    {
        delete[]this->map[i];
    }
    delete[]this->map;
}


void Battleship::printMap() {// ôóíêö³ÿ âèâîäó ãðàëüíîãî ïîëÿ
    cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
    int y = 1;
    for (int i = 0; i < n; i++)
    {
        if (y == 10)
            cout << y << " ";
        else
            cout << y << "  ";
        y++;
        for (int j = 0; j < n; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void Battleship::printMapEnemy() {// ôóíêö³ÿ âèâîäó ãðàëüíîãî ïîëÿ
    cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
    int y = 1;
    for (int i = 0; i < n; i++)
    {
        if (y == 10)
            cout << y << " ";
        else
            cout << y << "  ";
        y++;
        for (int j = 0; j < n; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}
