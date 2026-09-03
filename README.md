# Student Management System

A simple C++ console application for managing student records.

## Features
- Add a student
- Update student details
- Delete a student
- Search a student by ID
- View all students
- In-memory data storage
- Application logging

## Project structure
- src/ - main source code
- src/app/ - application entry
- src/models/ - student model
- src/services/ - business logic
- src/repository/ - repository layer
- src/storage/ - in-memory storage implementation
- logs/ - log output
- scripts/run.sh - build and run script

## Run the project
```bash
./scripts/run.sh
```

Build only:
```bash
./scripts/run.sh build
```

Clean build files:
```bash
./scripts/run.sh clean
```

## Requirements
- C++17 compatible compiler
- g++, clang++, or similar

This project follows a simple layered structure: app -> service -> repository -> storage.

---