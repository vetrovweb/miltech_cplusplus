//
// Created by Кирило Вєтров on 06.09.2026.
//
#include <iostream>

class Student {
    private:
    std::string name{};
    double grade{};

    public:
    Student(std::string name_, double grade_) : name(name_), grade(grade_) {}

    void print() const {
        std::cout << "Студент: [" << name << "], Бал: " << "[" << grade << "]." << std::endl;
    }

    // Геттер — це метод, який просто повертає вже існуюче приватне поле.
    // Йому не потрібні вхідні аргументи, але він має бути позначений як const (бо не змінює об'єкт).
    std::string getName() const { return name; }
    double getGrade() const { return grade; }
};


int main () {

    std::vector <Student> students = {
        {"Олег", 4.5},
        {"Анна", 4.9},
        {"Іван", 3.8}
    };

    for (const auto& student : students ) {
        student.print();
    }


    Student topStudent = students[0];
    for (const auto& student : students) {
        if (student.getGrade() > topStudent.getGrade()) {
            topStudent = student;
        }
    }

    std::cout << "\n--- Студент з найвищим балом ---\n";
    topStudent.print();

    return 0;
}