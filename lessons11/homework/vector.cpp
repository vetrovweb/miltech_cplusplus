//
// Created by Кирило Вєтров on 08.08.2026.
// Робота з динамічними масивами через контейнер vector
//
#include <iostream>

int main() {

    // Створення масива v1, знаходиться в області std
    std::vector<int> v1;

    // Створення цілих чисел
    std::vector<int> v2 = {1,2,3,4,5,6,7,8,9};

    // Створення масиву з символів char
    std::vector<char> v3 {'a','b','c','d'};

    // Додавання елементів масиву в кінець
    v2.push_back(100);

    std::cout << "Size:     " << v2.size() << std::endl;
    std::cout << "Capacity: " << v2.capacity() << std::endl;

    // Перебір елементів (Range-based for loop) для array теж працює
    std::cout << "Елементи вектора: ";
    for (int x : v2) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    // Перебір вектора за допомогою ітератора
    std::cout << "Через ітератор" << std::endl;
    for (auto it = v3.begin(); it != v3.end(); ++it) {
        // *it розіменовує ітератор (повертає значення) по-іншому помилка
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    // Пошук елемента за допомогою ітератора та find
    std::cout << *(std::find(v3.begin(), v3.end(), 'd')) << std::endl;

    // або
    auto it = std::find(v3.begin(), v3.end(), 'a');
    //std::cout << *it;
    if (it != v3.end()) {
        std::cout << "Елемент 'с' знайдено на позиції " << std::distance(v3.begin(), it) << std::endl;
    }
    else {
        std::cout << "Елемент 'с' не знайдено" << std::endl;
    }

    // Видалення останнього елемента
    v2.pop_back();

    // Сортування за зростанням
    std::sort(v2.begin(), v2.end());

    for (auto element : v2) {
        std::cout << element << ' ';
    }

    // Сортування за спаданням
    //std:sort(v2.begin(), v2.end(), std::greater<int>());
    // Теж саме тільки використовується лямбда-функція
    std::sort(v2.begin(), v2.end(), [](int a, int b) {
        return a > b;
    }); // 9 8 7 6 5 4 3 2 1


    // Оголошуємо та зберігаємо лямбду
    auto isEven = [](int x) {
        return x % 2 == 0;
    }; // Перевірка на парність

    // Використовуємо її у виклику функції
    bool check = isEven(4); // true

    // Передаємо її в алгоритм STL
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int even_count = std::count_if(numbers.begin(), numbers.end(), isEven);
    std::cout << even_count << std::endl;

    // Task 1 for Gemini

    return 0;
}
