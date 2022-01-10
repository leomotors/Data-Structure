#include "priority_queue.hpp"

#include <initializer_list>
#include <vector>

namespace LM {
// * Public Method
template <typename T>
priority_queue<T>::priority_queue(const std::initializer_list<T> &dat)
    : data(dat) {
    for (int i = data.size() - 1; i >= 0; i--) {
        heapify(i);
    }
}

template <typename T>
priority_queue<T>::priority_queue(const std::vector<T> &dat) : data(dat) {
    for (int i = data.size() - 1; i >= 0; i--) {
        heapify(i);
    }
}

template <typename T> const std::vector<T> &priority_queue<T>::getData() {
    return data;
}

template <typename T> T priority_queue<T>::top() {
    return data.at(0);
}

template <typename T> std::size_t priority_queue<T>::size() {
    return data.size();
}

template <typename T> bool priority_queue<T>::empty() {
    return data.empty();
}

template <typename T> void priority_queue<T>::pop() {
    data[0] = data.back();
    data.pop_back();
    heapify(0);
}

template <typename T> void priority_queue<T>::push(T value) {
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
template <typename T> inline int priority_queue<T>::left(int index) {
    return index * 2;
}

template <typename T> inline int priority_queue<T>::right(int index) {
    return index * 2 + 1;
}

template <typename T> inline int priority_queue<T>::parent(int index) {
    return index / 2;
}

// * Private Method
template <typename T> void priority_queue<T>::heapify(int index) {
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

template class priority_queue<int>;
} // namespace LM
