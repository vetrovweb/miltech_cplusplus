//
// Created by Кирило Вєтров on 05.06.2026.
//
#include <iostream>

int main() {
    using namespace std;

    //int x{};
    //cin >> x;

    // switch (x) {
    //     case 1:
    //         cout << 1 << endl;
    //         break;
    //     case 2:
    //         cout << 2 << endl;
    //         break;
    //     case 3:
    //         cout << 3 << endl;
    //         break;
    //     case 4:
    //         cout << 4 << endl;
    //         break;
    //     case 5:
    //         cout << 5 << endl;
    //         break;
    //     default:
    //         cout << "Default none" << endl;
    //         break;
    //}

    // double firstNum{0};
    // double secondNum{0};
    // char symbol;
    //
    // cout << "Введіть перше число: ";
    // cin >> firstNum;
    // cout << "Введіть друге число: ";
    // cin >> secondNum;
    // cout << "Введіть символ: ";
    // cin >> symbol;
    //
    //  switch (symbol) {
    //      case '+':
    //          firstNum += secondNum;
    //          cout << firstNum << endl;
    //          break;
    //      case '-':
    //          firstNum -= secondNum;
    //          cout << firstNum << endl;
    //          break;
    //      case '*':
    //          firstNum *= secondNum;
    //          cout << firstNum << endl;
    //          break;
    //      case '/':
    //          firstNum /= secondNum;
    //          cout << firstNum << endl;
    //          break;
    //      default:
    //          cout << "Некоректний символ!" << endl;
    //          break;
    // }

    int i{}, spaces{};

    cout << "Введіть улюблене число: ";
    cin >> i;

    while (i >= 0) {

        // 1. Виводимо потрібну кількість табуляцій для поточного рівня
        for (int j = 0; j < spaces; j++) {
            cout << '\t';
        }

        cout << i << endl;
        i--;
        spaces++;
    }

    return 0;
}