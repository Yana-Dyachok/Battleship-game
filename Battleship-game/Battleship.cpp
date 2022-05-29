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
    x = rand() % n + 1;
    y = rand() % n + 1;
    if (this->map[this->x - 1][this->y - 1] == 'A') {
        cout << "Enemy hit the target" << endl;
        this->map[this->x - 1][this->y - 1] = '#';
        sum--;
    }
    else {
        this->map[this->x - 1][this->y - 1] = '*';
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
    int mapX [20];
    int mapY[20];
    for (int i = 0; i < 1; i++)
    {
        x = rand() % n;
        y = rand() % n;
        this->map[x][y] = 'A';
        this->map[x + 1][y] = 'A';
        this->map[x + 2][y] = 'A';
        this->map[x + 3][y] = 'A';
        sum++;//підрахунок кораблів
        mapX[i] = x;
        mapY[i] = y;
        mapY[i] = y - 1;
        mapY[i] = y - 2;
        mapY[i] = y - 3;

    }
    for (int i = 0; i < 2; i++)
    {
        x = rand() % n;
        y = rand() % n;

        if (mapX[i] != x and mapY[i] != y) {
            this->map[x][y] = 'A';
            this->map[x][y - 1] = 'A';
            this->map[x][y - 2] = 'A';
            sum++;//підрахунок кораблів
            mapX[i] = x;
            mapY[i] = y;
            mapY[i] = y - 1;
            mapY[i] = y - 2;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        x = rand() % n;
        y = rand() % n;
        if (mapX[i] != x and mapY[i] != y) {
            this->map[x][y] = 'A';
            this->map[x + 1][y] = 'A';
            sum++;//підрахунок кораблів
            mapX[i] = x;
            mapX[i] = x+1;
            mapY[i] = y;
        }
    }

   
    for (int i = 0; i < 4; i++)
    {
        x = rand() % n;
        y = rand() % n;
        if (mapX[i] != x and mapY[i] != y) {
            this->map[x][y] = 'A';
            sum++;//підрахунок кораблі    
        }
    }
/*int Battleship::placingShips() {
    bool setting_is_possible = true;
    int dir = 0;
    int temp_x;
    int temp_y;
    while (sum < n) {
        do {
            this->x = rand() % n+1;
            this->y = rand() % n+1;

            temp_x = this->x;
            temp_y = this->y;

            dir = rand() % 4;

            setting_is_possible = true;
            for (int i = 0; i < n; ++i) {
                if (this->x < 1 || this->y < 1 || this->x > n || this->y > n) {
                    setting_is_possible = false;
                    break;
                }
                if (this->map[x][y] == 'A' ||
                    this->map[x][y + 1] == 'A' ||
                    this->map[x][y - 1] == 'A' ||
                    this->map[x + 1][y] == 'A' ||
                    this->map[x + 1][y + 1] == 'A' ||
                    this->map[x + 1][y - 1] == 'A' ||
                    this->map[x - 1][y] == 'A' ||
                    this->map[x][y] == 'A' ||
                    this->map[x][y] == 'A')
                {
                    setting_is_possible = false;
                    break;
                }
                switch (dir) {
                case 0:
                    x++;
                    break;
                case 1:
                    y++;
                    break;
                case 2:
                    x--;
                    break;
                case 3:
                    y--;
                    break;
                }
            }
        } while (setting_is_possible != 1);

        if (setting_is_possible == 1) {
            this->x = temp_x;
            this->y = temp_y;
            for (int i = 0; i < 4; ++i) {
                this->map[x][y] = 'A';
                switch (dir) {
                case 0:
                    x++;
                    break;
                case 1:
                    y++;
                    break;
                case 2:
                    x--;
                    break;
                case 3:
                    y--;
                    break;

                }
            }
        }
        sum++;
    }
    return this->map[n][n];
}


int Battleship::ship_rotate() {
    int ship_rate = 4;
    int ship_count = 1;
    placingShips();
    --ship_rate;
    ++ship_count;
    placingShips();
    --ship_rate;
    ++ship_count;
    placingShips();
    --ship_rate;
    ++ship_count;
    placingShips();
    return this->map[n][n];
}
*/

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
