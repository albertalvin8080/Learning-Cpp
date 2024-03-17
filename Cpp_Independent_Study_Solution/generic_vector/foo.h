#pragma once
#include<iostream>

class Foo {
private:
	int* p;

public:
	Foo() : p(new int[5]) {
		for (int i = 0; i < 5; ++i) {
			p[i] = 5;
		}
	}
	Foo(const Foo& other) : p(new int[5]) {
		printf("Foo: copy construct\n");
		for (int i = 0; i < 5; ++i) {
			p[i] = other.p[i];
		}
	}
	Foo(Foo&& other) noexcept {
		printf("Foo: move construct\n");
		p = other.p;
		other.p = nullptr;
	}
	~Foo() { delete[] p; }

	friend std::ostream& operator<<(std::ostream& os, const Foo& foo);
};

std::ostream& operator<<(std::ostream& os, const Foo& foo) {
	for (int i = 0; i < 5; ++i) {
		os << foo.p[i] << " ";
	}
	return os;
}