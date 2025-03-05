#pragma once
#include <limits>
#include <vector>

int maxOfVector(const std::vector<int>& vec) {
    int result = vec.front();
    for (auto el : vec) {
        if (result < el)
            result = el;
    }
    return result;
}
