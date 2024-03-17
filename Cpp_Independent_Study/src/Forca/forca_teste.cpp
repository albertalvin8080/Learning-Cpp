/*
 * Forca.cpp
 *
 *  Created on: 2 de set. de 2023
 *      Author: Albert
 */

#include <iostream>
#include "forca.h"
using namespace std;

int mainasaasasa(int argc, char **argv) {
	Forca forca("Batata");

	do
	{
		forca.show_word();
		char c;
		cin >> c;
		forca.try_guessing(c);
	}
	while(!forca.is_finished());
	forca.show_word();

	return 0;
}


