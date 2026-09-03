#pragma once

#include <string>
#include <vector>
#include <optional>
#include <stdexcept>

#include "models/student.hpp"
#include "repository/student_repository.hpp"
#include "logging/log_level.hpp"
#include "logging/logger.hpp"

class StudentService {
    StudentRepository& repository;

    public:
        StudentService(StudentRepository& repository) : repository(repository) {}

        void add_student(std::string name, int age, std::vector<Course> courses) {
            if (age <= 0) {
                Logger::log(LogLevel::ERROR, "Service: rejected student, invalid age " + std::to_string(age));
                throw std::invalid_argument("Age must be positive");
            }

            StudentModel s(name, age, courses); // id auto-generated
            repository.add(s);
        }

        bool update_student(std::string id, std::string name, int age, std::vector<Course> courses) {
            auto existing = repository.find_by_id(id);
            if (!existing) return false;

            existing->set_student_details(name, age, courses);
            return repository.update(*existing);
        }

        bool delete_student(std::string id) {
            return repository.remove(id);
        }

        std::optional<StudentModel> get_student(std::string id) {
            return repository.find_by_id(id);
        }

        std::vector<StudentModel> get_all_students() {
            return repository.get_all_students();
        }
};