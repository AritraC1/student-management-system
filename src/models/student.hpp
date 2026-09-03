#pragma once

#include <iostream>
#include <string>
#include <vector>

enum class Course {
    PHYSICS, CHEMISTRY, BIOLOGY, MATHS, ACCOUNTS, ENGLISH
};

class StudentModel {
    std::string id;
    std::string name;
    int age;
    std::vector<Course> course;

    // constructor
    public:
        StudentModel(
            std::string name, 
            int age, 
            std::vector<Course> course,
            std::string id = ""
        );

        // set student details
        void set_student_details(std::string name, int age, std::vector<Course> course);

        // update student name
        void set_name(std::string name);

        // update courses
        void set_courses(std::vector<Course> course);

        // get student details
        void display_details() const;

        // get id
        std::string get_id() const;
        
        // get name
        std::string get_name() const;

        // get age
        int get_age() const;

        // get courses
        std::vector<Course> get_courses() const;
};