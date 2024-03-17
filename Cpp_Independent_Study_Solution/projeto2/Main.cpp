#include <iostream>
#include "Esfera.h"

int main() {
	Esfera esfera(4);

	std::cout << esfera << std::endl;
	std::cout << *esfera << "\n";

	return 0;
}

std::ostream& operator<<(std::ostream& os, const Esfera& esfera)
{
	os << esfera.raio;
	return os;
}