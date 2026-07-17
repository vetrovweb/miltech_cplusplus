//
// Created by Кирило Вєтров on 10.07.2026.
//
#include <iostream>

int maxNumber(int a, int b) {
    int max;
    if (a > b) {
        max = a;            //return a > b ? a : b;
    }
    else {
        max = b;
    }
    return max;
}

int main() {

    int res;
    res = maxNumber(5, 6);
    std::cout << "Більше число: " << res << std::endl;

    return 0;
}