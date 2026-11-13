#include "Course.h"
#include "Professor.h"
#include "Student.h"

#include <iostream>

int main() {
    Professor professor1("Ivanov");
    Professor professor2("Petrova");

    Course cppCourse("C++ Programming", &professor1);
    Course algoCourse("Algorithms", &professor2);

    cppCourse.addTopic("Classes and objects");
    cppCourse.addTopic("Inheritance");
    cppCourse.addTopic("STL");

    algoCourse.addTopic("Sorting");
    algoCourse.addTopic("Graphs");

    Student student("Anna");
    student.enroll(&cppCourse);
    student.enroll(&algoCourse);
    student.enroll(&cppCourse); // дубликат не добавится

    std::cout << "Student: " << student.getName() << '\n';
    std::cout << "Courses:\n";

    for (Course* course : student.getCourses()) {
        std::cout << "  " << course->getName() << '\n';
    }

    std::cout << "Number of courses: " << student.getCourses().size() << '\n';

    return 0;
}
