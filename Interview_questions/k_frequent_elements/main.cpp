#include <iostream>
#include <unordered_map>
#include <array>
#include <queue>
#include <vector>

//template<typename T>
//struct PairSortFirst {
//	bool operator()(const std::pair<T, size_t>& p1, const std::pair<T, size_t>& p2) const noexcept {
//		// sorting by count
//		return p1.second < p2.second;
//	}
//};

template<typename T>
struct countComparator {
	bool operator()(const std::pair<T, size_t>& left, const std::pair<T, size_t>& right) const {
		return left.second < right.second;
	}
};

template<typename T>
std::vector<std::pair<T, size_t>> k_frequent_values(const std::vector<T>& vec, const size_t& k) {
	std::unordered_map<T, size_t> umap;

	for (const T& item : vec) {
		umap[item] += 1;
	}

	using pair_t = std::pair<T, size_t>;
	std::priority_queue <pair_t, std::vector<pair_t>, countComparator<T>> pqueue;

	for (const pair_t& pair : umap) {
		pqueue.push({pair.first, pair.second});
	}

	std::vector<pair_t> result;
	result.reserve(k);

	for (size_t i = 0; i < k; ++i) {

		printf("k: %i, v: %zu\n", pqueue.top().first, pqueue.top().second);

		result.push_back(std::move(pqueue.top()));
		pqueue.pop();
	}

	return result;
}

int main() {
	std::vector<int> vec = { 1, 1, 1, 3, 3, 3, 3, 2, 2 };
	//std::vector<int> vec = {1, 1, 1, 3, 2, 2, 4, 5, 5, 6, 4};
	k_frequent_values<int>(vec, 1);

	return 0;
}