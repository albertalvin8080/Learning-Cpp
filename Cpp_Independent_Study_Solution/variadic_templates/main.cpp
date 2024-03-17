#include <iostream>

template<typename T>
T sum(const T& t) {
	return t;
}

template<typename T, typename... Args>
T sum(const T& t, const Args&... args) {
	return t + sum(args...);
}

int main1() {
	std::cout << sum<double, double>(3, 5, 6.3, 10, 12) << "\n";
	return 0;
}