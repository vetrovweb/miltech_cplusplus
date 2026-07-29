//
// Created by Кирило Вєтров on 25.05.2026.
//
#include <iostream>

int main() {

    std::cout
        << "Type short takes: " << sizeof(short) << " bytes.\n"
        << "Type short takes: " << sizeof(int) << " bytes.\n"
        << "Type short takes: " << sizeof(long) << " bytes.\n"
        << "Type short takes: " << sizeof(long long) << " bytes.\n"
    << std::endl;

    return 0;
}