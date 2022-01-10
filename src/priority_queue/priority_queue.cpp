#include "priority_queue.hpp"

#include <initializer_list>
#include <vector>

namespace LM {
// * Public Method

priority_queue::priority_queue(const std::initializer_list<int> &dat)
    : data(dat) {
    for (int i = data.size() - 1; i >= 0; i--) {
        heapify(i);
    }
}

priority_queue::priority_queue(const std::vector<int> &dat) : data(dat) {
    for (int i = data.size() - 1; i >= 0; i--) {
        heapify(i);
    }
}

const std::vector<int> &priority_queue::getData() {
    return data;
}

int priority_queue::top() {
    return data.at(0);
}

std::size_t priority_queue::size() {
    return data.size();
}

bool priority_queue::empty() {
    return data.empty();
}

void priority_queue::pop() {
    data[0] = data.back();
    data.pop_back();
    heapify(0);
}

void priority_queue::push(int value) {
    data.push_back(value);
    int index = data.size() - 1;
    while (index) {
        if (data[index] > data[parent(index)]) {
            std::swap(data[index], data[parent(index)]);
            index = parent(index);
        } else {
            return;
        }
    }
}

// * Private Static Inline
inline int priority_queue::left(int index) {
    return index * 2;
}

inline int priority_queue::right(int index) {
    return index * 2 + 1;
}

inline int priority_queue::parent(int index) {
    return index / 2;
}

// * Private Method
void priority_queue::heapify(int index) {
    if (left(index) < data.size() && data[left(index)] > data[index]) {
        if (right(index) < data.size() &&
            data[right(index)] > data[left(index)]) {
            std::swap(data[right(index)], data[index]);
            heapify(right(index));
            return;
        }
        std::swap(data[left(index)], data[index]);
        heapify(left(index));
        return;
    }

    if (right(index) < data.size() && data[right(index)] > data[index]) {
        std::swap(data[right(index)], data[index]);
        heapify(right(index));
        return;
    }
}
} // namespace LM
