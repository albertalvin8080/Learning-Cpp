/*
 * ex01Pessoa.cpp
 *
 *  Created on: 4 de set. de 2023
 *      Author: Albert
 */
#include <iostream>
using namespace std;
#define TAM 4

struct Pessoa {
	string nome;
	int idade;
	string endereco;

	Pessoa() : nome(""), idade(0), endereco("") {}

	Pessoa(string _nome, int _idade, string _endereco) :
	nome(_nome), idade(_idade), endereco(_endereco) {}
};

Pessoa mais_velha(Pessoa const *pessoas) { // se colocar const aqui, so vai poder usar ponteiro const
	// ponteiro com read-only object
	const Pessoa *mais_velha = &pessoas[0];
//	mais_velha->idade = 1; error: assignment of member 'Pessoa::idade' in read-only object
	for(size_t i=1; i<TAM; ++i) {
		// pessoas[i].idade pega uma pessoa em si, por isso nao precisa de '->'
		if(pessoas[i].idade > mais_velha->idade) {
			mais_velha = &pessoas[i];
		}
	}
	return *mais_velha;
}

int maingdscdas() {
	Pessoa *pessoas = new Pessoa[TAM];

	for(size_t i = 0; i < TAM; ++i) {
//		pessoas[i] = Pessoa("robert", 19, "ponta grossa"); substitui por objetos nao alocados(?)
		pessoas[i].idade = i;
	}


	cout << mais_velha(pessoas).idade << endl;

	delete[] pessoas;
}



