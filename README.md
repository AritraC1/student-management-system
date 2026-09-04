# Student Management System

A C++ command-line application for managing student records.

## Features

- Add students
- View all students
- Search for a student by ID
- Delete students
- Assign courses to students
- Validate student age
- Write application events to a log file

> Student data is stored a file `data` and is loaded when the program starts.

## Build and run

```bash
./scripts/run.sh
```

Build without running:

```bash
./scripts/run.sh build
```

Remove build files:

```bash
./scripts/run.sh clean
```

## Requirements

- C++17-compatible compiler
- `g++` or `clang++`

## Project layout

```md
src/app/          Command-line menu
src/models/       Student data model
src/services/     Student operations
src/repository/   Student data access
src/storage/      In-memory storage
src/logging/      Application logging
scripts/run.sh    Build and run script
```

> Logs are written to `logs/log-file.txt`.

---