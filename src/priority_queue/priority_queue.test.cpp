#include "priority_queue.hpp"

#include "../shared/random.hpp"
#include "../shared/timer.hpp"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <queue>
#include <random>
#include <vector>

int main() {
    const int vectorSize = 1e7;

    std::cout << "Data Size: " << vectorSize << std::endl;

    TIMERSTART()
    std::vector<int> v;
    v.reserve(vectorSize);
    for (int i = 0; i < vectorSize; i++) {
        v.push_back(GEN());
    }
    TIMERSTOP("Construction")

    TIMERSTART()
    LM::priority_queue l(v);
    TIMERSTOP("My Priority Queue Initialization")

    TIMERSTART()
    while (!l.empty())
        l.pop();
    TIMERSTOP("My Priority Queue Popping")

    TIMERSTART();
    std::priority_queue<int> pq;
    for (int data : v)
        pq.push(data);
    TIMERSTOP("std::priority_queue Initialization")

    TIMERSTART()
    while (!pq.empty())
        pq.pop();
    TIMERSTOP("std::priority_queue Popping")

    TIMERSTART()
    std::vector<int> s = v;
    std::sort(s.begin(), s.end());
    TIMERSTOP("std::sort")
}
