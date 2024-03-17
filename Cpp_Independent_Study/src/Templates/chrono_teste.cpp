/*
 * ex02Calculadora.cpp
 *
 *  Created on: 3 de set. de 2023
 *      Author: Albert
 */
#include <iostream>
#include <chrono>
using namespace std;

int mainsewas(int argc, char **argv) {
	auto start = chrono::high_resolution_clock::now();

	auto end = chrono::high_resolution_clock::now();

	auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end-start).count() / 1000;

	cout << elapsed << "us" << endl;
	return 0;
}



