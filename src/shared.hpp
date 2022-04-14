#pragma once

#include <chrono>
#include <iostream>
#include <random>

namespace MacroRandom {
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> distrib(-2e9, 2e9);
} // namespace MacroRandom

#define GEN() MacroRandom::distrib(MacroRandom::gen)

namespace MacroTimer {
std::chrono::steady_clock::time_point start, end;
std::chrono::duration<double> elapsed;
} // namespace MacroTimer

#define TIMERSTART() MacroTimer::start = std::chrono::steady_clock::now();

#define TIMERSTOP(str)                                                         \
    MacroTimer::end = std::chrono::steady_clock::now();                        \
    MacroTimer::elapsed = MacroTimer::end - MacroTimer::start;                 \
    std::cout << str << " took: " << MacroTimer::elapsed.count() << " seconds" \
              << std::endl;
