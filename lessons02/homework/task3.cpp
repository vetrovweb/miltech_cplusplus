//
// Created by Кирило Вєтров on 25.05.2026.
//
#include <iostream>

int main() {

    int a{};
    int b{};
    int sum{}, riz{}, dob{};

    std::cout << "Введіть два числа: ";
    std::cin >> a;
    std::cin >> b;

    sum = a + b;
    riz = a - b;
    dob = a * b;

    std::cout << "Сума: " << sum << std::endl;
    std::cout << "Різниця: " << riz << std::endl;
    std::cout << "Добуток: " << dob << std::endl;

    return 0;
}