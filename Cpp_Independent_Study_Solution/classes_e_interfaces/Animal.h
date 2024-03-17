#pragma once
#include <string>

class Animal {
protected:
	std::string name;
	float size_cm;

public:
	Animal(const std::string& name, const float& size_cm);
	virtual void makeSound() = 0;

	friend std::ostream& operator<<(std::ostream& os, const Animal& animal) {
		os << animal.name << " " << animal.size_cm;
		return os;
	}
};

Animal::Animal(const std::string& name, const float& size_cm) 
	: name(name), size_cm(size_cm) {
}

//
class Bear : public Animal {
public:
	Bear(const std::string& name, const float& size_cm)
		: Animal(name, size_cm) {
	}
	void makeSound() override {
		std::cout << "bear made sound" << std::endl;
	}
};

//
class Fish : public Animal {
public:
	Fish(const std::string& name, const float& size_cm) : Animal(name, size_cm) {}

	void makeSound() override {
		std::cout << "fish made sound" << std::endl;
	}

	Fish operator+(const Fish& other) {
		Fish newFish(name + " " + other.name, size_cm + other.size_cm);
		return newFish;
	}
};