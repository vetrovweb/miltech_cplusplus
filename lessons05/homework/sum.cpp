//
// Created by Кирило Вєтров on 18.06.2026.
//
#include <iostream>

int main() {
    using namespace std;
    int number{};

    for (int i = 1; i <= 50; i++) {
        if (i%2 == 0) {
            number += i;
        }
    }
    cout << number << endl;

    return 0;
}