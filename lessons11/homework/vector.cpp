//
// Created by Кирило Вєтров on 08.08.2026.
// Робота з динамічними масивами через контейнер vector
//
#include <iostream>
#include <vector>
#include <algorithm>

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
    // -------------------------- 1. Вихідна структура даних -------------------------
    // Створіть структуру Student:
    struct Student {
        std::string name;                   //
        double avrgScore;                   // average score
        int course;                         // course in which students are studying (1, 2, 3, 4)
    };
    std::cout << "===========================================================" << std::endl;

    // Напишіть програму, яка створює вектор із 6–8 студентів (із різними балами та курсами)
    std::vector<Student> students {
        {"Олена", 85.5, 2},
        {"Іван", 54.0, 1},
        {"Марія", 92.0, 3},
        {"Петро", 59.5, 2},
        {"Андрій", 85.5, 4},
        {"Анна", 78.0, 1}
    };

    // Фільтрація (Відрахування):
    // Видаліть із вектора всіх студентів, у яких середній бал менший за 60.0
    // (використайте std::erase_if та лямбда-функцію).

    // запис теж коректний [](Student s). Це означає, що під час перевірки кожного студента C++ робить повну копію
    // об'єкта Student у пам'яті.Щоб програма працювала швидше приймайте об'єкти за константним посиланням:
    // students.erase(std::remove_if(students.begin(), students.end(), [](const Student& s) {
    //     return s.avrgScore < 4.5;
    //  }), students.end());

    // або так ...
    // Стандарт C++20 або новіший, у старіших версіях цієї функції просто немає.
    // Правило MISRA C++ 0.1.2 говорить: «Значення, яке повертає функція, має бути обов'язково використане».
    // "Я знаю, що там є результат, але я свідомо його ігнорую" void
    (void)std::erase_if(students, [](const Student& s) {
        return s.avrgScore < 60;
    });
    // Для MilTech-проєктів виведення результату в змінну є найкращим


    // 2. Сортування за рейтингом:
    // Посортуйте залишок студентів за спаданням середнього балу (найвищий бал — першим).
    // Якщо середній бал однаковий — посортуйте за абеткою за іменем (використайте std::sort та лямбда-функцію).
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.avrgScore != b.avrgScore) {
            return a.avrgScore > b.avrgScore;
        }
        else {
            return a.name < b.name;
        }
    });

    for (const auto& element : students) {
        std::cout << element.name << ' ' << element.avrgScore << std::endl;
    }

    // Task 2 for Gemini
    // ------------- 2. «Система управління складом (Inventory System)» --------------
    // Ви розробляєте модуль для аналізу товарів на складі. Дані зберігаються у векторі об'єктів Item.
    struct Item {
        std::string name;                            // Назва товару
        double price;                                // Ціна за одиницю
        int quantity;                                // Кількість на складі
        std::string category;                        // Категорія (наприклад: "Electronics", "Food", "Clothing")
    };

    // 2. Умова задачі
    std::cout << "===========================================================" << std::endl;
    // Створіть вектор із 7–8 товарів різних категорій (з різними цінами та кількістю).
    // Виконайте наступні операції, використовуючи алгоритми STL та лямбда-функції:
    std::vector<Item> inventory = {
        {"Laptop", 1200.0, 3, "Electronics"},
        {"Smartphone", 800.0, 10, "Electronics"},
        {"Bread", 1.5, 50, "Food"},
        {"T-Shirt", 25.0, 2, "Clothing"},
        {"Headphones", 150.0, 1, "Electronics"},
        {"Apple", 0.8, 100, "Food"},
        {"Jacket", 120.0, 4, "Clothing"}
    };

    for (const auto& element : inventory) {
        std::cout << element.name << ' ' << element.price << std::endl;
    }
    std::cout << std::endl;

    // Індексація цін (Модифікація std::for_each):
    // Підніміть ціну на 10% для всіх товарів із категорії "Electronics".
    // (Підказка: лямбда має приймати елемент за неконстантним посиланням Item&).
    std::for_each(inventory.begin(), inventory.end(), [](Item& p) {
        p.price = p.price + 10;
    });

    for (const auto& element : inventory) {
        std::cout << element.name << ' ' << element.price << std::endl;
    }

    // Пошук найдорожчого товару (std::max_element):
    // Знайдіть товар із найвищою загальною вартістю на складі (ціна×кількість) і виведіть його назву та розраховану суму.
    auto max_price_it = inventory.begin();
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->price * it->quantity > max_price_it->price * max_price_it->quantity) {
            max_price_it = it;
        }
    }
    std::cout << '\n' << "Max price: " << max_price_it->name << ' ' << max_price_it->price << '\n'
        << "Total cost of goods: " << max_price_it->price * max_price_it->quantity << std::endl;

    // Для порівняння, ось той самий функціонал через STL-алгоритм
    if (!inventory.empty()) {
        const auto max_price_it = std::max_element(inventory.begin(), inventory.end(),
            [](const Item& a, const Item& b) {
                return (a.price * a.quantity) < (b.price * b.quantity);
            });

        std::cout << "\nMax price: " << max_price_it->name << ' ' << max_price_it->price << '\n'
                  << "Total cost of goods: " << (max_price_it->price * max_price_it->quantity) << std::endl;
    }


    return 0;
}
