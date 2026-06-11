//
// Created by Кирило Вєтров on 11.06.2026.
//
// Завдання 2. Базовий while Умова: Програма запитує у користувача число N. Виведіть усі парні числа від 1 до N включно
// за допомогою циклу while.

#include <iostream>

int main() {
    using namespace std;
    int number{};

    cout << "Введіть будь-яке ціле число: ";
    cin >> number;

    cout << "Всі парні числа від 1 до " << number << ": ";
    while (number >= 1) {
        if (number%2 == 0) {
            cout << number << "  ";
        }
        number--;
    }
    cout << endl;
    return 0;
}
