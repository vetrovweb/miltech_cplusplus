//
// Created by Кирило Вєтров on 04.09.2026.
//
#include <iostream>

using namespace std;

class Car1 {
private:
    string brand;
    int speed;
    double fuel;

public:
    Car1 (string car, double fuel) : brand(car), fuel(fuel) {}

    void accelerate (int value) {
        if(value > 0 && value > 250) { speed = value; }
    }

    void brake () {
        if (speed > 0) { speed = 0; }
    }

    void refuel (double liters) {
        if (liters > 0) { fuel = liters; }
    }

    void showInfo () {
        cout << brand << endl;
        cout << fuel << endl;
        //cout << speed << endl;
    }

};

class BankAccount {
private:
    double balance{};

public:
    BankAccount (double balance_) : balance(balance_) {}

    void deposit (double amount) {
        if (amount > 0) { balance += amount; }
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        }
        else {
            std::cout << "Не можливо зняти " << amount << "$. " << "Недостатньо коштів на рахунку" << std::endl;
        }
    }

    // void getBalance () {
    //     cout << "На рахунку: " << balance << endl;
    // }
    double getBalance() const { return balance; }

};

class Vehicle {
protected:
    string brand;
    int year;

    Vehicle(string brand_, int year_) : brand(brand_), year(year_) {}
public:
    virtual void showInfo () {}
    virtual void move() {}
};

class Car : public Vehicle {
private:
    int doors;
public:
    Car(string brand_, int year_, int doors_) : Vehicle(brand_, year_), doors(doors_) {}

    void showInfo() override {
        cout << brand << '\t' << year << '\t' << doors << endl;
    }

    void move() override {
        cout << "Car drives on the road" << endl;
    }
};

class Motocycle : public Vehicle {
private:
    double engineVolume;

public:
    Motocycle(string brand_, int year_, int engineVolume_) : Vehicle(brand_, year_), engineVolume(engineVolume_) {}
    void showInfo() override {
        cout << brand << '\t' << year << '\t' << engineVolume << endl;
    }

    void move() override {
        cout << "Motocycle drives on the road" << endl;
    }
};

class Truck : public Vehicle {
private:
    double loadCapacity;

public:
    Truck(string brand_, int year_, double loadCapacity_) : Vehicle(brand_, year_), loadCapacity(loadCapacity_) {}
    void showInfo() override {
        cout << brand << '\t' << year << '\t' << loadCapacity << endl;
    }

    void move() override {
        cout << "Truck drives on the road" << endl;
    }
};


int main() {
    Car1 audi("Audi", 50);
    audi.showInfo();

    audi.refuel(100);
    audi.showInfo();

    BankAccount account(1000);
    account.deposit(100);
    //account.withdraw(10000);
    cout << "На рахунку " << account.getBalance() << endl;

    cout << "--------------------------------------------------------" << endl;

    Car car("BMW", 2020, 4);
    car.showInfo();

    Motocycle moto("Honda", 2021, 600);
    moto.showInfo();

    Truck truck("Volvo", 2019, 1000);
    truck.showInfo();

    //car.move();

    // Vehicle vehicle(1000, 2000); - ERROR
    Vehicle* vehicles[3] = {
        &car,
        &moto,
        &truck
    };

    for (Vehicle* vehicle : vehicles) {
        vehicle->move();
    }

    return 0;
}