//
// Created by Кирило Вєтров on 31.07.2026.
//
#include <iostream>
//#include <string>

using namespace std;

struct TaskManager {
    string title {};
    bool isDone {false};
};

int main() {

    // 1. Ініціалізуємо генератор поточним часом (робиться 1 раз на початку програми)
    std::srand(std::time(nullptr));

    // TaskManager task1 {"Завдання 1", true, "Без коментарів"};
    // TaskManager task2 {"Завдання 2", false, "Щось пішло не за планом"};
    // TaskManager task3 {"Завдання 3", true, "Без коментарів"};
    //
    // cout << '\t' << task1.title << endl
    //      << '\t' << task1.isDone << endl
    //      << '\t' << task1.comments << endl;

    int size = 5;
    int size_new = size + 1;
    TaskManager tm[size];
    TaskManager tm_new[size_new];

    //
    for (int i = 0; i < size; i++) {
        tm[i].title = "Task " + to_string(i);
        tm[i].isDone = rand() % 2;
    }

    //
    for (int i = 0; i < size; i++) {
        // boolalpha — це маніпулятор виводу, який виводить булеві значення як слова "true" / "false"
        cout << tm[i].title << '\t' << boolalpha << tm[i].isDone << endl;
    }

    //
    for (int i = 0; i < size_new; i++) {
        cout << tm_new[i].title << '\t' << boolalpha << tm_new[i].isDone << endl;
    }

    // Copy masiv
    for (int i = 0; i < size_new; i++) {
        tm_new[i].title = tm[i].title;
        tm_new[i].isDone = tm[i].isDone;
        if (tm_new[i].title.empty()) {
            getline(cin, tm_new[i].title);
            cin >> tm_new[i].isDone;
            //tm_new[i].title = "Task 24";
            //tm_new[i].isDone = true;
        }
    }

    for (int i = 0; i < size_new; i++) {
        cout << tm_new[i].title << '\t' << boolalpha << tm_new[i].isDone << endl;
    }

    //
    // int enter = 0;
    // cout << "Щоб ввести задачу натисніть 1: " << endl;
    // cin >> enter;
    // if (enter == 1) {
    //     cout << "Напишіть назву: " << endl;
    //
    //     // Очищаємо буфер від залишкового '\n'
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     getline(cin, tm[0].title);
    // }
    //
    // if (enter == 2) {
    //     for (int i = 0; i < size; i++) {
    //         if (tm[i].title != "0") {
    //             cout << tm[i].title << endl;
    //         }
    //     }
    // }
    //
    // cout << tm[0].title << endl;
    // STask task;
    // task.name = "Task 121312321";
    // task.isDone = true;
    // // cout << task.name << " - " << (task.isDone ? "Completed" : "Not completed") << endl;
    //
    // STask task1 { "Task 1",false };
    // // cout << task1.name << " - " << (task1.isDone ? "Completed" : "Not completed") << endl;
    //
    // cout <<
    //     '\n' <<
    //     "====== TASK MANAGER ======" << '\n' <<
    //     "1. Показати всі задачі" << '\n' <<
    //     "2. Додати задачу" << '\n' <<
    //     "3. Видалити задачу" << '\n' <<
    //     "4. Позначити як виконану" << '\n' <<
    //     "5. Показати тільки виконані" << '\n' <<
    //     "6. Показати тільки невиконані" << '\n' <<
    //     "7. Знайти задачу" << '\n' <<
    //     "8. Відсортувати задачі" << '\n' <<
    //     "9. Вийти" << '\n' <<
    //     '\n' <<
    //     "Ваш вибір: " << '\t';
    //
    // // Очікуємо натискання кнопки
    // int c = 0, counter = 0;
    // while (cin >> c) {
    //     cout << "Hello!" << endl;
    //     switch (c) {
    //         case 1: cout << "World!" << '\n';
    //             for (int i = 0; i > counter; i++) {
    //                 cout << task.name << " - " << task.isDone << endl;
    //             }
    //             break;
    //
    //         case 2: cout << "124!" << '\n'; break;
    //         case 3: cout << "Hell4324o!" << '\n'; break;
    //         case 4: cout << "343!" << '\n'; break;
    //         case 5: cout << "He2343llo!" << '\n'; break;
    //         case 6: cout << "H23434ello!" << '\n'; break;
    //         case 7: cout << "H23ук4eкекllo!" << '\n'; break;
    //         case 8: cout << "H23ук4ello!" << '\n'; break;
    //         case 9: return 0;
    //         default: cout << "Введіть правильний пункт: "; break;
    //     }
    // }

    return 0;
}