//
// Created by Кирило Вєтров on 07.09.2026.
//
#include <iostream>
#include <string>

class BankAccount {
private:
    std::string owner{};
    double balance{};

protected:
    BankAccount(std::string owner_, double balance_) : owner{std::move(owner_)}, balance{balance_} {}
    void setBalance(double newBalance) { balance = newBalance; }

public:
    virtual ~BankAccount() = default;
    void deposit(double amount) {
        if(amount > 0.0) { balance += amount; }
    }

    virtual bool withdraw(double amount) {
        if(amount > 0.0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        else {
            std::cout << "Deposit balance exceeds the limit" << std::endl;
            return false;
        }
    }

    double getBalance() const { return balance; }
    const std::string& getOwner() const { return owner; }

    virtual void showInfo() const {
        std::cout << "Owner: " << owner << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate{};

    public:
    SavingsAccount(std::string owner, double balance, double interestRate) :
        BankAccount(std::move(owner), balance), interestRate{interestRate} {}
    // Метод: addInterest() — збільшує баланс відповідно до процентної ставки.
    // (Наприклад: Balance = 1000, Interest = 5%. Після addInterest() Balance = 1050)
    void addInterest() {
        //balance * (interestRate / 100.0))
        deposit(getBalance() * (interestRate / 100.0));
    }

    void showInfo() const override {
        BankAccount::showInfo();
        std::cout << "Interest: " << interestRate << "%\n"
            << "-----------------------" << std::endl;
    }
};

class CreditAccount : public BankAccount {
private:
    double creditLimit{};

    public:
    CreditAccount(std::string owner_, double balance_, double creditLimit_) :
        BankAccount(std::move(owner_), balance_), creditLimit{creditLimit_} {}
    // Рахунок може мати від'ємний баланс, але не нижче кредитного ліміту.
    // (Наприклад: Balance = 1000, Credit limit = 2000. withdraw(2500) дозволено -> Balance = -1500.
    // Наступне withdraw(1000) заборонено, оскільки баланс стане нижчим за дозволений кредитний ліміт)
    bool withdraw(double amount) override {
        // Перевірка: новий баланс не повинен бути меншим за -creditLimit
        if (amount > 0.0 && (getBalance() - amount >= -creditLimit)) {
            setBalance(getBalance() - amount);
            return true;
        }
        std::cout << "Credit limit exceeded!\n";
        return false;
    }

    void showInfo() const override {
        BankAccount::showInfo();
        std::cout << "Credit limit: " << creditLimit << "\n"
            << "-----------------------" << std::endl;
    }
};

int main() {

    // Owner: Vova
    // Balance: 1050
    // Interest: 5%
    SavingsAccount ac1("Vova", 1000, 5);
    ac1.addInterest();
    ac1.showInfo();

    CreditAccount ac2("Alex", 1000, 2000);
    ac2.withdraw(2500);
    ac2.showInfo();

    return 0;
}