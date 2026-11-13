#include "Student.h"

#include <iostream>

int main() {
    Student student("Alice");

    std::cout << "Name: " << student.getName() << '\n';
    std::cout << "Status: " << student.getStatus() << '\n';
    std::cout << "Tuition: " << student.getTuition() << '\n';

    return 0;
}
