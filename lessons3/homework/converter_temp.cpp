//
// Created by Кирило Вєтров on 03.06.2026.
//
#include <iomanip>
#include <iostream>

int main () {

    using namespace std;
    float temp{};
    char unit;
    bool isValid = true;             // false if temp = < -273,15 C / -459,67 F

    // Налаштовуємо вивід: фіксована точка та 2 знаки після коми
    // cout << fixed << setprecision(2);
    cout << "Введіть температуру та одиницю (наприклад 36.6 С): ";
    cin >> temp;
    cin >> unit;

    // Число -459.67 неможливо точно записати у двійковій системі. Коли ви вводите -459.67,
    // компілятор округлює його, і всередині пам'яті воно перетворюється на щось на кшталт -459.6700134....
    if (temp < -273.15 && unit == 'C' || temp < -459.68 && unit == 'F') {
        isValid = false;
        cout << "Помилка: Температура нижча за абсолютний нуль!" << endl;
        return 0;
    }

    if (isValid == 1 && unit == 'F') {
        temp = (temp - 32) / 1.8;
        cout << "Температура у Цельсіях: " << temp << endl;
    }
    else if (isValid == 1 && unit == 'C') {
        temp = temp * 1.8 + 32;
        cout << "Температура у Фаренгейтах: " << temp << endl;
    }
    return 0;
}