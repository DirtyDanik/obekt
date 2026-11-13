#include "BudgetStudent.h"
#include "Course.h"
#include "PaidStudent.h"
#include "Professor.h"
#include "Student.h"

#include <iostream>

int main() {
    Professor professor("Ivanov");
    Course oop("OOP", &professor);

    oop.addTopic("Classes and objects");
    oop.addTopic("Constructors");
    oop.addTopic("Rule of three");

    BudgetStudent alice("Alice", 1500);
    PaidStudent bob("Bob", 200000);

    oop.enrollStudent(&alice);
    oop.enrollStudent(&bob);
    oop.enrollStudent(&alice); // дубликат не добавится

    std::cout << oop.getName() << " (Prof. "
              << oop.getProfessor()->getName() << ")\n";
    std::cout << "  Students: " << oop.getStudentCount() << '\n';

    for (Student* student : oop.getStudents()) {
        std::cout << "  - " << student->getName() << '\n';
    }

    return 0;
}
