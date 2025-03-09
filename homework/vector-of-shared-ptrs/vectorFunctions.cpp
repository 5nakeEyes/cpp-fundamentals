#include <iostream>
#include <memory>
#include <vector>
std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> vec;
    for (int i = 0; i < count; i++) {
        auto ptr = std::make_shared<int>(i);
        vec.push_back(ptr);
    }
    return vec;
}

void print(std::vector<std::shared_ptr<int>> vec) {
    for (auto element : vec)
        std::cout << *element << " ";
}

void add10(std::vector<std::shared_ptr<int>> vec) {
    for (auto element : vec)
        if (element != nullptr)
            *element += 10;
}

void sub10(int* const element) {
    if (element != nullptr)
        *element -= 10;
}

void sub10(std::vector<std::shared_ptr<int>> vec) {
    for (auto element : vec)
        sub10(element.get());
}