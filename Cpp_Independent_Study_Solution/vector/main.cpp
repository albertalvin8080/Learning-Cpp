#include <iostream>
#include <vector>

struct Vertex {
	float x, y, z;

	Vertex(const float& x, const float& y, const float& z) : x(x), y(y), z(z) {}

	Vertex(const Vertex& other) : x(other.x), y(other.y), z(other.z) {
		std::cout << "copy" << std::endl;
	}
	
	Vertex(std::initializer_list<float> list) {
		float sum = 0;
		for (float f : list) {
			sum += f;
		}
		std::cout << sum << std::endl;
	}
};

int main() {
	std::vector<Vertex> v;
	v.reserve(3);

	v.emplace_back(9, 8, 7);
	v.emplace_back(1, 2, 3);
	v.emplace_back(2, 3, 4);

	Vertex({ 1, 2, 3, 10, 11 });

	//v.push_back({ 1, 2, 3 });
	//v.push_back({ 1, 2, 3 });
	//v.push_back({ 1, 2, 3 });

	return 0;
}