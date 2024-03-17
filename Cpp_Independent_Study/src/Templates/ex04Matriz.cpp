/*
 * ex04Matriz.cpp
 *
 *  Created on: 3 de set. de 2023
 *      Author: Albert
 */
#include <iostream>
using namespace std;

template<typename T, size_t linhas, size_t colunas>
class Matriz {
private:
	T **matriz;

public:
	Matriz() {
		matriz = new T*[linhas];
		for(size_t i=0; i < linhas; ++i) {
			matriz[i] = new T[colunas];
		}
	}
};

int mainsasda() {
	return 0;
}

