#pragma once
#include <string>
#include <functional>

struct City {
	std::string m_name;
	double m_longitude, m_latitude;

	bool operator==(const City& other) const {
		return m_name == other.m_name;
	}

	bool operator<(const City& other) const {
		return m_name < other.m_name;
	}
};

namespace std {
	template<>
	struct hash<City> {
		size_t operator()(const City& city) const {
			return hash<std::string>()(city.m_name) ^ hash<double>()(city.m_longitude) ^ hash<double>()(city.m_latitude);
		}
	};
}