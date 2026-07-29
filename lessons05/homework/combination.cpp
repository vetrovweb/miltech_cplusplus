//
// Created by Кирило Вєтров on 18.06.2026.
//
#include <iostream>

int main() {
    using namespace std;
    int i{};

    for (;;) {
        cout << "Введіть число: ";
        cin >> i;

        if (i == 0) {
            cout << "Програму завершено" << endl;
            break;
        }
        if (i < 0) {
            continue;
        }
        else {
            cout << "Ви ввели додатне число" << endl;
            continue;
        }
    }


    return 0;
}