#include <iostream>

//#pragma pack(1)

struct Data {
	char a;
	int b;
	char c;
};

int main() {
	std::cout << sizeof(struct Data) << std::endl;
	return 0;
}