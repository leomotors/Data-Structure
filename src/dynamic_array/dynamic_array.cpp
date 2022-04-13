#include "dynamic_array.hpp"

#include <stdexcept>

namespace LM {
DynamicArray::DynamicArray() : _size(0) {
    const int initialSize = 5;
    data = new int[initialSize];
    _capacity = initialSize;
}

void DynamicArray::push_back(int n) {
    if (_size + 1 > _capacity) {
        // Will make push_back O(1) amortized
        // This can be any number, In Python is 1.1
        // Using high number make this faster
        // but also takes more unnecessary memory
        // At around 1.1-1.15 where its performance
        // is similar to std::vector
        const double reserve = 1.15;
        realloc((_size + 1) * reserve);
    }

    data[_size++] = n;
}

void DynamicArray::realloc(int new_size) {
    int *new_array = new int[new_size];

    for (int i = 0; i < _size; i++) {
        new_array[i] = data[i];
    }

    delete data;
    data = new_array;
    _capacity = new_size;
}

int DynamicArray::pop_back() {
    return data[--_size];
}

int &DynamicArray::at(int index) {
    if (index < 0 || index >= _size) {
        throw std::out_of_range("Index out of range");
    }

    return data[index];
}
} // namespace LM