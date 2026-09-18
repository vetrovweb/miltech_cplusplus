//
// Created by Кирило Вєтров on 11.09.2026.
//
#include <iostream>
#include <vector>


class LibraryItem {
private:
    std::string title{};
    int id{0};

public:
    LibraryItem(std::string title) : title{std::move(title)} {}

public:
    virtual void display() = 0;
    virtual ~LibraryItem() = default;

    std::string getTitle() const { return title; }
};

class Book : public LibraryItem {
private:
    std::string author{};
    int pages{0};

public:
    Book(std::string title_, std::string author_, int page_) :
        LibraryItem(std::move(title_)), author {author_}, pages{page_} {}

    void display() override {
        std::cout << "Книга: " << getTitle() << ", автор: " << author << ", " << pages << " стор." << std::endl;
    }
};

class DVD : public LibraryItem {
private:
    double durationMinutes{0.0};

public:
    DVD(std::string title_, double duration_)
        : LibraryItem(std::move(title_)), durationMinutes{duration_} {}

    void display() override {
        std::cout << "DVD: " << getTitle() << ", тривалість: " << durationMinutes << " хв." << std::endl;
    }
};

class Library {
public:

    // Альтернатива (Modern C++): У продакшн-коді зазвичай застосовують розумні вказівники
    // (std::vector<std::unique_ptr<LibraryItem>>), які гарантують RAII без ручного delete.
    std::vector<LibraryItem*> books;

    // Конструктор за замовчуванням
    Library() = default;

    void add(LibraryItem* item)
    {
        books.push_back(item);
    }

    void showAll() {
        for (auto& book : books) {
            book->display();
        }
    }

    // ДЕСТРУКТОР
    // Знищує Library -> знищує всі елементи всередині
    ~Library() {
        for (LibraryItem* item : books) {
            delete item; // Звільняємо динамічну пам'ять для кожного Book / DVD
        }
        books.clear();
    }
};

int main() {

    Library library;
    library.add(new Book("Кобзар", "Т. Шевченко", 352));
    library.add(new Book("Війна і мир", "Л. Толстой", 1274));
    library.add(new DVD("Матриця", 136.0));
    library.add(new DVD("Втеча з Шоушенка", 142.0));
    library.showAll();
    return 0;
}