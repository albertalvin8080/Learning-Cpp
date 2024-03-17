/*
 * teste01.cpp
 *
 *  Created on: Sep 10, 2023
 *      Author: Albert
 */
#include <iostream>
#include "animal.h"

int var = 123;

int main() {

	Animal *fish = new Fish("G-Fish", Animal::Type::Marithm);
	Animal *baiacu = new Baiacu("BaiacuLegal", Animal::Type::Marithm);

	fish->makeSound();
	baiacu->makeSound();

	delete fish;
	return 0;
}
