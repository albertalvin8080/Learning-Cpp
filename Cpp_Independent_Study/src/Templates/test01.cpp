/*
 * test01.cpp
 *
 *  Created on: 3 de set. de 2023
 *      Author: Albert
 */
#include <iostream>
using namespace std;

template<typename T>
void log(T value) {
	cout << value << endl;
}

template<typename T, size_t TAM>
class Array {
private:
	T array[TAM];

public:
	int get_length() {
		return TAM;
	}
};

int main32432(int argc, char **argv) {
	log("Oi");
	log(1.1);

	Array<string, 7> *arr = new Array<string, 7>();

	cout << arr->get_length() << endl;

	delete arr;

	return 0;
}



