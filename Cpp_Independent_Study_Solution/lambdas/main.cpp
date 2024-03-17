#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <math.h>
#include <numeric>

auto printContainer = [](const auto& c) {
	for (const auto& element : c) {
		std::cout << element << " | ";
	}
	std::cout << "\n";
};

int main() {
	std::vector<float> v = { 2, 3 };
	float r = std::accumulate(v.begin(), v.end(), 1.55f, [](float a, float b) { return a*b; });
	std::cout << r << std::endl;
}

int main4() {
	std::list<float> v = { 10, 1, 9, 3 };
	//auto r = std::find(v.begin(), v.end(), 3);
	//std::cout << *r << std::endl;

	std::list<float>(*func)(std::list<float>) = [](std::list<float> l) {
		std::list<float> r;
		for (const int& n : l)
			r.emplace_back(sqrt(n));
		return r;
	};

	std::list<float> r = func(v);
	printContainer(r);

	return 0;
}

int main3() {
	std::vector<int> v = {1, 2, 3, 4, 5};
	std::vector<int> out = {-1};
	int mult = 3;

	/*
	o terceiro parâmetro consiste no iterador que rereberá os valores após a transformação
	*/
	//std::transform(v.begin(), v.end(), std::back_inserter(out), [mult](int n) { return n * mult; });
	std::transform(v.begin(), v.end(), std::inserter(out, out.begin()), [mult](const int& n) { return n * mult; });

	for (const int& n : out) {
		std::cout << n << ", ";
	}
	return 0;
}

int main2() {
	int a = 9;
	auto func = [a](auto v) mutable { 
		a = 2;
		std::cout << v << " | " << a << std::endl;
	};
	func("oi");
	return 0;
}