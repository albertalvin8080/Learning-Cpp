/*
 * forca.cpp
 *
 *  Created on: 2 de set. de 2023
 *      Author: Albert
 */

#include <iostream>
#include "hangman.h"
using namespace std;

bool Hangman::try_guessing(const char guess) {
	size_t t = word.find(guess, 0);
	if(t == string::npos) {
		this->lives--;
		return false;
	}

	do {
		placeholders[t] = guess;
		t = word.find(guess, t+1);
	} while(t != string::npos);

	if(word == placeholders) {
		finished = true;
	}

	return true;
}

void Hangman::show_word() {

	if(lives < 6) cout << "     " << "O" << "   " << endl;
	if(lives < 5) cout << "    /";
	if(lives < 4) cout << "|";
	if(lives < 3) cout << "\\  " << endl;
	if(lives < 2) cout << "    /";
	if(lives < 1) cout << " \\ " << endl;

	for(size_t i = 0; i < placeholders.length(); ++i) {
		cout << placeholders[i] << " ";
	}
	cout << endl;
}

int Hangman::get_lives() {
	return lives;
}

bool Hangman::is_finished() {
	return finished;
}

Hangman::Hangman(const string &word) {
	this->lives = 0;
	this->word = word;
	for(size_t i = 0; i < word.length(); ++i) {
		this->word[i] = std::tolower(word[i]);
	}
	placeholders.resize(word.length(), '_');
	finished = false;
}

