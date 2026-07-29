//
// Created by Кирило Вєтров on 18.06.2026.
//
#include <iostream>

int main() {
    using namespace std;

    for (int i = 1; i <= 20; i++) {
        if (i%3 == 0) {
            continue;
        }
        cout << i << endl;
    }

    return 0;
}