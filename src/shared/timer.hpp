#pragma once

#include <chrono>
#include <iostream>

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
