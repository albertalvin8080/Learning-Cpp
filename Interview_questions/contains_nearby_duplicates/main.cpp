#include <iostream>
#include <vector>
#include <unordered_map>

template<typename T>
bool contains_nearby_duplicates(const std::vector<T>& items, const size_t k) {
	// item : index
	std::unordered_map<T, size_t> umap;

	for (size_t i = 0; i < items.size(); ++i) {
		const T& item = items[i];
		if (umap.find(item) == umap.end()) umap[item] = i;
		else {
			if (i - umap[item] <= k) return true;
			else umap[item] = i;
		}
	}

	return false;
}

int main() {
	std::cout << contains_nearby_duplicates(std::vector<int>{ 1, 2, 3, 1 }, 3) << "\n";
	std::cout << contains_nearby_duplicates(std::vector<int>{ 1, 2, 3, 4, 1 }, 3) << "\n";
	std::cout << contains_nearby_duplicates(std::vector<int>{ 1, 2, 3, 3, 1 }, 3) << "\n";
	std::cout << contains_nearby_duplicates(std::vector<int>{ 1, 0, 1, 1 }, 1) << "\n";
	std::cout << contains_nearby_duplicates(std::vector<int>{ 1, 2, 3, 1, 2, 3 }, 2) << "\n";

	return 0;
}