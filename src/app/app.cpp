#include <iostream>
#include <sstream>
#include "app.hpp"

namespace {
    std::vector<Course> prompt_courses() {
        std::cout << "Select courses (space-separated numbers):\n";
        std::cout << "0=Physics 1=Chemistry 2=Biology 3=Maths 4=Accounts 5=English\n> ";

        std::string line;
        std::getline(std::cin, line);

        std::vector<Course> courses;
        std::istringstream iss(line);
        int choice;
        while (iss >> choice) {
            if (choice >= 0 && choice <= 5) courses.push_back(static_cast<Course>(choice));
        }
        return courses;
    }
}

void Application::run() {
    bool running = true;

    while (running) {
        std::cout << "\n===== Student Management System =====" << std::endl;
        std::cout << "1. Add Student\n2. View Students\n3. Search Student\n";
        std::cout << "4. Delete Student\n5. Exit Program" << std::endl;
        std::cout << "========================================" << std::endl;

        int choice;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore(); // flush leftover newline before getline calls

        switch (choice) {
            case 1: {
                std::string name;
                int age;

                std::cout << "Name: ";
                std::getline(std::cin, name);

                std::cout << "Age: ";
                std::cin >> age;
                std::cin.ignore();

                auto courses = prompt_courses();

                try {
                    service.add_student(name, age, courses);
                    std::cout << "Student added.\n";
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 2: {
                auto students = service.get_all_students();
                if (students.empty()) std::cout << "No students found.\n";
                for (const auto& s : students) s.display_details();
                break;
            }
            case 3: {
                std::string id;
                std::cout << "Enter student ID: ";
                std::cin >> id;

                auto result = service.get_student(id);
                if (result) result->display_details();
                else std::cout << "Student not found.\n";
                break;
            }
            case 4: {
                std::string id;
                std::cout << "Enter student ID: ";
                std::cin >> id;

                std::cout << (service.delete_student(id) ? "Student deleted.\n" : "Student not found.\n");
                break;
            }
            case 5:
                running = false;
                break;

            default:
                std::cout << "Invalid choice.\n";
        }
    }
}