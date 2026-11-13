#include "Course.h"
#include "Professor.h"

#include <iostream>

int main() {
    Professor professor("Ivanov");
    Course course("C++ Programming", &professor);

    course.addTopic("Classes and objects");
    course.addTopic("Inheritance");
    course.addTopic("STL");

    std::cout << "Course: " << course.getName() << '\n';
    std::cout << "Professor: " << course.getProfessor()->getName() << '\n';
    std::cout << "Topics: " << course.getTopics().size() << '\n';

    return 0;
}
