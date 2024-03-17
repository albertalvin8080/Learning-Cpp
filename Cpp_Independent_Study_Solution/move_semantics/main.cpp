#include <iostream>
#include <vector>
#include <string>
#include "generic_array.h"

static size_t ac = 0;

void* operator new(size_t m_size) {
	ac++;
	return malloc(m_size);
}

int main() {
	//GenericArray<int> arr{"array-1", 4};
	//GenericArray<int> arr2{ arr };
	//GenericArray<int> arr3 = {std::move(arr)};
	{
		std::vector<GenericArray<int>> v;
		v.reserve(10);
		for (int i = 0; i < 10; ++i) {
			GenericArray<int> temp = {"array-"+std::to_string(i), 10};
			//v.push_back(temp);
			v.push_back(std::move(temp));
		}
	}
	std::cout << "Alloc count: " << ac << "\n";

	return 0;
}