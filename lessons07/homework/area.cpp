//
// Created by Кирило Вєтров on 10.07.2026.
//
#include <iostream>

double rectangleArea(double width, double height) {
    return width * height;
}

int main() {

    double res;
    res = rectangleArea(5, 6);
    std::cout << "Площа: " << res << std::endl;

    return 0;
}