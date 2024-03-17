/*
 * animal.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Albert
 */

#ifndef PURE_VIRTUAL_FUNCTIONS_ANIMAL_H_
#define PURE_VIRTUAL_FUNCTIONS_ANIMAL_H_

#include <iostream>

extern int var;

class Animal {
public:
	enum Type {
		Terrestrial = 0, Marithm, Aerial
	};

private:
	std::string name;
	Type type;

public:
	Animal(const std::string& name, Type type) {
		this->name = name;
		this->type = type;
	}

	virtual ~Animal() {}

	virtual void makeSound() = 0;
};

class Fish : public Animal {
public:
	Fish(const std::string& name, Type type) : Animal(name, type) {}

	virtual void makeSound() override {
		std::cout << "bloop" << std::endl;
	}
};

class Baiacu : public Fish {
public:
	Baiacu(const std::string& name, Type type) : Fish(name, type) {}

	virtual void makeSound() override {
		Fish::makeSound();
		std::cout << "Baiacu " << var << std::endl;
	}
};


#endif /* PURE_VIRTUAL_FUNCTIONS_ANIMAL_H_ */
