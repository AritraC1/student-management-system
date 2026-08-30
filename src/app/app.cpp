#include <iostream>
#include "app.hpp"

void Application::run() {
    std::cout << "==========================" << std::endl;
    std::cout << "Student Management System" << std::endl;
    std::cout << "==========================" << std::endl;

    std::cout << "\nFunctionalities which can be performed:" << std::endl;
    std::cout << "1. Add Student" << std::endl;
    std::cout << "2. View Students" << std::endl;
    std::cout << "3. Search Student" << std::endl;
    std::cout << "4. Delete Student" << std::endl;
    std::cout << "5. Exit Program" << std::endl;

    int choice;
    std::cout << "Enter choice:";
    std::cin >> choice;

    // switch (choice)
    // {
    // case 1:
    //     /* code */

    //     break;
    
    // default:
    //     break;
    // }
}