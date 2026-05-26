//
// Created by Кирило Вєтров on 25.05.2026.
//
#include <iostream>

int main() {

    int fuelLevel1;             // оголошення без ініціалізації
    int fuelLevel2 = 50;        // компілятор просить додати const до визначення типу змінної, оскільки значення не змінюється
    int fuelLevel3 {65};        // рекомендується
    int fuelLevel4 {};          // = 0

    std::cout
        << fuelLevel1 << " - без ініціалізації\n"
        << fuelLevel2 << "\t - копіювальна ініціалізація\n"
        << fuelLevel3 << "\t - універсальна\n"
        << fuelLevel4 << "\t - нульове значення\n"
    << std::endl;

    return 0;
}