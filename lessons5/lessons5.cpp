//
// Created by Кирило Вєтров on 12.06.2026.
//
#include <iostream>
#include <string>

#include <thread>                               // Обов'язково для std::this_thread::sleep_for
#include <chrono>                               // Обов'язково для std::chrono::milliseconds

int main() {
    using namespace std;
    //
    // // Масив або рядок із символами анімації для зручності
    // string loader = "/\\/";
    //
    // while (true) {
    //     for (char symbol : loader) {
    //         // Старий, нудний спосіб:
    //         // for (int i = 0; i < loader.length(); i++) {
    //         //     char symbol = loader[i];
    //         //     // код...
    //         // }
    //
    //         // \r повертає курсор на початок рядка, друкуємо символ
    //         cout << "\rЗавантаження... " << symbol << flush;
    //
    //         // Робимо паузу в 150 мілісекунд (0.15 секунди)
    //         this_thread::sleep_for(chrono::milliseconds(150));
    //     }
    // }

    // int temp{};
    //
    // while (true) {
    //     cout << "Введіть поточну температуру процесора: ";
    //     cin >> temp;
    //
    //     if (temp <= 0) {
    //         cout << "Система вимкнулась. Моніторинг завершено." << endl;
    //         break;
    //     }
    //     else if (temp > 80) {
    //         cout << "Перегрів!" << endl;
    //     }
    //     else {
    //         cout << "Стан стабільний." << endl;
    //     }
    //     cout << "------------------------------------" << endl;
    // }

    // int secret = 42;
    // int numberUser{};
    //
    // cout << "Гра \"Вгадай число\"" << endl;
    // cout << "--------------------" << endl;
    //
    // while (1) {
    //     cout << "Введіть число: ";
    //     cin >> numberUser;
    //     if (numberUser == secret) {
    //         cout << "Вітаю! Ви вгадали число" << endl;
    //         break;
    //     }
    //     else if (numberUser < secret) {
    //         cout << "Замало" << endl;
    //     }
    //     else {
    //         cout << "Забагато" << endl;
    //     }
    // }

    // for (int i = 1; i <= 20; i++) {
    //
    //     // if (i % 3 == 0) {
    //     //     // діляться на 3 без остачі, пропускаємо
    //     //     continue;
    //     // }
    //     // if (i % 2 == 0) {
    //     //     // парні числа
    //     //     cout << i << " ";
    //     // }
    //     if (i % 2 == 0 && i % 3 != 0) {
    //         cout << i << " ";
    //     }
    //
    // }


    int max1{};                     // найбільше число
    int max2{};                     // друге за величиною число
    int num{};
    //
    // cout << "Введіть послідовність додатних чисел (0 для завершення): " << endl;
    //
    // while (cin >> num && num != 0) {
    //     if (num > max1) {
    //         max2 = max1;            // cтарий максимум стає другим
    //         max1 = num;             // оновлюємо абсолютний максимум
    //     }
    //     else if (num > max2) {
    //         max2 = num;             // оновлюємо тільки другий максимум
    //     }
    // }

    return 0;
}