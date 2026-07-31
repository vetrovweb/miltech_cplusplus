//
// Created by Кирило Вєтров on 31.07.2026.
// Завдання 2: Перевертання масиву. Використання двох вказівників (на початок і кінець масиву)
// для зміни порядку його елементів на протилежний. Має бути функція void reverseArray...
#include <iostream>

using namespace std;

// Ф-ція. реверсу
void reverseArray(vector<int> &v) {
    reverse(v.begin(), v.end());
}

int main() {

    //
    vector<int> v;
    int size = 5;
    // Заповнення масиву
    for (int i = 0; i < size; i++) {
        v.push_back(i);
    }
    //reverse(v.begin(), v.end());                                // метод реверсу масиву і не тільки


    for (int x: v) {cout << x << ' ';}
    cout << endl;

    reverseArray(v);
    for (int x: v) {cout << x << ' ';}

    return 0;
}