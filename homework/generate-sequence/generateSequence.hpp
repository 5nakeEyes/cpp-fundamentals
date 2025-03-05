#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> vec = {};
    int next_step = step;
    for (int i = 0; i < count; i++) {
        vec.push_back(next_step);
        next_step += step;
    }
    return vec;
}
