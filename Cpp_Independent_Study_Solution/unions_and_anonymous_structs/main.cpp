#include <iostream>

class Vertix {
public:
	float x, y;
	/*Vertix(const float& x, const float& y) : x(x), y(y) {
		std::cout << "dentro do construtor." << "\n";
	}*/
};

class Vertix2 {
public:
	union {
		struct {
			float x, y, z;
			float w;
			//int w;
		};
		struct {
			// x, y | z, w
			Vertix sub_v1, sub_v2;
		};
	};
};

void printVertix(const Vertix& vertix) {
	std::cout << vertix.x << ", " << vertix.y << "\n";
}

int main() {
	Vertix v{1.0f, 2.0f};
	printVertix(v);
	std::cout << "------------------------" << "\n";

	Vertix2 v2{3.0f, 4.0f, 5.0f, 6.0f};
	v2.w = 500.0f;
	//printVertix(*(Vertix*)&v2);
	printVertix(v2.sub_v1);
	printVertix(v2.sub_v2);
}