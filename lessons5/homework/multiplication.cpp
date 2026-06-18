//
// Created by Кирило Вєтров on 18.06.2026.
//
#include <iostream>

int main() {
    using namespace std;
    int number{};

    cout << "Введіть ціле число: ";
    cin >> number;
    for (int i = 1; i <= 10; i++) {
       cout << number << " x " << i << " = ";
       cout << number * i << endl;
    }
    // cout << "Старт" << endl;

    return 0;
}