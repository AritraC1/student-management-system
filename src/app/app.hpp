#pragma once

#include "repository/student_repository.hpp"
#include "services/student_service.hpp"

class Application {
    StudentRepository repository;
    StudentService service;

    public:
        // inject repository into service
        Application() : service(repository) {}

        // run app
        void run();
};