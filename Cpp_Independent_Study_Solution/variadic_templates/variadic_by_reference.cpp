#include <iostream>

template<typename Callable, typename ...Args>
auto bind_values(Callable callable, const Args&... args) {
	return[callable = std::move(callable), ...args = std::move(args)]() {
		return callable(args...);
	};
}

int add(const int& a, const int& b) {
	return a + b;
}

int add2(const int& a, const int& b, const int& c, const int& d) {
	return a + b + c + d;
}


int main() {
	auto bound = bind_values(add, 4, 6);
	std::cout << bound() << std::endl;

	auto bound2 = bind_values(add2, 4, 5, 6, 7);
	std::cout << bound2() << "\n";
	return 0;
}