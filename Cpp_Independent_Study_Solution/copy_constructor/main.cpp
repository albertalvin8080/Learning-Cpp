#include <iostream>

struct Animal {
	float size;
	Animal() : size(3) {
	}
};

template<typename T>
class Scope_ptr {
private:
	T* ptr;
	int debug;

public:
	Scope_ptr(T* ptr, const int& debug) : ptr(ptr), debug(debug) {}

	~Scope_ptr() {
		delete[] ptr;
	}

	Scope_ptr(const Scope_ptr& other) : debug(other.debug) {
		ptr = new T;
		memcpy(ptr, other.ptr, sizeof(ptr));
	}

	T* operator->() {
		return this->ptr;
	}
};

int main() {
	Scope_ptr<Animal> p1(new Animal, 5);
	Scope_ptr<Animal> p2 = p1;
	std::cout << p1->size << std::endl;
	return 0;
}