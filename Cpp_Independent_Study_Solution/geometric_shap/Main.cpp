#include <iostream>
#include "FormaGemometrica.h"

int main() {
	FormaGeometrica forma(2, 4);
	
	printForma(forma);

	std::cin.get();
	return 0;
}

// friend
void printForma(const FormaGeometrica& forma) {
	std::cout << forma.holder.lado1 << forma.holder.lado2 << std::endl;
}