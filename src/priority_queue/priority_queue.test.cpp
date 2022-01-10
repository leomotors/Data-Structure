#include "priority_queue.hpp"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <queue>
#include <random>
#include <vector>

int main() {
    const int vectorSize = 1e7;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(-2e9, 2e9);

    std::cout << "Data Size: " << vectorSize << std::endl;

    auto start1 = std::chrono::steady_clock::now();

    std::vector<int> v;
    v.reserve(vectorSize);
    for (int i = 0; i < vectorSize; i++) {
        v.push_back(distrib(gen));
    }

    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
    std::cout << "Construction took: " << elapsed_seconds1.count() << "s\n";

    auto start2 = std::chrono::steady_clock::now();

    LM::priority_queue<int> l(v);
    while (!l.empty())
        l.pop();

    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
    std::cout << "My own Priority Queue Sorting: " << elapsed_seconds2.count()
              << "s\n";

    auto start3 = std::chrono::steady_clock::now();

    std::priority_queue<int> pq;
    for (int data : v)
        pq.push(data);

    while (!pq.empty())
        pq.pop();

    auto end3 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds3 = end3 - start3;
    std::cout << "std::priority_queue took: " << elapsed_seconds3.count()
              << "s\n";

    auto start4 = std::chrono::steady_clock::now();

    std::vector<int> s = v;
    std::sort(s.begin(), s.end());

    auto end4 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds4 = end4 - start4;
    std::cout << "std::sort took: " << elapsed_seconds4.count() << "s\n";
}
