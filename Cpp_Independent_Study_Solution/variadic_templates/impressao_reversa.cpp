#include <iostream>

template<typename T>
void reverse(const T& t) {
	std::cout << t << " ";
}

template <typename T, typename ...Args> 
void reverse(const T& t, const Args &...args) {
	// unpacking
	reverse(args...);
	reverse(t);
}

int main2() {
	reverse(123, "Hello World", 456);

	return 0;
}