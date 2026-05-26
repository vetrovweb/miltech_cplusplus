#include <iostream>

int main() {

    // using namespace std;
    // Спосіб 2: імпортуємо тільки те, що потрібно інакше буде попередження
    using std::cout;
    using std::endl;

    int a = 4;
    double b = 6;
    //
    long double c = 3.14159265358979323846;

    cout << a + b << "\t";
    cout << a - b << "\t";
    cout << a * b << "\t";
    cout << a / b << "\t";
    cout << a % int(b) << endl;
    //
    cout << " -------------------- ";
    cout << "\nРозмір long double - ";
    cout << sizeof(c) << endl;

    return 0;
}