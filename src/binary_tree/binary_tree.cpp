#include "binary_tree.hpp"

#include <initializer_list>
#include <vector>

namespace LM {
BinaryTree::BinaryTree(const std::initializer_list<int> &init) {
    auto it = init.begin();

    head = new TreeNode(*it);

    it++;
    for (; it != init.end(); it++) {
        insert(*it);
    }
}

BinaryTree::BinaryTree(const std::vector<int> &init) {
    auto it = init.begin();

    head = new TreeNode(*it);

    it++;
    for (; it != init.end(); it++) {
        insert(*it);
    }
}

void BinaryTree::insert(int value) {
    if (head == nullptr) {
        head = new TreeNode(value);
        _size = 1;
        return;
    }

    TreeNode *ptr = head;
    TreeNode *prev = ptr;

    while (ptr != nullptr) {
        prev = ptr;
        if (value < ptr->data)
            ptr = ptr->left;
        else if (value > ptr->data)
            ptr = ptr->right;
        else
            return;
    }

    _size++;
    if (value < prev->data) {
        prev->left = new TreeNode(value);
    } else {
        prev->right = new TreeNode(value);
    }
}

bool BinaryTree::find(int value) const {
    TreeNode *ptr = head;
    while (ptr != nullptr) {
        if (value == ptr->data)
            return true;
        if (value < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return false;
}

// * This function is badly written, don't mind it
void BinaryTree::erase(int value) {
    TreeNode *ptr = head;
    TreeNode *prev = head;
    while (ptr != nullptr) {
        if (value == ptr->data)
            break;

        prev = ptr;
        if (value < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if (ptr == nullptr)
        return;

    // * Erasure Process
    _size--;
    TreeNode **parentPtr;
    bool finished = false;

    while (!finished) {
        parentPtr = &((prev->left == ptr) ? prev->left : prev->right);

        switch ((ptr->left != nullptr) + (ptr->right != nullptr)) {
        case 0: {
            if (prev->data > ptr->data) {
                prev->left = nullptr;
                delete ptr;
            } else {
                prev->right = nullptr;
                delete ptr;
            }
            finished = true;
            break;
        }
        case 1: {
            if (ptr->left != nullptr) {
                *parentPtr = ptr->left;
                delete ptr;
            } else {
                *parentPtr = ptr->right;
                delete ptr;
            }
            finished = true;
            break;
        }
        case 2: {
            TreeNode *succ = ptr->right;
            TreeNode *prevsucc = ptr;
            while (succ->left != nullptr) {
                prevsucc = succ;
                succ = succ->left;
            }

            ptr->data = succ->data;

            prev = prevsucc;
            ptr = succ;
        }
        }
    }
}

std::size_t BinaryTree::size() const {
    return _size;
}

bool BinaryTree::empty() const {
    return !_size;
}
} // namespace LM
