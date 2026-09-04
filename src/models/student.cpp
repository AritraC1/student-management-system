#include <string>
#include <vector>
#include <sstream>

#include "student.hpp"
#include "utils/utils.hpp"

StudentModel::StudentModel (
    std::string name,
    int age,
    std::vector<Course> course,
    std::string id
): id(id.empty() ? generate_id() : id), name(name), age(age), course(course) {}

std::string StudentModel::serialize() const {
    std::ostringstream oss;
    oss << id << '|' << name << '|' << age << '|';
    for (size_t i = 0; i < course.size(); ++i) {
        if (i > 0) oss << ',';
        oss << static_cast<int>(course[i]);
    }
    return oss.str();
}

StudentModel StudentModel::deserialize(const std::string& line) {
    std::vector<std::string> fields;
    std::stringstream ss(line);
    std::string field;
    while (std::getline(ss, field, '|')) fields.push_back(field);

    std::string id   = fields.size() > 0 ? fields[0] : "";
    std::string name = fields.size() > 1 ? fields[1] : "";
    int age           = fields.size() > 2 ? std::stoi(fields[2]) : 0;

    std::vector<Course> courses;
    if (fields.size() > 3 && !fields[3].empty()) {
        std::stringstream cs(fields[3]);
        std::string c;
        while (std::getline(cs, c, ',')) {
            courses.push_back(static_cast<Course>(std::stoi(c)));
        }
    }

    return StudentModel(name, age, courses, id);
}

void StudentModel::set_student_details(std::string name, int age, std::vector<Course> course) {
    this->name = name; // this-> prevents shadowing
    this->age = age;
    this->course = course;
};

void StudentModel::set_name(std::string new_name) {
    name = new_name;
};

void StudentModel::set_courses(std::vector<Course> new_course){
    course = new_course;
};

void StudentModel::display_details() const {
    std::cout << "ID: " << id << ", Name: " << name << ", Age: " << age << std::endl;
}

std::string StudentModel::get_id() const { 
    return id; 
}

std::string StudentModel::get_name() const { 
    return name;
}

int StudentModel::get_age() const { 
    return age;
}

std::vector<Course> StudentModel::get_courses() const { 
    return course; 
}