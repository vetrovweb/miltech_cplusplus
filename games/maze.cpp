//
// Created by Кирило Вєтров on 07.08.2026.
//

#include <iostream>
#include <vector>
//#include <array>

using namespace std;

void movePlayer(vector<vector<char>>& new_field, int& x, int& y, int& step, char move, int& coins, bool& flag_win) {
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
                new_field[x][y] = '.';
                x--;
                new_field[x][y] = 'P';
                step++;
                // your win
                flag_win = true;
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
                new_field[x][y] = '.';
                y--;
                new_field[x][y] = 'P';
                step++;
                // your win
                flag_win = true;
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
                // your win
                flag_win = true;
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
                y++;
                new_field[x][y] = 'P';
                // Постійно оновлюємо (не залежно від напрямку)
                step++;
                // your win
                flag_win = true;
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

    // відповідно до норм MISRA C++
    //
    // constexpr std::size_t MAP_ROWS = 9U;
    // constexpr std::size_t MAP_COLS = 13U;
    //
    // constexpr std::array<std::array<char, MAP_COLS>, MAP_ROWS> map = {{
    //     {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    //      ....
    //     }};

    int step = 0;                                                                   // рахунок ходів (кроків)
    int x = 1, y = 1;                                                               // початкові координати гравця
    char button;                                                                   // кнопка
    int coins = 0;                                                                  // монети
    bool flag_win = false;                                                          // флаг перемоги
    bool check = true;                                                             // якщо натискають інші клавіші

    // ----------------------------------------------------------------------------
    // Playing field
    // ----------------------------------------------------------------------------
    vector <vector<char>> playingField {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', 'P', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '#'},
            {'#', '.', '#', '#', '.', '.', '#', '.', '.', '#', '#', '.', '#'},
            {'#', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '#'},
            {'#', '#', '#', '.', '.', '.', '.', '.', '#', '#', '#', '.', '#'},
            {'#', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '#'},
            {'#', '.', '.', '$', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
            {'#', '.', '#', '#', '#', '#', '.', '.', '#', '.', '#', 'E', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
    // ============================================================================

    // Виведення динамічного масиву типу матриця
    // Add function showing
    Show(playingField);


    // ----------------------------------------------------------------------------
    // Переміщення гравця P
    // ----------------------------------------------------------------------------
    while (true) {

        cin >> button;
        if (button == 'w' || button == 'a' || button == 's' || button == 'd') {
            movePlayer(playingField, x, y, step, button, coins, flag_win);
            Show(playingField);
            cout << "Count steps: " << step << endl;
            cout << "Coins: " << coins << endl;
            if (flag_win) {
                cout << "You Win! Congratulations!" << endl;
                return 0;
            }
        }
        if (button == 'q') {
            return 0;
        }
    }
    // ============================================================================

    return 0;
}