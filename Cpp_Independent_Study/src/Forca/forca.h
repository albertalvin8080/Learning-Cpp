/*
 * forca.h
 *
 *  Created on: 2 de set. de 2023
 *      Author: Albert
 */

#ifndef FORCA_FORCA_H_
#define FORCA_FORCA_H_
#include <iostream>
using namespace std;

class Forca {
private:
	int lives;
	string word;
	bool finished;
	string placeholders;

public:
	Forca(const string &word);
//	~Forca();
	void show_word();
	bool try_guessing(const char guess);
	int get_lives();
	bool is_finished();
};

#endif /* FORCA_FORCA_H_ */
