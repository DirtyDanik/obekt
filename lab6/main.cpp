#include "BudgetStudent.h"
#include "Course.h"
#include "ForeignStudent.h"
#include "PaidStudent.h"
#include "Professor.h"
#include "Student.h"

#include <iostream>
#include <vector>

void printStudentCourses(const Student& student) {
    for (Course* course : student.getCourses()) {
        const Professor* professor = course->getProfessor();

        std::cout << "  " << course->getName() << " (Prof. ";

        if (professor != nullptr) {
            std::cout << professor->getName();
        } else {
            std::cout << "none";
        }

        std::cout << ")\n";
    }
}

int main() {
    Professor ivanov("Ivanov");
    Professor petrova("Petrova");

    Course oop("OOP", &ivanov);
    Course math("Math", &petrova);
    Course physics("Physics", &ivanov);

    oop.addTopic("Classes and objects");
    oop.addTopic("Constructors");
    oop.addTopic("Rule of three");

    math.addTopic("Limits");
    math.addTopic("Derivatives");

    physics.addTopic("Mechanics");
    physics.addTopic("Thermodynamics");
    physics.addTopic("Electromagnetism");

    BudgetStudent alice("Alice", 1500);
    PaidStudent bob("Bob", 200000);
    BudgetStudent gleb("Gleb", 1200);
    ForeignStudent chen("Chen", "China");

    // Запись со стороны студента и со стороны курса.
    alice.enroll(&oop);
    oop.enrollStudent(&alice);
    alice.enroll(&math);
    math.enrollStudent(&alice);

    bob.enroll(&physics);
    physics.enrollStudent(&bob);

    gleb.enroll(&oop);
    oop.enrollStudent(&gleb);
    gleb.enroll(&physics);
    physics.enrollStudent(&gleb);

    chen.enroll(&math);
    math.enrollStudent(&chen);

    // Повторная запись: дубликаты не должны добавляться.
    alice.enroll(&oop);
    oop.enrollStudent(&alice);

    std::cout << "=== Students ===\n";

    std::cout << alice.getName() << " (" << alice.getStatus()
              << "), tuition: " << alice.getTuition() << '\n';
    printStudentCourses(alice);

    std::cout << bob.getName() << " (" << bob.getStatus()
              << "), tuition: " << bob.getTuition() << '\n';
    printStudentCourses(bob);

    std::cout << gleb.getName() << " (" << gleb.getStatus()
              << "), tuition: " << gleb.getTuition() << '\n';
    printStudentCourses(gleb);

    std::cout << chen.getName() << " (" << chen.getStatus()
              << "), tuition: " << chen.getTuition()
              << ", country: " << chen.getCountry() << '\n';
    printStudentCourses(chen);

    std::vector<Course*> courses{&oop, &math, &physics};

    std::cout << "\n=== Courses ===\n";

    for (Course* course : courses) {
        std::cout << '\n' << course->getName() << " (Prof. "
                  << course->getProfessor()->getName() << ")\n";
        std::cout << "  Topics: " << course->getTopics().size() << '\n';

        for (const std::string& topic : course->getTopics()) {
            std::cout << "  - " << topic << '\n';
        }

        std::cout << "  Students: " << course->getStudentCount() << '\n';

        for (Student* student : course->getStudents()) {
            std::cout << "  - " << student->getName() << '\n';
        }
    }

    const int totalTuition =
        alice.getTuition() +
        bob.getTuition() +
        gleb.getTuition() +
        chen.getTuition();

    std::cout << "\n=== Summary ===\n";
    std::cout << "\nTotal tuition: " << totalTuition << '\n';

    std::cout << "\n=== Scholarships ===\n\n";
    std::cout << alice.getName() << ": " << alice.getScholarship() << '\n';
    std::cout << gleb.getName() << ": " << gleb.getScholarship() << '\n';

    // Эксперимент 2: getScholarship() есть в Student, но методы не виртуальные.
    // Через Student* вызывается версия базового класса и возвращается 0.
    std::cout << "\n=== Experiment: calls through Student* ===\n";

    Student* all[] = {&alice, &bob, &gleb, &chen};
    int totalScholarshipThroughBase = 0;

    for (Student* student : all) {
        std::cout << student->getName()
                  << ": status=" << student->getStatus()
                  << ", tuition=" << student->getTuition()
                  << ", scholarship=" << student->getScholarship() << '\n';

        totalScholarshipThroughBase += student->getScholarship();
    }

    std::cout << "Total scholarship through Student*: "
              << totalScholarshipThroughBase << '\n';

    return 0;
}
