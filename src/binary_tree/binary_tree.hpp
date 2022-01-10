#pragma once

#include <initializer_list>

#include <vector>

namespace LM {
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int dat, TreeNode *lptr = nullptr, TreeNode *rptr = nullptr)
        : data(dat), left(lptr), right(rptr) {}
};

class BinaryTree {
  private:
    TreeNode *head;
    int _size = 0;

  public:
    BinaryTree() {}
    BinaryTree(const std::initializer_list<int> &data);
    BinaryTree(const std::vector<int> &data);

    void insert(int value);
    bool find(int value) const;
    void erase(int value);
    std::size_t size() const;
    bool empty() const;
};
} // namespace LM
