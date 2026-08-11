//
// Created by Кирило Вєтров on 07.08.2026.
//

#include <iostream>
#include <vector>

using namespace std;

void movePlayer(vector<vector<char>>& new_field, int& x, int& y, int& step, char move, int& coins) {
    // Питаємо що попереду і якщо можна, заміняємо місцями символи
    switch (move) {
        case 'w':
            if (new_field[x-1][y] == '.') {
                new_field[x][y] = '.';
                x--;
                new_field[x][y] = 'P';
                // Постійно оновлюємо (не залежно від напрямку)
                step++;
            }
            // рахуємо кроки, навіть якщо не можна йти
            else if (new_field[x-1][y] == '#') {
                step++;
            }
            else if (new_field[x-1][y] == '$') {
                new_field[x][y] = '.';
                x--;
                new_field[x][y] = 'P';
                step++;
                coins++;
            }
            else if (new_field[x-1][y] == 'E') {
                new_field[x-1][y] = '.';
                x--;
                new_field[x][y] = 'P';
                step++;
                cout << "You Win! Congratulations!" << endl;
            }
        break;

        case 'a':
            if (new_field[x][y-1] == '.') {
                new_field[x][y] = '.';
                y--;
                new_field[x][y] = 'P';
                step++;
            }
            else if (new_field[x][y-1] == '#') {
                step++;
            }
            else if (new_field[x][y-1] == '$') {
                new_field[x][y] = '.';
                y--;
                new_field[x][y] = 'P';
                step++;
                coins++;
            }
            else if (new_field[x][y-1] == 'E') {
                new_field[x][y-1] = '.';
                y--;
                new_field[x][y] = 'P';
                step++;
                cout << "You Win! Congratulations!" << endl;
            }
        break;

        case 's':
            if (new_field[x+1][y] == '.') {
                new_field[x][y] = '.';
                x++;
                new_field[x][y] = 'P';
                step++;
            }
            else if (new_field[x+1][y] == '#') {
                step++;
            }
            else if (new_field[x+1][y] == '$') {
                new_field[x][y] = '.';
                x++;
                new_field[x][y] = 'P';
                // Постійно оновлюємо (не залежно від напрямку)
                step++;
                coins++;
            }
            else if (new_field[x+1][y] == 'E') {
                new_field[x][y] = '.';
                x++;
                new_field[x][y] = 'P';
                // Постійно оновлюємо (не залежно від напрямку)
                step++;
                cout << "You Win! Congratulations!" << endl;
            }
        break;

        case 'd':
            if (new_field[x][y+1] == '.') {
                new_field[x][y] = '.';
                y++;
                new_field[x][y] = 'P';
                step++;
            }
            else if (new_field[x][y+1] == '#') {
                step++;
            }
            else if (new_field[x][y+1] == '$') {
                new_field[x][y] = '.';
                y++;
                new_field[x][y] = 'P';
                // Постійно оновлюємо (не залежно від напрямку)
                step++;
                coins++;
            }
            else if (new_field[x][y+1] == 'E') {
                new_field[x][y] = '.';
                x++;
                new_field[x][y] = 'P';
                // Постійно оновлюємо (не залежно від напрямку)
                step++;
                cout << "You Win! Congratulations!" << endl;
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
    char control;                                                                   // кнопка
    int coins = 0;                                                                  // монети

    // ----------------------------------------------------------------------------
    // Playing field
    // ----------------------------------------------------------------------------
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
    // ============================================================================

    // Виведення динамічного масиву типу матриця
    // Add function showing
    Show(playingField);


    // ----------------------------------------------------------------------------
    // Переміщення гравця P
    // ----------------------------------------------------------------------------
    while (cin >> control) {
        switch (control) {

            // up
            case 'w':
                movePlayer(playingField, x, y, step, control, coins);
                Show(playingField);
                cout << "Count steps: " << step << endl;
                cout << "Coins: " << coins << endl;
                break;

            // left
            case 'a':
                movePlayer(playingField, x, y, step, control, coins);
                Show(playingField);
                cout << "Count steps: " << step << endl;
                cout << "Coins: " << coins << endl;
                break;

            // down
            case 's':
                movePlayer(playingField, x, y, step, control, coins);
                Show(playingField);
                cout << "Count steps: " << step << endl;
                cout << "Coins: " << coins << endl;
                break;

            // right
            case 'd':
                movePlayer(playingField, x, y, step, control, coins);
                Show(playingField);
                cout << "Count steps: " << step << endl;
                cout << "Coins: " << coins << endl;
                break;

            //case 9: return 0;
            //default: cout << "Введіть правильний пункт: \n"; break;
        }
    }
    // ============================================================================

    return 0;
}