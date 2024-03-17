#include <iostream>
#include <vector>

size_t searchInsert(const int* const &array, const int& size, const int& value) {
	int start = 0;
	int end = size-1;

	while (start <= end) {
		int middle_idx = (end + start) / 2;
		int middle_value = array[middle_idx];

		if (middle_value == value) return middle_idx;
		if (middle_value > value) end = middle_idx - 1;
		else start = middle_idx + 1;
	}

	return start;
}

int main() {
	const int size = 6;
	int array[size] = {1, 3, 4, 6, 8, 12};

	std::cout << searchInsert(array, size, 5) << "\n";
	std::cout << searchInsert(array, size, 1) << "\n";
	std::cout << searchInsert(array, size, 2) << "\n";
	std::cout << searchInsert(array, size, 7) << "\n";

	return 0;
}