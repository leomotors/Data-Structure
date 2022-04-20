#include "safe_vector.hpp"

#include "../shared.hpp"

int main() {
    LM::safe_vector v;

    std::cout << v.getat(2).value_or(69) << "\n";
}
