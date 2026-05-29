#include <iostream>
#include <numbers>

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    // // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    //
    // const auto lang = "C++";
    // //std::cout << "Hello and welcome to " << lang << "!\n";
    // std::cout << "Hello, world!\n";
    // std::cout << 5,3;
    // std::cout << "\t" << 5.4;
    // std::cout << "\n" << 2 * 5,3; // can't see after ","
    //
    // int a = 5;
    // float b = 5;
    // std::cout << "\n" << a / 7;
    // std::cout << "\n" << b / 7;
    //
    // // out size variable
    // long int c = 19234834127283;
    // short int d = 32;
    // int f;
    //
    // cout << "\n" << sizeof(d) << endl;
    // // cout << "\n" << "Введіть змінну f" << endl;
    // // cin >> f;
    // // cout << f << endl;1
    //
    //
    // // lessons 37 (3-тє заняття)
    // bool t1 = 12;
    // std::cout << t1 << endl;

    int age{};
    std::cout << "Введіть Ваш вік: ";
    std::cin >> age;

    if (age < 18) {
        std::cout << "Вам менше 18-ти. Упс..." << std::endl;
    }
    else if (age >= 30 ){
        std::cout << "Трохи старий, але красавчик" << std::endl;
    }
    else {
        std::cout << "Ви красавчик" << std::endl;
    }

    return 0;
}