#include <initializer_list>
#include <unordered_map>
#include <iostream>
#include <string>

static int s_AllocCount = 0;

void* operator new(size_t size) {
	s_AllocCount++;
	return malloc(size);
}

// WRONG AWNSER
//void removeDuplicatesAwnser(const std::string& str) {
//	std::stack<char> stack;
//
//	for (const char& c : str) {
//		if (!stack.empty() && stack.top() == c) {
//			stack.pop();
//		}
//		else {
//			stack.push(c);
//		}
//	}
//
//	while (!stack.empty()) {
//		std::cout << stack.top() << " ";
//		stack.pop();
//	}
//	std::cout << "\n";
//}

template<size_t t_size>
std::string removeDuplicates(const std::string_view& view) {
	std::unordered_map<char, size_t> map;
	// initializing array with 0
	short aux[t_size] = {};

	for (size_t i = 0; i < t_size; ++i) {
		const char &c = view[i];
		auto condition = map.contains(c);

		if (condition) {
			aux[map.at(c)] = 0;
			map.erase(c);
		}
		else {
			map.insert({c, i});
			aux[i] = 1;
		}
	}

	std::string result;
	//result.reserve(map.size());
	for (size_t i = 0; i < t_size; ++i) {
		if (aux[i])
			result += view[i];
	}

	return result;
}

int main() {
	std::cout << removeDuplicates<7>("abbbaca") << "\n";
	std::cout << removeDuplicates<6>("axzzxy") << "\n";
	std::cout << removeDuplicates<8>("sluiolis") << "\n";

	std::cout << "Alloc Count: " << s_AllocCount << "\n";

	return EXIT_SUCCESS;
}