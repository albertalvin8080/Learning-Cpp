/*
 * ex02Retangulo.cpp
 *
 *  Created on: 4 de set. de 2023
 *      Author: Albert
 */
#include <iostream>
using namespace std;

struct Retangulo {
	float s_e[2]; // superior_esquerdo
	float i_d[2]; // inferior_direito

	Retangulo(float x1, float y1, float x2, float y2) {
		s_e[0] = x1;
		s_e[1] = y1;
		i_d[0] = x2;
		i_d[1] = y2;
	}

	float get_area() {
		return (i_d[0] - s_e[0]) * (s_e[1] - i_d[1]);
	}
};

int maindsadsa() {
	Retangulo *r = new Retangulo(1, 2, 5, 6);

	cout << r->get_area() << endl;

	delete r;

	return 0;
}

