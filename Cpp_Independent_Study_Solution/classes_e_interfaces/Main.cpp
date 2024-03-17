#include <iostream>
#include "Animal.h"

int main() {

	//Animal bear(); //not polimorfism
	//Bear bear("bear", 123.0f);
	//bear->makeSound();
	Fish fish1("sakana", 30.0f);
	Fish fish2("sacana", 92.0f);

	Fish fish3 = fish1 + fish2;
	std::cout << fish3 << std::endl;

	std::cin.get();
}