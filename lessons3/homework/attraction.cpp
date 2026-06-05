//
// Created by Кирило Вєтров on 05.06.2026.
//
#include <iostream>

int main() {

    using namespace std;
    int age;
    float height;
    bool hasHeartIssues;

    cout << "Введіть свій вік: ";
    cin >> age;
    cout << "Введість свій ріст: ";
    cin >> height;
    cout << "Маєте проблеми з серцем? (1/0): ";
    cin >> hasHeartIssues;

    if (age >= 12 && age <= 65) {
        // cout << "Доступ дозволено! Гарної поїздки!" <<endl;
        if (height >= 1.40f && height <= 2.00f) {
            if (!hasHeartIssues) {
                cout << "Доступ дозволено! Гарної поїздки!" <<endl;
            }
            else {
                cout << "Доступ заборонено: У Вас проблеми з серцем." << endl;
            }
        }
        else {
            cout << "Доступ заборонено: Ваш зріст менший за 1.40м." << endl;
        }
    }
    else {
        cout << "Доступ заборонено: Ваш вік менший за 12 або більший за 65." << endl;
    }

    return 0;
}