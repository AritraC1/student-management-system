#pragma once

#include <vector>
#include <string>
#include <optional>

#include "models/student.hpp"
#include "storage/storage.hpp"
#include "logging/logger.hpp"
#include "logging/log_level.hpp"

class StudentRepository {
    Storage<StudentModel> storage;

    public:
        // add student
        void add(StudentModel s) {
            storage.add(s);
            Logger::log(LogLevel::INFO, "Repository: student added, id=" + s.get_id());
        }

        // Update student details
        bool update(StudentModel s) {
            bool success = storage.update(
                [&](const StudentModel& existing) { return existing.get_id() == s.get_id(); },
                s
            );

            Logger::log(
                success ? LogLevel::INFO : LogLevel::WARNING,
                (success ? "Repository: student updated, id=" : "Repository: update failed, id not found: ") + s.get_id()
            );

            return success;
        }

        // Delete student from storage
        bool remove(std::string id) {
            bool success = storage.remove(
                [&](const StudentModel& existing) { return existing.get_id() == id; }
            );

            Logger::log(
                success ? LogLevel::INFO : LogLevel::WARNING,
                (success ? "Repository: student removed, id=" : "Repository: remove failed, id not found: ") + id
            );

            return success;
        }

        // Get one student from storage by id
        std::optional<StudentModel> find_by_id(std::string id) {
            auto result = storage.find(
                [&](const StudentModel& existing) { return existing.get_id() == id; }
            );

            if (!result) {
                Logger::log(LogLevel::WARNING, "Repository: student not found, id=" + id);
            }

            return result;
        }

        // get all students
        std::vector<StudentModel> get_all_students() {
            return storage.get_all();
        }
};