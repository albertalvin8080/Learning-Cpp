#include <iostream>
#include <random>

std::tuple<std::string, int> createPerson() {
	return {"lucas", 129};
}

int main() {
	auto [name, age] = createPerson();
	std::cout << name << ", " << age << "\n";
	return EXIT_SUCCESS;
}