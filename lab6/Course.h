#pragma once

#include <string>
#include <vector>

class Professor; // forward declaration
class Student;   // forward declaration

class Course {
public:
    Course(const std::string& name, Professor* professor);
    ~Course() = default;

    void addTopic(const std::string& topic);
    void enrollStudent(Student* student);

    const std::string& getName() const;
    const std::vector<std::string>& getTopics() const;
    const Professor* getProfessor() const;
    const std::vector<Student*>& getStudents() const;
    int getStudentCount() const;

private:
    std::string name_;
    std::vector<std::string> topics_;   // композиция
    Professor* professor_;              // агрегация
    std::vector<Student*> students_;    // агрегация
};
