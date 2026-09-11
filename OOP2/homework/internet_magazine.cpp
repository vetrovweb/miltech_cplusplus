//
// Created by Кирило Вєтров on 09.09.2026.
//
#include <iostream>

namespace {
    // Абстрактний клас
    class Product {
    private:
        std::string name{};
        double price{};

    protected:
        Product(std::string name_, double price_) : name(std::move(name_)), price(price_) {}

    public:
        virtual ~Product() = default;                                                // Віртуальний деструктор

        const std::string& getName() const { return name; }
        double getPrice() const { return price; }
        virtual double getFinalPrice() const = 0;                                    // чисто віртуальний (= 0) - віртуальна функції
        virtual void showInfo() const {}                                             // — віртуальний
    };

    class PhysicalProduct : public Product {
    private:
        double deliveryPrice{};

    public:
        PhysicalProduct(std::string name, double price, double deliveryPrice_) : Product(std::move(name), price), deliveryPrice(deliveryPrice_) {}
        //virtual ~PhysicalProduct() = default;

        // For MISRA shall be declared with the virtual keywords
        double getFinalPrice() const override { return getPrice() + deliveryPrice; }
        // Product: Laptop
        // Price: 3000
        // Delivery: 50
        // Final price: 3050
        // ----------------
        void showInfo() const override {
            std::cout << "Product: " << getName() << "\n"
                << "Price: " << getPrice() << "\n"
                << "Delivery: " << deliveryPrice << "\n"
                << "Final price: " << getFinalPrice() << "\n"
                << "--------------------"
            << std::endl;
        }
    };

    class DigitalProduct : public Product {
    private:
        double discount{};

    public:
        DigitalProduct(std::string name, double price, double discount_) : Product(std::move(name), price), discount(discount_) {}
        //virtual ~DigitalProduct() = default;

        double getFinalPrice() const override { return getPrice() - discount; }

        void showInfo() const override {
            std::cout << "Product: " << getName() << "\n"
                << "Price: " << getPrice() << "\n"
                << "Delivery: " << discount << "\n"
                << "Final price: " << getFinalPrice() << "\n"
                << "--------------------"
            << std::endl;
        }
    };
}

int main() {

    PhysicalProduct pr("Laptop", 3000.0, 50.0);
    pr.showInfo();

    DigitalProduct dp("Game", static_cast<double>(100), 20.0);
    dp.showInfo();

    return 0;
}