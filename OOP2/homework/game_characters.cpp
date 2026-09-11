//
// Created by Кирило Вєтров on 09.09.2026.
//
#include <iostream>
#include <string>

// Абстрактний клас.
// Абстрактний клас - клас в якому є хоча б один чисто віртуальний метод ( = 0 )
class Character {
    private:
    std::string name{};
    double health{};
    double damage{};

public:
    Character(std::string name_, double health_, double damage_) :
        name(std::move(name_)), health(health_), damage(damage_) {}

    virtual void attack(Character& target) = 0;                                        // — чисто віртуальний
    virtual void takeDamage(double damage_) {}
    virtual void showInfo() const {}
    //
    const std::string& getName() const { return name; }
    double getHealth() const { return health; }
    double getDamage() const { return damage; }
    void setHealth(double health_) { health = health_; }
    // Віртуальний деструктор
    virtual ~Character() = default;
};

// Warrior — звичайна атака: 50 damage.
// Mage — атака: 70 damage. Але після кожної атаки маг втрачає 10 HP.
// Archer — звичайна атака: 40 damage. Має 20% шанс завдати подвійної шкоди (Critical attack: 80 damage).
class Warrior : public Character {
public:
    Warrior(std::string name_, double health_, double damage_) :
        Character((std::move(name_)), health_, damage_) {}

    void takeDamage(double damage_) override {
        if (damage_ > 0.0) {
            setHealth(getHealth() - damage_);
            if (getHealth() < 0.0) { setHealth(0.0); }
        }
    }

    void attack(Character &target) override {
        std::cout <<
            getName() << " attacks " << target.getName() << " for " << getDamage() << " damage"
        << std::endl;
        target.takeDamage(getDamage());
    }

    void showInfo() const override {
        std::cout << getName() << " HP: " << getHealth() << std::endl;
    }
};

class Wizard : public Character {};

class Archer : public Character {};


int main() {

    Warrior warrior("Warrior", 200, 50);
    Warrior mage("Mage", 120, 70);
    warrior.attack(mage);
    mage.attack(warrior);

    warrior.showInfo();

    return 0;
}