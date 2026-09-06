//
// Created by Кирило Вєтров on 05.09.2026.
//

// Завдання 1: Клас "Точка у 2D" (Point2D)
// Створіть клас Point2D, який описує точку на площині.
// Вимоги:
// Приватні поля:
// x (double) — координата X.
// y (double) — координата Y.
// Конструктори:
// За замовчуванням (встановлює x = 0, y = 0).
// З параметрами (приймає значення для x та y).
// Публічні методи:
// move(double dx, double dy) — зсуває точку на dx по X та dy по Y.
// distanceTo(const Point2D& other) — обчислює та повертає відстань від поточної точки до іншої точки other.
// print() — виводить координати у форматі (X, Y).

#include <iostream>
#include <cmath>

using namespace std;

class Point2D {

    // Приватні поля
    private:
    double x;
    double y;

public:
    // Конструктори
    // Конструктор за замовчуванням
    //Point2D() = default;
    //Point2D (double dx, double dy) : x(dx), y(dy) {}
    Point2D (double dx = 0.0, double dy = 0.0) : x(dx), y(dy) {}

    void move(double dx, double dy) {
        dx += x;
        dy -= y;
    }

    double distanceTo(const Point2D& other) const{
        //pow(x, 2); // 25.0
        return sqrt(pow((x - other.x),2) + pow((y - other.y), 2));
    }

    void print() const {
        cout << '(' << x << ", " << y << ')' << endl;
    }

    //     Завдання 2: Перевантаження оператора порівняння ==
    // Додайте до нашого класу Point2D оператор ==, який перевірятиме,
    // чи однакові дві точки (чи збігаються їхні x та y).
    bool operator==(const Point2D& other) const {
        // можна порівнюють з урахуванням невеликої похибки std::abs(x - other.x) < 0.00001
        return x == other.x && y == other.y;
    }
};


int main () {

    Point2D p1(5,10);
    Point2D p2(5,10);

    p1.print();
    p2.print();

    if (p1 == p2) {
        cout << "Точки однакові" << endl;
    }

    return 0;
}
