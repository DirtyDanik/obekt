#pragma once

#include <string>
#include <vector>

class Professor; // forward declaration

class Course {
public:
    Course(const std::string& name, Professor* professor);

    void addTopic(const std::string& topic);

    const std::string& getName() const;
    const std::vector<std::string>& getTopics() const;
    const Professor* getProfessor() const;

    ~Course() = default;

private:
    std::string name_;
    std::vector<std::string> topics_; // композиция
    Professor* professor_;            // агрегация
};
