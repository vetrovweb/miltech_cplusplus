//
// Created by Кирило Вєтров on 17.07.2026.
//
#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main() {
    //array<int, 5> arr{};

    // for (int x : arr) {
    //     cout << x << " ";
    // }

    // Реверс масиву
    // array<int, 4> arr2{1, 2, 3, 4};
    //
    // for (int x : arr2) {
    //     cout << x << " ";
    // }
    // reverse(arr2.begin(), arr2.end());
    // cout << '\n' << "-----------" << '\n';
    // for (int x : arr2) {
    //     cout << x << " ";
    // }
    //
    // // Новий стиль (C++20)
    // std::ranges::reverse(arr);
    // cout << '\n' << "-----------" << '\n';
    // for (int x : arr2) {
    //     cout << x << " ";
    // }


    // Реверс динамічного масиву
    // cout << '\n';
    // cout << '\n';
    // Введення кількості елементів з консолі
    // vector<int> arr3;
    //
    // std::cout << "Вводьте числа (0 для завершення):\n";
    // int n = 0;
    // while (cin >> n)
    // {
    //     //int n;
    //     //std::cin >> n;
    //     //if (n == 0) break;
    //     arr3.push_back(n);
    // }
    //
    // cout << '\n' << "-----------------" << '\n';
    // for (int x : arr3) { cout << x << " ";}
    //
    // reverse(arr3.begin(), arr3.end());
    //
    // cout << '\n' << "-----------------" << '\n';
    // for (int x : arr3) { cout << x << " ";}


    // Пошук другого найбільшого елемента масиву
    vector<int> arr4 = {8, 4, 5, 2, 3, 7, 9};

    for (int x: arr4) {
        cout << x << '\t';
    }

    // Index
    int max1 = 0;
    int max2 = 0;
    for (int i = 0; i < arr4.size(); i++) {
        if (arr4[i] > max1) {
            max2 = max1;
            max1 = arr4[i];
            // if (max1 > max2) {
            //
            // }
        }
    }
    cout << '\n';
    cout << "Другий набільший елемент масиву: " << max2 << endl;

    return 0;
}