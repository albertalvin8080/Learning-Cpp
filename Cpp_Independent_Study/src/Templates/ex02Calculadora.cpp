/*
 * ex02Calculadora.cpp
 *
 *  Created on: 3 de set. de 2023
 *      Author: Albert
 */
#include <iostream>
using namespace std;

template<typename T>
class Calculadora {
public:
	T somar(T a, T b) {
		return a + b;
	}
	T subtrair(T a, T b) {
		return a - b;
	}
	T multiplicar(T a, T b) {
		return a*b;
	}
	T dividir(T a, T b) {
		return a/b;
	}
};

int mainfdsa(int argc, char **argv) {

	Calculadora<int> *c1 = new Calculadora<int>;
	cout << c1->dividir(1, 3) << endl;

	Calculadora<double> *cDouble = new Calculadora<double>;
	cout << cDouble->dividir(1, 3) << endl;

	delete c1;

	return 0;
}
