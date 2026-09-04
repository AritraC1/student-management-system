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
        explicit StudentRepository(std::string filepath = "data/students.txt") : storage(filepath) {
            storage.load_from_file();
            Logger::log(LogLevel::INFO, "Repository: loaded students from " + filepath);
        }

        void add(StudentModel s) {
            storage.add(s);
            storage.save_to_file();
            
            Logger::log(LogLevel::INFO, "Repository: student added, id=" + s.get_id());
        }

        bool update(StudentModel s) {
            bool success = storage.update(
                [&](const StudentModel& existing) { return existing.get_id() == s.get_id(); },
                s
            );

            if (success) storage.save_to_file();

            Logger::log(
                success ? LogLevel::INFO : LogLevel::WARNING,
                (success ? "Repository: student updated, id=" : "Repository: update failed, id not found: ") + s.get_id()
            );

            return success;
        }

        bool remove(std::string id) {
            bool success = storage.remove(
                [&](const StudentModel& existing) { return existing.get_id() == id; }
            );

            if (success) storage.save_to_file();

            Logger::log(
                success ? LogLevel::INFO : LogLevel::WARNING,
                (success ? "Repository: student removed, id=" : "Repository: remove failed, id not found: ") + id
            );

            return success;
        }

        std::optional<StudentModel> find_by_id(std::string id) {
            auto result = storage.find(
                [&](const StudentModel& existing) { return existing.get_id() == id; }
            );

            if (!result) {
                Logger::log(LogLevel::WARNING, "Repository: student not found, id=" + id);
            }

            return result;
        }

        std::vector<StudentModel> get_all_students() {
            return storage.get_all();
        }
};