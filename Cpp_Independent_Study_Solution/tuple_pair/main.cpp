#include <iostream>
#include <tuple>
#include <utility>

std::tuple<int, std::string, float> twoValues() {
	std::tuple<int, std::string, float> tu(1, std::string("oi"), 4.3);
	return tu;
}

int main(int argc, char* argv[]) {
	std::cout << "argc: " << argc << std::endl;
	if (argc > 1)
		std::cout << argv[1] << std::endl;

	auto tuple = twoValues();
	std::cout << std::get<0>(tuple) << ", " << std::get<1>(tuple) << ", " << std::get<2>(tuple) << std::endl;

	//std::pair<int, float> p(1, (float)'o');
	std::pair<int, float> p = std::make_pair(1, (float)'o');

	std::cout << p.first << ", " << p.second << std::endl;

	std::cin.get();
	return 0;
}