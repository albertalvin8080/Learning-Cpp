/*
 * Forca.cpp
 *
 *  Created on: 2 de set. de 2023
 *      Author: Albert
 */

#include <iostream>
#include "hangman.h"
using namespace std;

int main(int argc, char **argv) {
	Hangman hangman("Potato");

	do
	{
		hangman.show_word();
		char c;
		cin >> c;
		hangman.try_guessing(c);
	}
	while(!hangman.is_finished());
	hangman.show_word();

	return 0;
}


