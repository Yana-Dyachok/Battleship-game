#include "Battleship.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;
Battleship::Battleship() {//конструктор
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
    this->mapE = nullptr;
    this->mapE = new char* [n];
    for (int i = 0; i < n; i++)
    {
        mapE[i] = new char[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mapE[i][j] = '.';
        }
    }
}


void Battleship::hittingTarget() {// метод для попадання в ціль гравцем
    std::cout << "Enter coordinates x and y:" << endl;
    cin >> this->x;//користувач-гравець вводить координати
    cin >> this->y;
    if ((this->x > 10 or this->x < 1) or (this->y > 10 or this->y < 1)) {
        do {//при неправильному введенні координат, запускається цикл-поки користувач не введе правильно
            cout << "Wrong coordinates, try again: ";
            cin >> this->x;
            cin >> this->y;
        } while ((this->x > 10 or this->x < 1) or (this->y > 10 or this->y < 1));
    }
    if (this->map[this->x - 1][this->y - 1] == 'A') {// при попаданні в ціль
        cout << "You hit the target" << endl;
        this->mapE[this->x - 1][this->y - 1] = '#';//змінюється знак відповідних координат в масиві на '#'
        sum--;//при попаданні в ціль віднімається число від суми решти кораблів
    }
    else {
        this->mapE[this->x - 1][this->y - 1] = '*';//змінюється знак відповідних координат в масиві на '*' при непопаданні в ціль
        cout << "You missed" << endl;
    }
    Sleep(500);//затримання виконання програми в консолі на 500мс
}


void Battleship::hittingTargetEnemy() {// метод для попадання в ціль противником
    std::cout << "Enemy step:" << endl;
    this->x = rand() % n;//рандомне попадання в ціль
    this->y = rand() % n;
    if (this->map[this->x][this->y] == 'A') {// при попаданні в ціль 
        cout << "Enemy hit the target" << endl;
        this->map[this->x][this->y] = '#';//змінюється знак відповідних координат в масиві на '#'
        sum--;//при попаданні в ціль віднімається число від суми решти кораблів
    }
    else {
        this->map[this->x][this->y] = '*';//змінюється знак відповідних координат в масиві на '*' при непопаданні в ціль
        cout << "Enemy missed" << endl;
    }
}


void Battleship::placingShipsMyself() {//метод самостійного розташування кораблів
    char chose;//змінна вибору напрямку розташування
    while (sum < 10) {
        for (int i = 0; i < 1; i++)//розташування чотирьохпалубних кораблів
        {
            cout << "Enter coordinates x and y for four-deck ship:" << endl;
            cin >> this->x;
            cin >> this->y;
            cout << "Select a direction, enter 1 for vertical and 2 for horizontal::" << endl;
            cin >> chose;
            switch (chose) {
            case '1'://вертикальний напрямок розташування
                this->map[this->x - 1][this->y - 1] = 'A';
                this->map[this->x][this->y - 1] = 'A';
                this->map[this->x + 1][this->y - 1] = 'A';
                this->map[this->x + 2][this->y - 1] = 'A'; break;
            case '2'://горизонтальний напрямок розташування
                this->map[this->x - 1][this->y - 1] = 'A';
                this->map[this->x - 1][this->y] = 'A';
                this->map[this->x - 1][this->y + 1] = 'A';
                this->map[this->x - 1][this->y + 2] = 'A'; break;
            default: cout << "That was a bad direction please try again" << endl; continue;
            }
            sum++;//підрахунок кораблів
        }
        printMapEnemy();
        for (int i = 0; i < 2; i++)//розташування трьохпалубних кораблів
        {
           cout << "Enter coordinates x and y for three-deck ship:" << endl;
            cin >> this->x;
            cin >> this->y;
            cout << "Select a direction, enter 1 for vertical and 2 for horizontal::" << endl;
            cin >> chose;
            switch (chose) {
            case '1'://вертикальний напрямок розташування
                this->map[this->x - 1][this->y - 1] = 'A';
                this->map[this->x][this->y - 1] = 'A';
                this->map[this->x + 1][this->y - 1] = 'A'; break;
            case '2'://горизонтальний напрямок розташування
                this->map[this->x - 1][this->y - 1] = 'A';
                this->map[this->x - 1][this->y] = 'A';
                this->map[this->x - 1][this->y + 1] = 'A'; break;
            default: cout << "That was a bad direction please try again" << endl; continue;
            }
            sum++;//підрахунок кораблів
            printMapEnemy();
        }
        for (int i = 0; i < 3; i++)//розташування двохпалубних кораблів
        {
            cout << "Enter coordinates x and y for two-deck ship:" << endl;
            cin >> this->x;
            cin >> this->y;
            cout << "Select a direction, enter 1 for vertical and 2 for horizontal::" << endl;
            cin >> chose;
            switch (chose) {
            case '1'://вертикальний напрямок розташування
                this->map[this->x - 1][this->y - 1] = 'A';
                this->map[this->x][this->y - 1] = 'A'; break;
            case '2'://горизонтальний напрямок розташування
                this->map[this->x - 1][this->y - 1] = 'A';
                this->map[this->x - 1][this->y] = 'A'; break;
            default: cout << "That was a bad direction please try again" << endl; continue;
            }
            sum++;//підрахунок кораблів
            printMapEnemy();
        }
            for (int i = 0; i < 4; i++)//розташування однопалубних кораблів
            {
                cout << "Enter coordinates x and y for one-deck ship:" << endl;
                cin >> this->x;
                cin >> this->y;
                this->map[this->x - 1][this->y - 1] = 'A';
                sum++;//підрахунок кораблів
                printMapEnemy();
            }
            system("cls");
        }
    }


