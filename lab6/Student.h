#pragma once

#include <string>
#include <vector>

class Course; // forward declaration

class Student {
public:
    explicit Student(const std::string& name);
    virtual ~Student() = default;

    void enroll(Course* course);

    const std::string& getName() const;
    const std::vector<Course*>& getCourses() const;
    int getCourseCount() const;

    std::string getStatus() const;
    int getTuition() const;

private:
    std::string name_;
    std::vector<Course*> courses_; // агрегация
};
