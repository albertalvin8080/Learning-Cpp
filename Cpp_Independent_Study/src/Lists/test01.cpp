/*
 * test01.cpp
 *
 *  Created on: 3 de set. de 2023
 *      Author: Albert
 */
#include <list>
#include <iostream>
using namespace std;

int mainfdsxc() {
	list<int> lista(5, -1);

	size_t tam = 10;
	for(size_t i = 0; i < tam; ++i) {
		lista.push_back(i);
	}

	cout << "List size: " << lista.size() << endl;
//	lista.reverse();
	lista.sort();
	list<int>::iterator it;
	it = lista.begin();

	advance(it, 5);
	lista.insert(it, -99);

	tam = lista.size();
	for(size_t i = 0; i < tam; ++i){
		cout << lista.back() << endl;
		lista.pop_back();
	}
	return 0;
}



