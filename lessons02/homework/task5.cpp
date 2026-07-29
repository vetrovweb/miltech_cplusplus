//
// Created by Кирило Вєтров on 25.05.2026.
//
#include <iostream>

int main() {

    int sec{};
    int res_m{}, res_h{};

    std::cout << "Введіть кількість секунд: ";
    std::cin >> sec;

    res_h = sec / 60;
    res_m = sec % 60;
    std::cout << res_h << " хв \t" << res_m << " сек" << std::endl;

    return 0;
}