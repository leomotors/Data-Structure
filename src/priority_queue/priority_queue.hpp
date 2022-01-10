#pragma once

#include <initializer_list>
#include <vector>

namespace LM {
class priority_queue {
  protected:
    std::vector<int> data;

  public:
    priority_queue() {}
    priority_queue(const std::initializer_list<int> &dat);
    priority_queue(const std::vector<int> &dat);

    const std::vector<int> &getData();
    int top();
    std::size_t size();
    bool empty();
    void pop();
    void push(int value);

  private:
    static inline int left(int index);
    static inline int right(int index);
    static inline int parent(int index);

    void heapify(int index);
};
} // namespace LM
