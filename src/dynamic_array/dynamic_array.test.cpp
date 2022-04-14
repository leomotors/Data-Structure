#include "dynamic_array.hpp"

#include "../shared.hpp"

#include <cassert>
#include <iostream>
#include <vector>

int main() {
    const int s = 1e8;

    TIMERSTART()
    std::vector<int> vector;
    for (int i = 0; i < s; i++)
        vector.push_back(i);
    TIMERSTOP("std::vector 10^8x push back speed")

    TIMERSTART()
    std::vector<int> vector2;
    vector2.reserve(2e8);
    for (int i = 0; i < s; i++)
        vector.push_back(i);
    TIMERSTOP("std::vector 10^8x push back with reservation")

    TIMERSTART()
    LM::DynamicArray darr;
    for (int i = 0; i < s; i++)
        darr.push_back(i);
    TIMERSTOP("My Dynamic Array 10^8x push back speed")

    // Compilation should ok
    assert(darr[5] == darr.at(5));
}