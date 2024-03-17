#include <iostream>
#include <vector>
#include "vic_variant.h"

int main() {
	vic_variant var1;
	vic_variant var2;

	var1 = std::vector<int>({1, 2});
	var2 = 'A';

	std::cout << sumVICVariant(var1, var2) << "\n";

	return EXIT_SUCCESS;
}

struct Visitor {
	void operator()(const int& arg) {
		std::cout << "Integer : " << arg << "\n";
	}
	void operator()(const float& arg) {
		std::cout << "Float   : " << arg << "\n";
	}
	void operator()(const std::string& arg) {
		std::cout << "String  : " << arg << "\n";
	}
	void operator()(const char* arg) {
		std::cout << "C-String: " << std::string(arg) << "\n";
	}
};

int main2() {
	std::variant<float, int, std::string, const char*> myVariant;

	myVariant = 3.14f;
	// precisa ser inicializado
	std::visit(Visitor{}, myVariant);

	myVariant = "const_char_pointer";
	std::visit(Visitor{}, myVariant);

	myVariant = 94;
	std::visit(Visitor{}, myVariant);
	
	myVariant = std::string("C++str");
	std::visit(Visitor{}, myVariant);

	return EXIT_SUCCESS;
}

int main1() {
	std::variant<std::string, int> myVariant{};
	myVariant = 4;
	std::cout << myVariant.index() << "\n";
	myVariant = std::string("ola");
	std::cout << myVariant.index() << "\n";

	std::cout << "----------------------\n";
	std::visit([](auto& arg) {
		std::cout << arg << "\n"; 
	}, myVariant);

	std::cout << "----------------------\n";
	myVariant = 999;
	int* ptr = std::get_if<int>(&myVariant);
	//std::string* ptr = std::get_if<std::string>(&myVariant);
	if (ptr) {
		std::cout << *ptr << "\n";
	}

	//results in crash if the value is not of the given type
	//std::cout << std::get<int>(myVariant) << "\n";

	return EXIT_SUCCESS;
}