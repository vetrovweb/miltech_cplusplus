//
// Created by Кирило Вєтров on 31.05.2026.
// Калькулятор знижок за промокодом (int + float + char)
//

#include <iostream>
#include <string>               // Обов'язкова бібліотека для роботи з рядками
#include <iomanip>              // Для того, щоб вивести float з фіксованою кількістю знаків після коми,
int main() {
    using namespace std;

    float price = 500;       // start price
    char userType{};
    bool hasCoupon = false;
    float discount{};
    float discountCoupon{};
    float total{};
    string promokodTXT;

    cout << "Введіть тип покупця (S/P/R): ";
    cin >> userType;

    if (userType == 'S' || userType == 's') {
        // студент, 10%
        discount = price * 0.1;
        total = price - discount;
        promokodTXT = "студентa (10%)";
    }
    else if (userType == 'P' || userType == 'p') {
        // пенсіонер, 15%
        discount = price * 0.15;
        total = price - discount;
        promokodTXT = "пенсіонера (15%)";
    }
    else if (userType == 'R' || userType == 'r') {
        // звичайний покупець, 0%
        total = price;
        promokodTXT = "0%";
    }
    else {
        cout << "Не існуючий промокод!" << endl;
        return 0;
    }

    cout << "Маєте купон? (1 - так, 0 - ні): ";
    cin >> hasCoupon;
    if (hasCoupon) {
        discountCoupon = 50;
        total = total - discountCoupon;
    }

    // Налаштовуємо вивід: фіксована точка та 2 знаки після коми
    cout << fixed << setprecision(2);
    cout << "Початкова ціна: " << price << endl;
    cout << "Знижка "<< promokodTXT << ": -" << discount << endl;
    cout << "Знижка за купон: -" << discountCoupon << endl;
    cout << "До сплати: "<< total << endl;
    return 0;
}