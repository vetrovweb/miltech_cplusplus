//
// Created by Кирило Вєтров on 18.06.2026.
//
#include <iostream>
#include <string>

int main() {
    using namespace std;

    // 1 task
    // string name;
    //
    // cout << "Введіть ваше Прізвище та імʼя: ";
    // getline(cin, name);
    //
    // cout << "Вітаємо, " << name + '.' << " Раді бачити Вас на уроці." << endl;


    // 2 task
    // string worldAll, word1, word2;
    // cout << "Введіть перше слово: ";
    // cin >> word1;
    // cout << "Введіть друге слово: ";
    // cin >> word2;
    //
    // worldAll = word1 + ' ' + word2;
    // cout << worldAll << endl;
    // cout << "Загальна довжина фрази: " << worldAll.length() << endl;

    // 3 task
    // string word;
    // cout << "Введіть слово: ";
    // cin >> word;
    // word[0] = '+';
    // word[word.length() - 1] = '-';
    // cout << "Оновлений рядок: "<< word << endl;

    // 4 task *

    string sentence;
    int j = 0;

    cout << "Введіть речення: ";
    getline(cin, sentence);
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ') {
            j++;
        }
    }

    //cout << sentence << endl;
    cout << "Кількість пробілів у тексті: " << j << endl;

    return 0;
}