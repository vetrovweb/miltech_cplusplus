//
// Created by Кирило Вєтров on 04.09.2026.
//
#include <iostream>

    // --------------------------- 1. Клас BankAccount ---------------------------
    // Поля: owner, accountNumber, balance.
    // Важливі поля мають бути private.
    // Створи конструктор для створення рахунку.
    // Додай метод deposit() для поповнення рахунку.
    // Додай метод withdraw() для зняття коштів.
    // Додай метод transferTo() для переказу коштів на інший рахунок.
    // Додай метод printInfo() для виведення інформації про рахунок.
class BankAccount {
private:
    std::string owner{};
    int accountNumber{};
    double balance{};

public:
    // Конструктор
    // Заберемо зайве копіювання рядка передавши за константним посиланням (не завжди!), а ще краще використати std::move
    BankAccount (std::string owner_, int accountNumber_, double balance_) :
        owner{std::move(owner_)}, accountNumber{accountNumber_}, balance{balance_} {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        }
        else {
            std::cout << "Не можливо зняти " << amount << "$. " << "Недостатньо коштів на рахунку" << std::endl;
        }
    }

    bool transferTo(BankAccount& target, double amount) {
        if (amount <= 0 || balance < amount) {
            std::cout << "Переказ неможливий: недостатньо коштів на рахунку або некоректна сума!\n";
            return false;
        }
        else {
            // 2. Знімаємо гроші з поточного акаунта
            balance -= amount;

            // 3. Зараховуємо гроші на інший акаунт
            target.balance += amount;

            std::cout << "Успішно переказано " << amount << " $ для " << target.owner << "\n";
            return true;
        }
    }

    void printInfo() {
        std::cout << "Owner: " << owner << "; Id: " << accountNumber << "; " << balance << "$ " << std::endl;
    }

};



int main () {


    BankAccount account1{"Олег", 24353, 2124.92};
    BankAccount account2{"Анна", 22353, 1240.54};
    account1.printInfo();
    account1.transferTo(account2, 1410.4);
    account2.printInfo();
    return 0;
}