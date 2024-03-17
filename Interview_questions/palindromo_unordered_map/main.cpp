#include <iostream>
#include <string_view>
#include <unordered_map>

bool isAnagram(const std::string_view str1, const std::string_view str2) 
{
	std::cout << str1 << " and " << str2 << ": ";

	std::unordered_map<char, uint8_t> map;
	for (const char& c : str1) {
		if (map.find(c) == map.end()) map[c] = 1;
		else map[c] += 1;
	}

	for (const char& c : str2) {
		auto it = map.find(c);
		if (it == map.end()) return false;
		if (it->second > 1) it->second -= 1;
		else map.erase(it);
	}

	return map.empty();
}

int main() {
	std::cout << isAnagram("anagram", "nagaram") << "\n";
	std::cout << isAnagram("anagram", "nagaramm") << "\n";
	std::cout << isAnagram("fried", "fired") << "\n";
	std::cout << isAnagram("listen", "silent") << "\n";
	std::cout << isAnagram("pipi", "popi") << "\n";

	return 0;
}