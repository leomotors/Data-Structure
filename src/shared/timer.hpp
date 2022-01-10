#pragma once

#include <chrono>
#include <iostream>

std::chrono::steady_clock::time_point start, end;
std::chrono::duration<double> elapsed;

#define TIMERSTART() start = std::chrono::steady_clock::now();

#define TIMERSTOP(str)                                                         \
    end = std::chrono::steady_clock::now();                                    \
    elapsed = end - start;                                                     \
    std::cout << str << " took: " << elapsed.count() << " seconds" << std::endl;
