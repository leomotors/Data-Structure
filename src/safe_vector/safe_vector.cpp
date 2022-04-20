#include "safe_vector.hpp"

#include <tuple>

namespace LM {
std::optional<int> safe_vector::getat(std::size_t index) {
    try {
        return at(index);
    } catch (...) {
        return std::nullopt;
    }
}
} // namespace LM
