//
// Created by Кирило Вєтров on 09.09.2026.
//
#include <iostream>
#include <string>
#include <cstdlib>                                                                  // Для std::rand та std::srand
#include <ctime>                                                                    // Для std::time

// Абстрактний клас.
// Абстрактний клас - клас в якому є хоча б один чисто віртуальний метод ( = 0 )
class Character {
    private:
    std::string name{};
    double health{};
    double damage{};

protected:
    Character(std::string name_, double health_, double damage_) :
        name(std::move(name_)), health(health_), damage(damage_) {}

public:
    virtual void takeDamage(double damage_) {
        if (damage_ > 0.0) {
            health -= damage_;
            if (health < 0.0) { health = 0.0; }
        }
    }
    virtual void attack(Character& target) = 0;                                     // — чисто віртуальний
    //virtual void showInfo() const {}
    void showInfo() const {
        std::cout << name << " HP: " << health << std::endl;
    }
    //
    const std::string& getName() const { return name; }
    double getHealth() const { return health; }
    double getDamage() const { return damage; }
    //void setHealth(double health_) { health = health_; }
    // Віртуальний деструктор
    virtual ~Character() = default;
};

// Warrior — звичайна атака: 50 damage.
// Mage — атака: 70 damage. Але після кожної атаки маг втрачає 10 HP.
// Archer — звичайна атака: 40 damage. Має 20% шанс завдати подвійної шкоди (Critical attack: 80 damage).
class Warrior : public Character {
public:
    Warrior(std::string name_, double health_, double damage_) :
        Character(std::move(name_), health_, damage_) {}

    void attack(Character &target) override {
        std::cout <<
            getName() << " attacks " << target.getName() << " for " << getDamage() << " damage"
        << std::endl;
        target.takeDamage(getDamage());
    }
};

class Mage : public Character {

    public:
    Mage(std::string name_, double health_, double damage_) :
        Character(std::move(name_), health_, damage_) {}

    void attack(Character &target) override {
        std::cout <<
            getName() << " attacks " << target.getName() << " for " << getDamage() << " damage, "
        << getName() << " loses 10 HP" << std::endl;
        target.takeDamage(getDamage());
        takeDamage(10.0);
    }

};

class Archer : public Character {
    public:
    Archer(std::string name_, double health_, double damage_) :
        Character((std::move(name_)), health_, damage_) {}

    void attack(Character &target) override {
        //takeDamage(10.0);
        // random -> rand
        // Число в потрібному діапазоні (наприклад, від 1 до 100):
        // Формула: std::rand() % range + min
        int dmg = (std::rand() % 5) + 1;

        std::cout << getName() << " attacks " << target.getName() << " for ";
        if (dmg == 5) {
            target.takeDamage(getDamage() * 2.0);                                   // Critical attack
            std::cout << getDamage() * 2.0 << " Critical attacks" << std::endl;
        }
        else {
            target.takeDamage(getDamage());
            std::cout << getDamage() << " damage" << std::endl;
        }
    }

};


int main() {
    // 1. Ініціалізуємо генератор поточним часом (робимо це ОДИН раз за всю програму!)
    std::srand(std::time(nullptr));

    Warrior warrior("Warrior", 200.0, 50.0);
    Mage mage("Mage", 120.0, 70.0);
    Archer archer("Archer", 100.0, 40.0);
    warrior.attack(mage);
    mage.attack(warrior);
    archer.attack(warrior);

    warrior.showInfo();
    mage.showInfo();
    archer.showInfo();

    return 0;
}