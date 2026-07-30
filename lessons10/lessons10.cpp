//
// Created by Кирило Вєтров on 24.07.2026.
//
#include <iostream>


using namespace std;


int main() {


    // int n = 0;
    // cout << "Введіть (N): ";
    // cin >> n;
    //
    // // Зчитати N цілих чисел у vector
    // vector<int> scores(n);
    // cout << "Введіть бали гравців: " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cin >> scores[i];
    // }

    // Видалити всі результати, що менші за 50
    // scores.erase(
    //         remove_if(scores.begin(), scores.end(), [](int score) {
    //             return score < 50;
    //     }),
    //     scores.end()
    // );

    // Видалити всі результати, що менші за 50 інший варіант
    // vector<int> score_tmp;
    //
    // for (size_t i = 0; i < scores.size(); ++i) {
    //     if (scores[i] >= 50) {
    //         score_tmp.push_back(scores[i]);
    //         scores.push_back(score_tmp[i]);
    //
    //         //scores.erase(scores.begin() + 0);
    //     }
    // }
    //
    // for (int x: scores) {
    //     cout << x << " ";
    // }

    // // 4. Відсортувати вектор за спаданням
    // sort(scores.begin(), scores.end(), greater<int>());
    //
    // // Виведення результатів
    // cout << "\n----------- Результати ----------" << endl;
    //
    // // Кількість гравців, що залишилися
    // cout << "Кількість гравців, що залишилися: " << scores.size() << endl;
    //
    // // if (scores.empty()) {
    // //     cout << "Немає гравців з результатом >= 50." << endl;
    // //     return 0;
    // // }
    //
    // // Найбільший результат (оскільки відсортовано за спаданням, перший елемент — найбільший)
    // cout << "Найбільший результат: " << scores[0] << endl;
    //
    // // Три найкращі результати (якщо менше трьох — вивести всі)
    // cout << "Топ результати: ";
    // int top_count = min(static_cast<int>(scores.size()), 3);
    //
    // for (int i = 0; i < top_count; ++i) {
    //     cout << scores[i] << " ";
    // }



    // Вказівники
    void printValue(int* ptr);
    void swapNumbers(int* x, int* y);
    void swapMassive(int* arr1, int* arr2, int size);
    // int x = 42;
    // printValue(&x);
    // printValue(nullptr);

    // Нова задача
    // Міняємо місцями значення двох змінних
    int a = 50, b = 40;
    cout << a << '\t' << b << endl;
    swapNumbers(&a, &b);
    cout << a << '\t' << b << endl;

    int m;
    std::cout << "\nРозмір масиву: ";
    std::cin >> m;

    int* arr1 = new int[m];
    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) { cin >> arr1[i]; }
    cout << '\n';
    for (int i = 0; i < m; ++i) { cin >> arr2[i]; }

    for (int i = 0; i < m; ++i) { cout << arr1[i] << '\t'; }
    cout << '\n';
    for (int i = 0; i < m; ++i) { cout << arr2[i] << '\t'; }
    cout << '\n';

    swapMassive(arr1, arr2, m);

    for (int i = 0; i < m; ++i) { cout << arr1[i] << '\t'; }
    cout << '\n';
    for (int i = 0; i < m; ++i) { cout << arr2[i] << '\t'; }

    return 0;
}

// Вказівники
void printValue(int* ptr) {

    if (ptr) {
        *ptr = 10;
        cout << *ptr << endl;
        cout << ptr << endl;
    }
    else
        cout << nullptr << endl;
}
// -----------------------------------

// Ф-ція. зміни місць чисел
void swapNumbers(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
// -----------------------------------

// Ф-ція. зміни місць значень масивів
void swapMassive(int* arr1, int* arr2, int size) {
    for (int i = 0; i < size; ++i) {
        swap(arr1[i], arr2[i]);
    }
}
// -----------------------------------