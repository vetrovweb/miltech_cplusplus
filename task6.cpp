//
// Created by Кирило Вєтров on 29.05.2026.
//
#include <iostream>
#include <limits>

int main() {


    short x = 32767;

    std::cout << "short x = " << x << std::endl;
    x = x + 1;
    std::cout << "x = x + 1 --- " << x << std::endl;
    return 0;
}