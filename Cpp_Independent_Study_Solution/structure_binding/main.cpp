#include <iostream>
#include <random>
#include <tuple>

std::tuple<std::string, int> createPerson() {
	return {"lucas", 129};
}

int main() {
	auto [name, age] = createPerson();
	std::cout << name << ", " << age << "\n";
	return EXIT_SUCCESS;
}