#pragma once

#include <vector>

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
};