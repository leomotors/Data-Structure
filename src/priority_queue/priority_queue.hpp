#pragma once

#include <initializer_list>
#include <vector>

namespace LM {
template <typename T> class priority_queue {
  protected:
    std::vector<T> data;

  public:
    priority_queue() {}
    priority_queue(const std::initializer_list<T> &dat);
    priority_queue(const std::vector<T> &dat);

    const std::vector<T> &getData();
    T top();
    std::size_t size();
    bool empty();
    void pop();
    void push(T value);

  private:
    static inline int left(int index);
    static inline int right(int index);
    static inline int parent(int index);

    void heapify(int index);
};
} // namespace LM
