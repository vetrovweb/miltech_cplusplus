//
// Created by Кирило Вєтров on 06.09.2026.
//
#include <iostream>
#include <string>
#include <utility>                                                        // for std::move

namespace {
    using std::cout;
    using std::endl;
    using std::string;
}

// --------------------------- Task 1 -------------------------------
class Employee {
    private:
    string name{};
    double salary{0.0};                                                   // salary - ЗП

public:
    // Конструктори
    // std::move(name) замість const string& name_, так краще.
    Employee(string name_, double salary_) : name(std::move(name_)), salary(salary_) {}

    // Обов'язковий віртуальний деструктор!
    virtual ~Employee() = default;

    // Чисто віртуальний метод (= 0)
    virtual double calculateBonus() const = 0;

    string getName() const { return name; }
    double getSalary() const { return salary; }

    // virtual void showInfo() const {
    //     cout << "Name: " << name << "\n" << "Salary: " << salary << endl;
    // }
    // Універсальний варіант для всіх класів-нащадків
    virtual void showInfo() const {
        cout << "Name: " << name << "\n"
             << "Salary: " << salary << "\n"
             << "Bonus: " << calculateBonus() << "\n"                           // поліморфний виклик!
             << "Total: " << salary + calculateBonus() << "\n"
             << "-----------------------" << endl;
    }
};

// Класи-нащадки
class Developer : public Employee {
    private:
    int countProjects{};
    static constexpr double bonusDev = 100.0;                                   // only +100$ for project

    public:
        Developer(string name_, double salary_, int countProjects_)
            : Employee(std::move(name_), salary_), countProjects(countProjects_) {}

        //double calculateBonus override () {}
        double calculateBonus() const override {
            return countProjects * bonusDev; // $100 за кожен проєкт
        }

        // Вже непотрібний, є у батьківському класі
        // void showInfo() const override {
        //     cout << "Name: " << getName() << "\n"
        //     << "Salary: " << getSalary() << "\n"
        //     << "Bonus: " << calculateBonus() << "\n"
        //     << "Total: " << calculateBonus() + getSalary() << "\n"
        //     << "-----------------------" << endl;
        // }
};

class Manager : public Employee {
    private:
    int countWorkers{};
    static constexpr double bonusMan = 500.0;                                  // 500 + 100$/person

    public:
    Manager(string name_, double salary_, int countWorkers_) : Employee(std::move(name_), salary_), countWorkers(countWorkers_) {}

    double calculateBonus() const override {
        return (countWorkers * 100.0) + bonusMan; // $100 за кожен проєкт
    }

    // void showInfo() const override {
    //     cout << "Name: " << getName() << "\n"
    //     << "Salary: " << getSalary() << "\n"
    //     << "Bonus: " << calculateBonus() << "\n"
    //     << "Total: " << calculateBonus() + getSalary() << "\n"
    //     << "-----------------------" << endl;
    // }
};
// ==================================================================

int main() {

    // Developer: Vova, зарплата $3000, 5 проєктів
    //
    // Name: Vova
    // Salary: 3000
    // Bonus: 500
    // Total: 3500
    // ----------------
    Developer developer("Vova", 3000, 5);
    developer.showInfo();

    // Manager: Alex, зарплата $4000, 8 працівників
    Manager manager("Alex", 4000, 8);
    manager.showInfo();


    return 0;
}