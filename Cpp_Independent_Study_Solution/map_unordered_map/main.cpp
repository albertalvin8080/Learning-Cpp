#include <iostream>
#include <unordered_map>
#include <map>
#include "city.h"

int main() {
	std::unordered_map<City, std::string> cities_umap;
	cities_umap[City{"Lol-Town", 190, 190}] = "Lol-Town";
	cities_umap[City{"Berlin", 3000, 400}] = "Berlin";
	cities_umap[City{"Prague", 500, 380}] = "Prague";
	cities_umap[City{"Zara", 13, 3432432}] = "Zara";

	std::map<City, std::string> cities_map;

	for (auto[city, name] : cities_umap) {
		cities_map[city] = std::move(name);
		//std::cout << name << "\n\t" << city.m_longitude << ", " << city.m_latitude << "\n";
	}

	for (auto[city, name] : cities_map) {
		std::cout << name << "\n\t" << city.m_longitude << ", " << city.m_latitude << "\n";
	}

	return 0;
}