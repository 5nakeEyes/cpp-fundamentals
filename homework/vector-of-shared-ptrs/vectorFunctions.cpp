std::vector<std::shared_ptr<int>> generate(int count) {
	std::vector<std::shared_ptr<int>> vec;
	for (int i = 0; i < count; i++) {
		auto ptr = std::make_shared<int>(i);
		vec.push_back(ptr);
	}
	return vec;
}