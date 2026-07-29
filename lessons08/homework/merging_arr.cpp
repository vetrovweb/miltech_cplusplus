//
// Created by Кирило Вєтров on 13.07.2026.
//
#include <iostream>
//#include <vector>


int main() {
    //int arr[] = {};                                                     // нічого не знаємо про розмір тому потрібно вказати
    // нульові елементи, "arr[] = {0, 0, 0}"
    int arr1[] = {1, 3, 9};
    int arr2[] = {2, 0, 10};
    //int mediana = {};
    //int arr2[] = {2, 9, 5, -2, static_cast<int>(104.3)};
    int temp = 0;

    // Рахуємо розміри масивів окремо
    const int size1 = sizeof(arr1) / sizeof(arr1[0]);
    const int size2 = sizeof(arr2) / sizeof(arr2[0]);
    const int m = size1 + size2;

    int arr[m] = {};                                                    // якщо забрати const, то працювати не буде

    // об'єднання масивів
    // for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
    //     arr[i] = arr1[i];
    //     if (i == (sizeof(arr1) / sizeof(arr1[0])) - 1) {
    //         for (int j = 0; j < sizeof(arr2) / sizeof(arr2[0]); j++) {
    //             arr[i+1+j] = arr2[j];
    //         }
    //     }
    // }

    //std::cout << sizeof(arr1) / sizeof(arr1[0]) << std::endl;         // аналог std::size(arr1)

    // for (int i = 0; i < (sizeof(arr1) / sizeof(arr1[0])) + (sizeof(arr2) / sizeof(arr2[0])); i++) {
    //     std::cout << arr[i] << "  ";
    // }

    //
    //std::cout << '\n' << "-----------------------" << std::endl;
    //int arr3[] = {1, -3, -2, 9, 4, 8, 0, 5};
    // for (int i = 0; i < 3; i++) {
    //     std::cout << arr3[i] << '\t';
    // }
    // упорядковуємо масив від найменшого до найбільшого
    //int min = arr3[0];
    //int temp = 0;
    // int p = sizeof(arr) / sizeof(arr[0]);
    //
    // std::cout << '\n' << p << std::endl;
    // for (int i = 0; i < p; i++) {
    //     //int temp = arr3[i];                                           // 1'st element
    //     // if (arr3[i] > arr3[i + 1]) {
    //     //     temp = arr3[i];
    //     //     arr3[i] = arr3[i + 1];                                   // звіряємо перший елемент з другим і так далі
    //     //     arr3[i + 1] = temp;                                      // не забуваємо поміняти їх місцями
    //     // }
    //     for (int j = 0; j < p; j++) {
    //         if (arr3[i] < arr3[j]) {
    //             temp = arr3[i];
    //             arr3[i] = arr3[j];
    //             arr3[j] = temp;
    //         }
    //     }
    // }
    // std::cout << '\n' << std::endl;
    // for (int i = 0; i < p; i++) {
    //     std::cout << arr3[i] << '\t';
    // }
    //
    // std::cout << '\n' << "-----------------------" << std::endl;


    // ----------- Упорядковуємо і об'єднуємо масиви ------------
    //int m = (sizeof(arr1) / sizeof(arr1[0])) + (sizeof(arr2) / sizeof(arr2[0]));
    //std::cout << m << '\t' << std::endl;

    for (int i = 0; i < size1; i++) {
        arr[i] = arr1[i];
        if (i == (size1 - 1)) {
            for (int j = 0; j < size2; j++) {
                arr[i+1+j] = arr2[j];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        std::cout << arr[i] << '\t';
    }

    if (m % 2) { std::cout << '\n' << "Медіана = " << arr[m / 2] << std::endl; }
    else { std::cout << '\n' << "Медіана = " << (arr[m / 2] + arr[m / 2 - 1]) / 2.0 << std::endl; }
    // ------- Закінчення роботи з упорядкуванням масиву --------

    return 0;
}