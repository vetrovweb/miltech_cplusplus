//
// Created by Кирило Вєтров on 19.08.2026.
// For games
//
#include <cctype>                                               // для std::tolower
#pragma once                                                    // захищає від повторного підключення

// Підключення залежно від операційної системи
#if defined(_WIN32) || defined(_WIN64)
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif


// Функція миттєвого зчитування одного символу
char InstandRead() {
#if defined(_WIN32) || defined(_WIN64)
    return _getch();
#else
    char ch = '\0';
    struct termios old_term, new_term;

    // 1. Зчитуємо поточні налаштування термінала
    tcgetattr(STDIN_FILENO, &old_term);
    new_term = old_term;

    // 2. Вимикаємо канонічний режим (буферизацію) та ехо-вивід
    new_term.c_lflag &= ~(ICANON | ECHO);

    // 3. Застосовуємо нові налаштування негайно
    tcsetattr(STDIN_FILENO, TCSANOW, &new_term);

    // 4. Читаємо 1 байт
    read(STDIN_FILENO, &ch, 1);

    // 5. Обов'язково повертаємо початкові налаштування термінала
    tcsetattr(STDIN_FILENO, TCSANOW, &old_term);

    return ch;
#endif
}
/*
int main() {
    std::cout << "=== Тест зчитування клавіш без Enter ===" << std::endl;
    std::cout << "Натискай клавіші на клавіатурі (W, A, S, D)." << std::endl;
    std::cout << "Натисни 'q' для виходу.\n" << std::endl;

    while (true) {
        // Зчитуємо клавішу одразу при натисканні
        char key = InstandRead();

        // Переводимо у нижній регістр (щоб W і w оброблялися однаково)
        char lower_key = std::tolower(key);

        std::cout << "Натиснуто символ: '" << key
                  << "' (ASCII код: " << static_cast<int>(key) << ")" << std::endl;

        // Логіка реакції на керування
        if (lower_key == 'w') {
            std::cout << "-> Дія: Рух ВГОРУ" << std::endl;
        } else if (lower_key == 'a') {
            std::cout << "-> Дія: Рух ЛІВОРУЧ" << std::endl;
        } else if (lower_key == 's') {
            std::cout << "-> Дія: Рух ВНИЗ" << std::endl;
        } else if (lower_key == 'd') {
            std::cout << "-> Дія: Рух ПРАВОРУЧ" << std::endl;
        } else if (lower_key == 'q') {
            std::cout << "\nВихід з програми..." << std::endl;
            break;
        } else {
            std::cout << "-> Некоректна клавіша (не WASD)!" << std::endl;
        }

        std::cout << "-----------------------------------" << std::endl;
    }

    return 0;
}
*/