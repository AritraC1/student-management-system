#pragma once

#include <vector>
#include <optional>
#include <functional>

template <typename T>
class Storage {
    // In memory - data stoarge
    std::vector<T> storage;

public:
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
};