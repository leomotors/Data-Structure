#pragma once

namespace LM {
class DynamicArray {
  private:
    int *data;
    int _size;
    int _capacity;

  public:
    inline int size() const {
        return _size;
    }
    inline int capacity() const {
        return _capacity;
    }
    DynamicArray();
    void push_back(int n);
    int pop_back();
    inline int &operator[](int index) {
        return data[index];
    }
    int &at(int index);

  private:
    void realloc(int new_size);
};
} // namespace LM
