#pragma once

#include <string>
#include <vector>

class Course; // forward declaration

class Student {
public:
    explicit Student(const std::string& name);

    void enroll(Course* course);

    const std::string& getName() const;
    const std::vector<Course*>& getCourses() const;

    ~Student() = default;

private:
    std::string name_;
    std::vector<Course*> courses_; // агрегация
};
