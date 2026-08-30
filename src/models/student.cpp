#include <string>
#include <vector>

#include "student.hpp"
#include "utils/utils.hpp"

StudentModel::StudentModel (
    std::string name,
    int age,
    std::vector<Course> course,
    std::string id
): id(id.empty() ? generate_id() : id), name(name), age(age), course(course) {}

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