#include "persistent_stack.hpp"

#include "../shared.hpp"

#include <cassert>
#include <iostream>

int main() {
    LM::persistent_stack<int> pst;

    /**
     * Try pst.pop()
     * Expected: out_of_range exception
     * Result: as expected
     * PS. Previous Version Result: Segmentation Fault
     */
    [[nothing_here]]

    auto firstver = pst.push(5);
    std::cout << "push 5: " << firstver << "\n";

    assert(pst.top() == 5);

    auto secondver = pst.push(2);
    std::cout << "push 2: " << secondver << "\n";
    assert(pst.top(firstver) == 5);

    std::cout << "push 3 to first ver: " << pst.push(3, firstver) << "\n";
    assert(pst.top(secondver) == 2);

    auto fourthver = pst.pop(secondver);
    assert(pst.top(fourthver) == 5);

    std::cout << CHALK(GREEN, "yo angelo! test pass\n");

    for (int i = 0; i < 1000000; i++) {
        pst.push(0);
        pst.push(i);
    }

    std::cout << CHALK(GREEN, "yo angelo! survived 2M push stretch test!\n");

    LM::persistent_stack<double> dst;

    dst.push(1);
    dst.push(2);
    dst.pop();
    assert(static_cast<int>(dst.top()) == 1);
}
