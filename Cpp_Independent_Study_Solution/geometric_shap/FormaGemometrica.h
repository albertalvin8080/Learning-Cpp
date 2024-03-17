#pragma once
#include <iostream>

class FormaGeometrica {
private:
	struct dataHolder {
		float lado1;
		float lado2;
	} holder;

public:
	FormaGeometrica(const float& lado1, const float& lado2) {
		holder.lado1 = lado1;
		holder.lado2 = lado2;
	}
	~FormaGeometrica() {}

	friend void printForma(const FormaGeometrica& forma);
};