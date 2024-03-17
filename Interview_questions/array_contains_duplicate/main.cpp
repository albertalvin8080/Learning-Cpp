#include <iostream>
//#include <unordered_map>
#include <unordered_set>
#include <chrono>

int containsDuplicate1(const int* const & array, const int size) {
	std::unordered_set<int> set;

	for (int i = 0; i < size; ++i) {
		const int n = array[i];
		std::unordered_set<int>::const_iterator got = set.find(n);
		if (got != set.end()) {
			// exists
			return 1;
		}
		set.insert(n);
	}
	return 0;
}

int containsDuplicate2(const int* const& array, const int size) {
	std::unordered_set<int> set;

	int left = 0;
	int right = size - 1;

	while (left <= right) {
		const int nl = array[left++];
		const int nr = array[right--];

		auto gotL = set.find(nl);
		if (gotL != set.end())
			return 1;

		set.insert(nl);

		auto gotR = set.find(nr);
		if (gotR != set.end())
			return 1;

		set.insert(nr);
	}
	return 0;
}

int main() {
	const int size = 10000;
	int array[size];

	for (int i = 0; i < size; ++i) {
		array[i] = i;
	}
	//array[0] = 9999;
	array[0] = 99;
	//array[0] = 1;

	auto s1 = std::chrono::high_resolution_clock::now();
	auto v1 = containsDuplicate1(array, size);
	auto e1 = std::chrono::high_resolution_clock::now();
	auto d1 = std::chrono::duration_cast<std::chrono::microseconds>(e1-s1);

	std::cout << "v1: " << v1 << std::endl;
	std::cout << "us: " << d1.count() << std::endl;

	auto s2 = std::chrono::high_resolution_clock::now();
	auto v2 = containsDuplicate2(array, size);
	auto e2 = std::chrono::high_resolution_clock::now();
	auto d2 = std::chrono::duration_cast<std::chrono::microseconds>(e2-s2);

	std::cout << "v2: " << v2 << std::endl;
	std::cout << "us: " << d2.count() << std::endl;
}