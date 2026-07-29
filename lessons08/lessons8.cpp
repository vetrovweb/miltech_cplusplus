//
// Created by Кирило Вєтров on 10.07.2026.
//
#include <iostream>

using namespace std;

int donumber(int x, int y) {

    return x + y;
}

int main() {

    // donumber(10, 20);
    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};              // масив
    //
    // for (int i = 0; i < 10; i++) {                              // виводимо дані з масиву
    //     std::cout << arr[i] << " ";
    // }
    //
    // std::cout << std::endl;

    int arr[15] = {2, 3, 4, 5, 6, 1, 8, 12, 13, 15, 13, 22, 55, 23, 12};
    int n = 0;
    for (int i = 0; i < 15; i++) {
       if (arr[i] % 2 == 0) {
           std::cout << arr[i] << " ";
           n++;

       }
    }
    std::cout << '\n' << n << std::endl;

    int arr1[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int sum = 0;
    int aver = 0;
    for (int i = 0; i < 8; i++) {
        sum += arr1[i];

    }
    aver = sum / 8;

    cout << "Summa: "<< sum << endl;
    cout << "Average: "<< aver << endl;

    // int nums1[] = {};
    // int nums2[] = {};
    // int nums[3] = {};
    // int nums1[2] = {1, 3};
    // int nums2[1] = {2};
    //
    // for (int i = 0; i < 3; i++) {
    //     cout << nums1[i] << " ";
    //     nums[i] = nums1[i];
    //     for (int j = 0; j < 1; j++) {
    //         cout << nums2[j] << "";
    //         nums[j] = nums1[j];
    //
    //     }
    // }

    int arr3[] = {4, 2, 7, 1, 9, 3};
    int target = 76;
    int index = -1;

    for (int i = 0; i < 6; ++i)
    {
        if (arr3[i] == target)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
        std::cout << "Знайдено на позиції " << index;
    else
        std::cout << "Не знайдено";

    int arr5[] = {1, 2, 3, 4, 5};
    int n1 = 5;

    cout << '\n';
    for (int i = 0; i < (n1 / 2); ++i)
    {
        int temp = arr5[i];
        arr5[i] = arr5[n1 - 1 - i];
        arr5[n1 - 1 - i] = temp;
    }
    // {5, 4, 3, 2, 1}
    for (int i = 0; i < n1; ++i) {
        cout << arr5[i] << " ";
    }

    // урок 77
    cout << '\n';
    int arr6[] = {1, 2, 3, 4, 5};
    cout << sizeof(arr6) / sizeof(arr6[0]) << endl;
    cout << sizeof(arr6[0]) << endl;

    // урок 78
    cout << "----------------------------" << endl;
    int m = 10;
    std::cin >> m;
    //m = 10;
    int arr7[m];                    // НЕ ДОЗВОЛЕНО! має бути константа (VLA — не стандарт C++)
                                    // Використовуйте std::vector для динамічного розміру --- АЛЕ ПРАЦЮЄ ---
    cout << sizeof(arr7) << endl;

    // урок 79
    cout << "----------------------------" << endl;
    int squares[11];
    for (int i = 0; i < 11; ++i)
    {
        squares[i] = (i + 1) * (i + 1);
    }
    // {1, 4, 9, 16, 25, 36, 49, 64, 81, 100}
    for (int i = 0; i < 11; ++i) {
        cout << squares[i] << " ";
    }

    cout << '\n';
    int arr8[] = {1, 2, 3, 4, 5};
    int p = 5;


    for (int i = 0; i < p / 2; ++i)
    {
        int temp = arr8[i];                         // копіюємо перший елемент, тобто нульовий елемент масиву
        arr8[i] = arr8[p - 1 - i];                  // Присвоюємо першому елементу масиву останній, кількість елементів 5-ть,
                                                    // але рахуємо їх з 0 по 4 тому "p - 1" і додаємо циклу.
                                                    // На кожну позицію змінюємо на мінус 'i'

        arr8[p - 1 - i] = temp;                     // Перший закидуємо в останній (попередньо копіювали)
    }
    for (int i = 0; i < p; ++i) {
        cout << arr8[i] << " ";
    }
    // {5, 4, 3, 2, 1}

    return 0;
}