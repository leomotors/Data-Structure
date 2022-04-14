#include "binary_tree.hpp"

#include "../shared.hpp"

#include <algorithm>
#include <cassert>
#include <chrono>
#include <functional>
#include <iostream>
#include <random>
#include <set>
#include <vector>

int main() {
    const int vectorSize = 1e7;

    std::cout << "Data Size: " << vectorSize << std::endl;

    int items1, items2;

    TIMERSTART()
    std::vector<int> v;
    v.reserve(vectorSize);
    for (int i = 0; i < vectorSize; i++) {
        v.push_back(GEN());
    }
    TIMERSTOP("Data Initialization")

    TIMERSTART()
    LM::BinaryTree tree;
    for (int d : v)
        tree.insert(d);
    items1 = tree.size();
    TIMERSTOP("My Ordinary Binary Tree Insertions")

    TIMERSTART()
    for (int i = 0; i < vectorSize; i++)
        tree.erase(v[i]);
    assert(tree.empty());
    TIMERSTOP("My Ordinary Binary Tree Erasing")

    TIMERSTART()
    std::set<int> s;
    for (int d : v)
        s.insert(d);
    items2 = s.size();
    TIMERSTOP("std::set (Red-Black Tree) Insertions")

    TIMERSTART()
    for (int i = 0; i < vectorSize; i++)
        s.erase(v[i]);
    assert(s.empty());
    TIMERSTOP("std::set (Red-Black Tree) Erasing")

    assert(items1 == items2);
    std::cout << "There is " << items1 << " unique items" << std::endl;
}
