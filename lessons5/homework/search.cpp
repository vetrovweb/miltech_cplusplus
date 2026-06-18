//
// Created by Кирило Вєтров on 18.06.2026.
//
#include <iostream>

int main() {
    using namespace std;

    for (int i = 1; i <= 100; i++) {
        if (i%7 == 0 && i%5 == 0) {
            cout << "Число знайдене: " << i << endl;
            break;
        }
    }

    return 0;
}