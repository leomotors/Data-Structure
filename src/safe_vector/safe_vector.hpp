#pragma once

#include <optional>
#include <vector>

namespace LM {
class safe_vector : public std::vector<int> {
  public:
    std::optional<int> getat(std::size_t index);
};
} // namespace LM
