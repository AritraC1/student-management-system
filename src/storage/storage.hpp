#pragma once

#include <vector>
#include <optional>
#include <functional>
#include <fstream>
#include <string>
#include <filesystem>
#include <stdexcept>

template <typename T>
class Storage {
    // In memory - data stoarge
    std::vector<T> storage;
    std::string filepath;

    void ensure_directory_exists() const {
        std::filesystem::path p(filepath);
        
        if (p.has_parent_path()) {
            std::filesystem::create_directories(p.parent_path());
        }
    }

    public:
        // filepath e.g. "data/students.txt"
        explicit Storage(std::string filepath) : filepath(std::move(filepath)) {}

        // update data in storage
        void add(T item) {
            storage.push_back(item);
        }

        // get data from storage
        std::vector<T> get_all() {
            return storage;
        }

        // find
        std::optional<T> find(std::function<bool(const T&)> predicate) {
            for (const auto& item : storage) {
                if (predicate(item)) return item;
            }

            return std::nullopt;
        }

        // update
        bool update(std::function<bool(const T&)> predicate, T new_item) {
            for (auto& item : storage) {
                if (predicate(item)) { item = new_item; return true; }
            }

            return false;
        }

        // remove
        bool remove(std::function<bool(const T&)> predicate) {
            for (auto it = storage.begin(); it != storage.end(); ++it) {
                if (predicate(*it)) { storage.erase(it); return true; }
            }

            return false;
        }

        // Persistence
        
        // Requires T::serialize() const -> std::string  (one line, no '\n')
        void save_to_file() {
            std::ofstream out(filepath, std::ios::trunc);
            
            if (!out) throw std::runtime_error("Could not open file for writing: " + filepath);
            
            for (const auto& item : storage) {
                out << item.serialize() << '\n';
            }
        }

        // Requires static T::deserialize(const std::string& line) -> T
        void load_from_file() {
            std::ifstream in(filepath);

            // no file yet on first run — not an error
            if (!in) return;
            
            storage.clear();
            
            std::string line;
            
            while (std::getline(in, line)) {
                if (line.empty()) continue;
                storage.push_back(T::deserialize(line));
            }
        }
};