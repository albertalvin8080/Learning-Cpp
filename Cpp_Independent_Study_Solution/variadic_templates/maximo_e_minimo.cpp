#include <iostream>

template<typename T>
T max_v(const T& t) {
	return t;
}

template<typename T, typename ...Args>
T max_v(const T& t, const Args &...args) {
	T r = max_v(args...);
	return r > t ? r : t;
}

template<typename T>
T min_v(const T& t) {
	return t;
}

template<typename T, typename ...Args>
T min_v(const T& t, const Args &...args) {
	T r = min_v(args...);
	return r > t ? t : r;
}

int main3() {
	std::cout << max_v<double, double>(1, 2, 5.2, 4, 5) << "\n";
	std::cout << min_v<double, double>(0.1, 2, 5.2, 4, 5) << "\n";

	return 0;
}