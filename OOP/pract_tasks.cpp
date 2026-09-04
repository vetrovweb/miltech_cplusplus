//
// Created by Кирило Вєтров on 03.09.2026.
//
#include <iostream>


class Student {
private:
    // Поля
    std::string name{};
    int age{};
    int grade{};

public:
    //  Методи
    void printInfo() {
        std::cout << "Name: " << name << '\t'
                  << "Age: " << age << '\t'
                  << "Grade: " << grade << '\t'
        << std::endl;
    }

    void AddData() {
        // Повинна бути перевірка введення даних
        // std::string name, int age, int grade
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter age: ";
        std::cin >> age;
        std::cout << "Enter grade: ";
        std::cin >> grade;
        std::cout << "Thank you" << std::endl;
    }
};

class Dog {

private:
    std::string name{};
    int age{};

public:
    Dog(std::string n, int a) : name{n}, age{a} {}

    void bark() const {
        std::cout << name << " каже: Гав!\n";
    }

    int getAge() const { return age; }


};

class BankAccount {
private:
    std::string owner{};
    double balance{};
public:
    // Конструктор з ім’ям власника та початковим балансом
    BankAccount (std::string cOwner, double cBalance) : owner{cOwner}, balance{cBalance} {}

    // deposit(double amount)
    void deposit(double amount) {
        if (amount > 0) { balance += amount; }
    }

    // withdraw(double amount)
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        }
        else {
            std::cout << "Не можливо зняти " << amount << "$. " << "Недостатньо коштів на рахунку" << std::endl;
        }
    }

    // printInfo()
    void printInfo() {
        std::cout << "-------------------- Bank account -----------------------" << std::endl;
        std::cout << "Owner: " << owner << ";  " << "Amount: " << balance << "$" << std::endl;
    }

    double getBalance() const {
        return balance;
    }

};

int main() {

    // Ім'я: Олег   Вік: 18   Оцінка: 10
    Student Oleg;
    Student Olenka;

    //Oleg.AddData();
    Oleg.printInfo();
    // Olenka.name = "Olena"; - помилка, оскільки поле name є закритим в області (private)

    //
    Dog rex("Рекс", 3);
    rex.bark();

    //
    //     10. BankAccount — повне завдання на інкапсуляцію
    // Створи клас BankAccount.
    // Поля owner та balance мають бути private.
    // Створи конструктор з ім’ям власника та початковим балансом.
    // Створи deposit(double amount).
    // Створи withdraw(double amount).
    // Створи printInfo().
    // Не можна поповнити рахунок на 0 або від’ємну суму.
    // Не можна зняти 0 або від’ємну суму.
    // Не можна зняти більше грошей, ніж є на рахунку.
    // Змінювати balance напряму з main() не можна.
    // Приклад:
    // // BankAccount account("Олег", 1000);
    // //     account.deposit(500);
    // //     account.withdraw(200);
    // //     account.printInfo();

    // BankAccount account; - є конструктор класу, тому буде помилка потрібно обовʼязково прописати значення
    BankAccount account("Олег", 1000);
    account.printInfo();
    account.deposit(510.8);
    account.printInfo();
    account.withdraw(2510.8);
    account.printInfo();
    std::cout << account.getBalance() << std::endl;

    return 0;
}

