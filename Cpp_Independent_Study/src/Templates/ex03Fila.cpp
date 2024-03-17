/*
 * ex03Fila.cpp
 *
 *  Created on: 3 de set. de 2023
 *      Author: Albert
 */
#include <queue>
#include <iostream>
using namespace std;

template<typename T>
class Fila {
private:
	queue<T> *fila;

public:
	Fila() {
		fila = new queue<T>;
	}
	Fila(const queue<T> &fila) {
		this->fila = new queue<T>(fila);
	}
	~Fila() {
		delete fila;
	}

	void push(T value) {
		fila->push(value);
	}
	void pop() {
		fila->pop();
	}
	T front() {
		return fila->front();
	}
};

int mainuobui() {
	Fila<string> *fila = new Fila<string>();

	fila->push("ola");
	fila->push("ola2");
	fila->push("ola3");
	cout << fila->front() << endl;
	fila->pop();
	cout << fila->front() << endl;

	delete fila;
	return 0;
}

