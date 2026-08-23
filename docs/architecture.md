# Architecture
The Student Management System is a CLI-based application written in C++.

The system will manage student information, attendance, marks, GPA, fees, and user roles. The project will be developed incrementally in phases.

## Architecture Style
The application will follow a simple layered architecture.

```md
CLI 
  ↓ 
Services 
  ↓ 
Repositories 
  ↓ 
File Storage
```

## Components

### CLI
Handles user interaction.

**Responsibilities:**
- Display menus
- Read user input
- Display results and errors

### Services
Contains the application's business logic.

**Responsibilities:**
- Student management
- Attendance calculations
- GPA calculations
- Fee management
- Validation

### Repositories
Handles data access.

**Responsibilities:**
- Save data
- Load data
- Find data
- Update data
- Delete data

### File Storage
Stores application data permanently.

**Example:**

```md
data/
├── students.txt
├── attendance.txt
├── marks.txt
└── fees.txt
```

## Layer Rules
- CLI communicates with Services.
- Services contain business logic.
- Services communicate with Repositories.
- Repositories handle data access.
- CLI should not directly access files.
- Business logic should not be placed in the CLI.

## Design Goals
- Keep responsibilities separated.
- Keep the code easy to understand.
- Make the system easy to extend.
- Minimize coupling between components.
- Practice clean C++ design.

---