#pragma once

#include <random>

namespace MacroRandom {
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> distrib(-2e9, 2e9);
} // namespace MacroRandom

#define GEN() MacroRandom::distrib(MacroRandom::gen)
