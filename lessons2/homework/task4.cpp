//
// Created by Кирило Вєтров on 25.05.2026.
//
#include <iostream>

int main() {

    int a{};
    int b{};

    std::cout << "Введіть два числа:";
    std::cin >> a;
    std::cin >> b;
    std::cout << "Було: а = " << a << ", b = " << b << std::endl;
    std::cout << "Стало: а = " << b << ", b  = " << a << std::endl;

    return 0;
}