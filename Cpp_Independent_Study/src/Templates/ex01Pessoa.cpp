/*
 * ex01Pessoa.cpp
 *
 *  Created on: 3 de set. de 2023
 *      Author: Albert
 */
#include <iostream>
using namespace std;

class Pessoa {
private:
	string nome;
	size_t idade;
	string endereco;
public:
	Pessoa(string nome, size_t idade, string endereco) {
		this->nome = nome;
		this->idade = idade;
		this->endereco = endereco;
	}

	const string& getEndereco() const {
		return endereco;
	}

	size_t getIdade() const {
		return idade;
	}

	const string& getNome() const {
		return nome;
	}
};

int maindsaf(int argc, char **argv) {
//  restrict
	Pessoa* p1 = new Pessoa("Padre", 91, "Macapá");
	string str = p1->getEndereco();
	cout << str << endl;

	return 0;
}

