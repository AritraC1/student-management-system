#include <iostream>
#include "app.hpp"

void Application::run() {
    std::cout << "\n===== Student Management System =====" << std::endl;
    std::cout << "1. Add Student" << std::endl;
    std::cout << "2. View Students" << std::endl;
    std::cout << "3. Search Student" << std::endl;
    std::cout << "4. Delete Student" << std::endl;
    std::cout << "5. Sort Records" << std::endl;
    std::cout << "6. Exit Program" << std::endl;
    std::cout << "========================================" << std::endl;

    int choice;
    std::cout << "Enter choice:";
    std::cin >> choice;
    std::cout << "choice:" << choice;

    // switch (choice)
    // {
    // case 1:
    //     /* code */

    //     break;
    
    // default:
    //     break;
    // }
}