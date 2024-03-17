#include <iostream>
#include <vector>

void printFlowers(const std::vector<int>& flowers) {
	for (const int f : flowers) {
		std::cout << f << ", ";
	}
	std::cout << std::endl;
}

// rvalue
bool canPlaceFlowers(std::vector<int>&& flowers, const int& n) {
	size_t size = flowers.size();
	int addCount = 0;

	printFlowers(flowers);

	//[1] to [n-2]
	for (size_t i = 1; i < size-1; ++i) {
		if (flowers[i] == 0 && flowers[i-1] == 0 && flowers[i+1] == 0) {
			flowers[i] = 1;
			addCount++;
		}
	}

	if (flowers[0] == 0 && flowers[1] == 0)
		addCount++;
	if (flowers[size-1] == 0 && flowers[size-2] == 0)
		addCount++;

	return addCount == n;
}

int main() {
	bool r = canPlaceFlowers(std::vector<int>({1, 0, 0, 1, 0, 1, 0, 0, 0, 0}), 3);
	std::cout << (r ? "true" : "false") << std::endl;

	bool r2 = canPlaceFlowers(std::vector<int>({ 0, 1, 0, 0, 1 }), 1);
	std::cout << (r2 ? "true" : "false") << std::endl;

	return 0;
}