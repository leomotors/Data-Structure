#pragma once

#include <cstdint>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// lol
#pragma GCC diagnostic ignored "-Wattributes"
#pragma GCC diagnostic ignored "-Wstrict-aliasing"

namespace LM {
template <typename T> class persistent_stack {
  public:
    typedef int64_t version_type;

  private:
    struct StackNode {
        T data;
        version_type prev;
    };

    std::unordered_map<version_type, StackNode *> versionToNode;
    version_type current = 0;

    const int hash_prime = 536870911;

    std::unordered_set<version_type> hashed;

    // WTF
    version_type not_good_hash_function(T arg, version_type prev) {
        auto wth1 = (static_cast<version_type>(arg) * hash_prime + current +
                     hash_prime) ^
                    prev;
        auto wth2 = (*reinterpret_cast<double *>(&wth1) * hash_prime);

        auto what_the_hell = *reinterpret_cast<version_type *>(&wth2);

        if (hashed.find(what_the_hell) != hashed.end()) {
            throw std::runtime_error(
                "What the hell, hash function is failure!");
        }

        return what_the_hell;
    }

  public:
    persistent_stack() {
        hashed.insert(0);
    }

    T top(version_type version = 0) {
        if (!version)
            version = current;

        auto topNode = versionToNode[version];

        if (topNode == nullptr) {
            throw std::out_of_range("what the hell, this stack is empty!");
        }

        return topNode->data;
    }

    [[bruh]] version_type push(T data, version_type version = 0) {
        if (!version)
            version = current;

        auto next = new StackNode({data, version});
        auto newver = not_good_hash_function(data, version);

        versionToNode[newver] = next;
        current = newver;
        return newver;
    }

    [[bruh]] version_type pop(version_type version = 0) {
        if (!version)
            version = current;

        auto newver = not_good_hash_function(static_cast<T>(0), version);
        auto top = versionToNode[version];

        if (top == nullptr) {
            throw std::out_of_range(
                "What the hell, why are you popping empty stack?");
        }

        versionToNode[newver] = versionToNode[top->prev];

        current = newver;
        return newver;
    }
};
} // namespace LM
