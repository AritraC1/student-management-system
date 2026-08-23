# Project Requirement Document (PRD)

## Overview
Student Management System is a CLI-based application built in C++ to manage student records and academic information.

## Goal
The goal of the system is to provide a simple way to manage student information through a command-line interface.

The project will be developed incrementally, with new features added in multiple phases.

## Users
- **Admin:** Can manage all student records and system data.
- **Teacher:** Can manage attendance and marks.
- **Student:** Can view their own information and academic records.

## Functional Requirements

### Phase 1 - Student Management
- Add Student
- Update Student
- Delete Student
- Search Student
- View All Students

### Phase 2 - Persistence
- Save data to file
- Load data from file

### Phase 3 - Validation & Exceptions
- Validate user input
- Handle invalid operations
- Display meaningful error messages

### Phase 4 - Logging
- Log important system events
- Log errors and warnings

### Phase 5 - Attendance
- Mark attendance
- View attendance history
- Calculate attendance percentage

### Phase 6 - Marks
- Add marks
- Update marks
- View marks

### Phase 7 - GPA
- Calculate GPA
- Generate student result summary

### Phase 8 - Fees
- Record fee payments
- View fee status
- Track pending fees

### Phase 9 - Roles
- Admin role
- Teacher role
- Student role

## Non-Functional Requirements
- CLI-based application
- Written in modern C++
- Modular and maintainable code
- Proper error handling
- Logging support
- Data persistence using files

## Data Entities
### Student
- Student ID
- Name
- Age
- Course

### Attendance Record
- Student ID
- Date
- Status

### Marks
- Student ID
- Subject
- Marks Obtained

### Fee Record
- Student ID
- Amount
- Payment Status

## Future Enhancements
- SQLite integration
- Report generation
- CSV export
- Smart pointer-based ownership model
- Improved search and sorting algorithms
- Unit testing

---