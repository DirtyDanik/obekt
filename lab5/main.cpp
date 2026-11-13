#include "Course.h"
#include "Professor.h"
#include "Student.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

void printCourseInfo(const Course* course) {
    const Professor* professor = course->getProfessor();

    std::cout << "  " << course->getName()
              << " (" << course->getTopics().size() << " topics, professor: ";

    if (professor != nullptr) {
        std::cout << professor->getName();
    } else {
        std::cout << "none";
    }

    std::cout << ")\n";

    for (const std::string& topic : course->getTopics()) {
        std::cout << "    - " << topic << '\n';
    }
}

int main() {
    // Контейнер владеет профессорами: в main нет new/delete.
    std::vector<std::unique_ptr<Professor>> professors;
    professors.push_back(std::make_unique<Professor>("Ivanov"));
    professors.push_back(std::make_unique<Professor>("Petrova"));

    // Курсы созданы на стеке и агрегируют профессоров.
    Course cppCourse("C++ Programming", professors[0].get());
    Course algoCourse("Algorithms", professors[1].get());

    cppCourse.addTopic("Classes and objects");
    cppCourse.addTopic("Inheritance");
    cppCourse.addTopic("STL");

    algoCourse.addTopic("Sorting");
    algoCourse.addTopic("Graphs");

    std::vector<Course*> courses{&cppCourse, &algoCourse};

    Student student("Anna");
    student.enroll(&cppCourse);
    student.enroll(&algoCourse);
    student.enroll(&cppCourse); // дубликат не добавится

    std::cout << "Professors and their courses:\n";
    for (const std::unique_ptr<Professor>& professor : professors) {
        std::cout << professor->getName() << ":";

        for (Course* course : courses) {
            if (course->getProfessor() == professor.get()) {
                std::cout << ' ' << course->getName();
            }
        }

        std::cout << '\n';
    }

    std::cout << "\nCourses:\n";
    for (Course* course : courses) {
        printCourseInfo(course);
    }

    std::cout << "\nStudent: " << student.getName() << '\n';
    std::cout << "Courses of the student:\n";
    for (Course* course : student.getCourses()) {
        std::cout << "  " << course->getName() << '\n';
    }

    std::cout << "\nNumber of courses: " << student.getCourses().size() << '\n';

    return 0;
}
