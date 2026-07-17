//
// Created by Кирило Вєтров on 10.07.2026.
//
#include <iostream>

void isEven(int a) {
    if (a % 2) {
        std::cout << "Не парне число: " << a << std::endl;
    }
    else {
        std::cout << "Парне число: " << a << std::endl;
    }
}

int main() {

    isEven(6);
    return 0;
}