void Battleship::placingShips() {//рандомне розташування кораблів
    for (int i = 0; i < 1; i++)//розташування чотирьохпалубних кораблів
    {
        do {
            this->x = rand() % n;
            this->y = rand() % n;
        } while ((this->x + 3 < 0) or (this->x + 3) > n);
        this->map[this->x][this->y] = 'A';
        this->map[this->x + 1][this->y] = 'A';
        this->map[this->x + 2][this->y] = 'A';
        this->map[this->x + 3][this->y] = 'A';
        sum++;//підрахунок кораблів
    }
    while (sum < 3) {
        for (int i = 0; i < 2; i++)//розташування трьохпалубних кораблів
        {
            do {
                this->x = rand() % n;
                this->y = rand() % n;
            } while ((this->y - 2) < 0 or (this->y - 2) > n);
            if (this->map[this->x][this->y] == 'A' and
                this->map[this->x][this->y - 1] == 'A' and
                this->map[this->x][this->y - 2] == 'A' and
                this->map[this->x][this->y - 3] == 'A' and
                this->map[this->x][this->y + 1] == 'A' and
                this->map[this->x - 1][this->y] == 'A' and
                this->map[this->x - 1][this->y + 1] == 'A' and
                this->map[this->x - 1][this->y - 1] == 'A' and
                this->map[this->x - 1][this->y - 2] == 'A' and
                this->map[this->x - 1][this->y - 3] == 'A' and
                this->map[this->x + 1][this->y] == 'A' and
                this->map[this->x + 1][this->y + 1] == 'A' and
                this->map[this->x + 1][this->y - 1] == 'A' and
                this->map[this->x + 1][this->y - 2] == 'A' and
                this->map[this->x + 1][this->y - 3] == 'A') {
                continue;
            }
            else {
                this->map[this->x][this->y] = 'A';
                this->map[this->x][this->y - 1] = 'A';
                this->map[this->x][this->y - 2] = 'A';
                sum++;//підрахунок кораблів
            }
        }
    }
    while (sum < 6) {
        for (int i = 0; i < 3; i++)//розташування двохпалубних кораблів
        {
            do {
                this->x = rand() % n;
                this->y = rand() % n;
            } while ((this->x + 1) < 0 or (this->x + 1) > n);
            if (this->map[this->x][this->y] == 'A' and
                this->map[this->x][this->y - 1] == 'A' and
                this->map[this->x][this->y + 1] == 'A' and
                this->map[this->x - 1][this->y] == 'A' and
                this->map[this->x - 1][this->y + 1] == 'A' and
                this->map[this->x - 1][this->y - 1] == 'A' and
                this->map[this->x + 1][this->y] == 'A' and
                this->map[this->x + 1][this->y + 1] == 'A' and
                this->map[this->x + 1][this->y - 1] == 'A' and
                this->map[this->x + 2][this->y] == 'A' and
                this->map[this->x + 2][this->y - 1] == 'A' and
                this->map[this->x + 2][this->y + 1] == 'A') {
                continue;
            }
            else {
                this->map[this->x][this->y] = 'A';
                this->map[this->x + 1][this->y] = 'A';
                sum++;//підрахунок кораблів
            }
        }
    }
    while (sum < 10) {
        for (int i = 0; i < 4; i++)//розташування однопалубних кораблів
        {
            this->x = rand() % n;
            this->y = rand() % n;
            if (this->x != 0 or this->x != n or this->y != 0 or this->y != n) {
                if (this->map[this->x][this->y] == 'A' and
                    this->map[this->x][this->y - 1] == 'A' and
                    this->map[this->x][this->y + 1] == 'A' and
                    this->map[this->x - 1][this->y] == 'A' and
                    this->map[this->x - 1][this->y + 1] == 'A' and
                    this->map[this->x - 1][this->y - 1] == 'A' and
                    this->map[this->x + 1][this->y] == 'A' and
                    this->map[this->x + 1][this->y + 1] == 'A' and
                    this->map[this->x + 1][this->y - 1] == 'A') {
                    continue;
                }
                else {
                    this->map[this->x][this->y] = 'A';  sum++;//підрахунок кораблів
                }
            }
            else {
                this->map[this->x][this->y] = 'A';  sum++;//підрахунок кораблів
            }
        }
    }
 }

 
Battleship::~Battleship() {//деструктор 
    for (int i = 0; i < n; i++)
    {
        delete[]this->map[i];//видаляємо масив з динамічної
    }
    delete[]this->map;
    for (int i = 0; i < n; i++)
    {
        delete[]this->mapE[i];//видаляємо масив з динамічної
    }
    delete[]this->mapE;
}


void Battleship::printMap() {// метод виводу грального поля для противника (комп'ютера)
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
            cout << mapE[i][j] << " ";
        }
        cout << "\n";
    }
}


void Battleship::printMapEnemy() {// метод виводу грального поля для гравця
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
