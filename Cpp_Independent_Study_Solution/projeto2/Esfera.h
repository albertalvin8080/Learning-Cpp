#ifndef _ESFERA_H_
#define _ESFERA_H_
#include <iostream>
//#include <string>

class Esfera {
private:
	float raio;
	std::string str = "nunca saberemos";

public:
	Esfera(const float &raio) : raio(raio) {
		
	}

	std::string operator*() {
		return str;
	}

	friend std::ostream& operator<<(std::ostream& os, const Esfera& esfera);
};

#endif
