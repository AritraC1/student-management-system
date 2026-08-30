#include <vector>
#include <string>

#include "models/student.hpp"
#include "storage/storage.hpp"

class StudentRepository { 
    Storage<StudentModel> storage;

    public:
        // Create a new student and store it in storage
        void add(StudentModel s) {
            storage.add(s);
        }

        // Update student details

        // Delete student from storage

        // Get one student from storage by id

        // Get all student
        void get_all_students() {
            std::vector<StudentModel> students = storage.get_all();

            for (const auto& student : students) {
                student.display_details();
            }
        }
};