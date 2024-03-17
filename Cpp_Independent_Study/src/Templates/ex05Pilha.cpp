/*
 * ex05Pilha.cpp
 *
 *  Created on: 3 de set. de 2023
 *      Author: Albert
 */
#include <stack>
#include <iostream>
using namespace std;

template<typename T>
stack<T>* criar_pilha() {
	return new stack<T>;
}

int mainsdaasdds() {
	stack<string> *p = criar_pilha<string>();

	delete p;
	return 0;
}



