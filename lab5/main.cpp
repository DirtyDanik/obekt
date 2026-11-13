#include "Course.h"

#include <iostream>

int main() {
    Course course("C++ Programming");

    course.addTopic("Classes and objects");
    course.addTopic("Inheritance");
    course.addTopic("STL");

    std::cout << "Course: " << course.getName() << '\n';
    std::cout << "Topics: " << course.getTopics().size() << '\n';

    return 0;
}
