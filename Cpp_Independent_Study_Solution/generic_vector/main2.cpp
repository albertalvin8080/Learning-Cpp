#include <iostream>
#include "generic_vector.h"
#include "foo.h"
#include <vector>

int main() {
	gVector<std::string> v = {"ola", "a", "b", "c"};
	
	//v.reserve(10);
	/*v.emplace_back(std::move(Foo()));
	v.emplace_back(Foo());
	v.pop_back();
	v.emplace_back(Foo());
	v.emplace_back(Foo());
	v.emplace_back(Foo());
	v.pop_back();*/
	v.emplace_back("oi");
	v.emplace_back("oi2");
	v.emplace_back("z");
	v.pop_back();
	v.emplace_back("zi");
	v.pop_back();
	v.push_back("no");

	std::cout << "-----------------------------------\n";
	for (const auto& item : v) {
		std::cout << item << " ";
	}
	std::cout << "\n";

	std::cout << "-----------------------------------\n";
	for (gVector<std::string>::Iterator it = v.begin(); it != v.end(); it++) {
		//*it = "teste";
		std::cout << *it << " ";
	}
	std::cout << "\n";
	std::cout << "-----------------------------------\n";

	for (gVector<std::string>::ReverseIterator it = v.rbegin(); it != v.rend(); it++) {
		//*it = "teste";
		std::cout << *it << " ";
	}
	std::cout << "\n";
	std::cout << "-----------------------------------\n";

	// usando um iterador reverso de forma reversa
	for (gVector<std::string>::ReverseIterator it = --v.rend(); it != --v.rbegin(); --it) {
		//*it = "teste";
		std::cout << *it << " ";
	}
	std::cout << "\n";
	std::cout << "-----------------------------------\n";
	//std::cout << v.begin()->at(0);

	return 0;
}