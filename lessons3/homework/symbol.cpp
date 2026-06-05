//
// Created by Кирило Вєтров on 05.06.2026.
//
#include <iostream>

int main() {

    using namespace std;
    char ch;
    bool isVowel;

    cout << "Введіть символ: ";
    cin >> ch;

    if (ch >= '0' && ch <= '9') {
        cout << "Це число 0-9 ";
        // cout << ch << endl;
    }
    else if (ch >= 'A' && ch <= 'Z') {
        cout << "Це велика латинська літера ";
        // cout << ch << endl;
    }
    else if (ch >= 'a' && ch <= 'z') {
        cout << "Це маленька латинська літера ";
        // cout << ch << endl;
    }
    else {
        cout << "Це спец. сивол!" << endl;
    }

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'O' || ch == 'U') {
        isVowel = true;
        cout << "\nДодатково: це голосна літера!";
    }

    return 0;
}