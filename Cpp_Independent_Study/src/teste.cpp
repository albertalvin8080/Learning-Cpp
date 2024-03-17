/*
 * teste.cpp
 *
 *  Created on: Sep 6, 2023
 *      Author: Albert
 */




#include <iostream>
using namespace std;

class Veiculo {
private:
	int num_rodas;

public:
	void set_num_rodas(int *num) {
		this->num_rodas = *num;
	}
	int get_num_rodas() {
		return num_rodas;
	}
};

int main2123() {
	Veiculo *v1 = new Veiculo();
	v1->set_num_rodas(new int(69));
	cout << v1->get_num_rodas() << endl;
	return 0;
}
