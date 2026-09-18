//
// Created by Кирило Вєтров on 13.09.2026.
//
#include <iostream>


int main() {

    int* p{};
    {
        p = new int;
    }
    *p = 5;
    std::cout << *p << std::endl;

    // for (int i = 0; i < 10000000000; i++) {
    //     int* pp = new int;
    //     std::cout << *pp << std::endl;
    // }

    // Static array
    int arr1[5];
    // Dynamic array
    int* arr2 = new int[5];

    // Consts
    int value = 5;
    const int* pvalue = &value;

    value = 7;
    //*pvalue = 10;         // error

    const int c = 10;
    //const int* p = &c;    // error
    int const* q = &c;

    q = 0;

    return 0;
}