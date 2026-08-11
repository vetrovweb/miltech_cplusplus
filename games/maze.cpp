//
// Created by Кирило Вєтров on 07.08.2026.
//

#include <iostream>
#include <vector>

using namespace std;

void movePlayer(vector<vector<char>>& new_field, int& x, int& y, int& step, char move) {
    // Питаємо що попереду і якщо можна заміняємо місцями символи
    switch (move) {
        case 'w':
            if (new_field[x-1][y] == '.') {
                new_field[x][y] = '.';
                x--;
                new_field[x][y] = 'P';
                // Постійно оновлюємо (не залежно від напрямку)
                step++;
                //cout << "char - " << left << endl;
            }
            // рахуємо кроки, навіть якщо не можна йти
            else if (new_field[x-1][y] == '#') {
                step++;
            }
            break;

        case 'a':
            if (new_field[x][y-1] == '.') {
                new_field[x][y] = '.';
                y--;
                new_field[x][y] = 'P';
                // Постійно оновлюємо (не залежно від напрямку)
                step++;
                //cout << "char - " << left << endl;
            }
            // рахуємо кроки, навіть якщо не можна йти
            else if (new_field[x][y-1] == '#') {
                step++;
            }
            break;

        case 's':
            if (new_field[x+1][y] == '.') {
                new_field[x][y] = '.';
                x++;
                new_field[x][y] = 'P';
                // Постійно оновлюємо (не залежно від напрямку)
                step++;
                //cout << "char - " << left << endl;
            }
            // рахуємо кроки, навіть якщо не можна йти
            else if (new_field[x+1][y] == '#') {
                step++;
            }
            break;

        case 'd':
            if (new_field[x][y+1] == '.') {
                new_field[x][y] = '.';
                y++;
                new_field[x][y] = 'P';
                // Постійно оновлюємо (не залежно від напрямку)
                step++;
                //cout << "char - " << left << endl;
            }
            // рахуємо кроки, навіть якщо не можна йти
            else if (new_field[x][y+1] == '#') {
                step++;
            }
            break;

        //default:
    }
}

void Show(vector<vector<char>>& arr) {
    for ( int i = 0; i < arr.size(); i++) {
        for ( int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
#include <array>

    // відповідно до норм MISRA C++
    //
    // constexpr std::size_t MAP_ROWS = 9U;
    // constexpr std::size_t MAP_COLS = 13U;
    //
    // constexpr std::array<std::array<char, MAP_COLS>, MAP_ROWS> map = {{
    //     {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    //     {'#', 'P', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '#'},
    //     {'#', '.', '#', '#', '.', '.', '#', '.', '.', '#', '#', '.', '#'},
    //     {'#', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '#'},
    //     {'#', '#', '#', '.', '.', '.', '.', '.', '#', '#', '#', '.', '#'},
    //     {'#', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '#'},
    //     {'#', '.', '.', '$', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
    //     {'#', '.', '#', '#', '#', '#', '.', '.', '#', '.', '#', 'E', '#'},
    //     {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    // }};

    int step = 0;                                                                   // рахунок ходів (кроків)
    int x = 1, y = 1;                                                               // початкові координати гравця

    // ------------------------------------------------------------------------------
    // Playing field
    // ------------------------------------------------------------------------------
    vector <vector<char>> playingField {
        {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', 'P', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '#'},
            {'#', '.', '#', '#', '.', '.', '#', '.', '.', '#', '#', '.', '#'},
            {'#', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '#'},
            {'#', '#', '#', '.', '.', '.', '.', '.', '#', '#', '#', '.', '#'},
            {'#', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '#'},
            {'#', '.', '.', '$', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
            {'#', '.', '#', '#', '#', '#', '.', '.', '#', '.', '#', 'E', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
        }
    };

    // Виведення динамічного масиву типу матриця
    // Add function showing
    Show(playingField);

    // Інший варіант виведення даних
    // ...


    // Переміщення гравця P
    char control;
    while (cin >> control) {
        switch (control) {
            // up
            case 'w':
                //cout << 'w';
                movePlayer(playingField, x, y, step, control);
                Show(playingField);
                cout << "Count steps: " << step << endl;
                break;

                // left
            case 'a':
                //cout << 'a';
                movePlayer(playingField, x, y, step, control);
                Show(playingField);
                cout << "Count steps: " << step << endl;
                break;

                // down
            case 's':
                //cout << 's';
                movePlayer(playingField, x, y, step, control);
                Show(playingField);
                cout << "Count steps: " << step << endl;
                break;

                // right
            case 'd':
                //bool flag = false;

                //int x = 0, y = 1;
                movePlayer(playingField, x, y, step, control);
                Show(playingField);
                cout << "Count steps: " << step << endl;

                break;

            //case 9: return 0;
            //default: cout << "Введіть правильний пункт: \n"; break;
        }

    }

    return 0;
}