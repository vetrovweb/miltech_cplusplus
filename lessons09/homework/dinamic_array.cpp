//
// Created by Кирило Вєтров on 17.07.2026.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {

    // Робота з бібліотекою vector
    vector<int> d_arr;

    cout << "Введіть елементи масиву: " << endl;
    while (true) {
        int n = 0;
        cin >> n;
        if (n == 0) break;
        d_arr.push_back(n);
    }

    // Звіряємо кожен елемент по-порядку
    for (int i = 0; i < d_arr.size(); i++) {
        for (int j = i + 1; j < d_arr.size(); j++) {
            if (d_arr[i] == d_arr[j]) {
                // видаляємо поточний елемент масиву
                d_arr.erase(d_arr.begin() + j);
            }
        }
    }

    cout << "Оновлений масив: " << endl;
    for (int x : d_arr) {
        cout << x << '\t';
    }

    return 0;
}