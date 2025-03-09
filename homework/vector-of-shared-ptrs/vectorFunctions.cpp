#include <vector>
#include <memory>
#include <iostream>
std::vector<std::shared_ptr<int>> generate(int count) {
	std::vector<std::shared_ptr<int>> vec;
	for (int i = 0; i < count; i++) {
		auto ptr = std::make_shared<int>(i);
		vec.push_back(ptr);
	}
	return vec;
}

void print(std::vector<std::shared_ptr<int>> vector) {
	for(auto element : vector)
		std::cout << *element << " ";
}

void add10(std::vector<std::shared_ptr<int>> vector) {
	for (auto element : vector)
		*element += 10;
}

void sub10(int* const element) {
	*element -= 10;
}