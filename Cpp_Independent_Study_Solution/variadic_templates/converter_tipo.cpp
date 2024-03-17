#include <iostream>
#include <string>

template<typename DestType, typename T>
DestType convertType(const T &t) {
	return static_cast<DestType>(t);
}

template<typename DestType, typename T, typename ...Args>
// could not use &... if dont use 'const'
DestType convertType(const T &t, const Args& ...args) {
	return convertType<DestType>(t) + convertType<DestType>(args...);
}

int main141() {
	std::cout << convertType<double>(2, 4.4f, 5.4) << "\n";
	std::cout << convertType<std::string>("Hello", " ", "bitch") << "\n";

	std::cout << typeid(std::string).name() << "\n";

	return 0;
}