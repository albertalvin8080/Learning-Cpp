#ifndef VIC_VARIANT
#define VIC_VARIANT

#include <variant>
#include <vector>

// vector, int, char
using vic_variant = std::variant<std::vector<int>, int, char>;
//typedef std::variant<std::vector<int>, int, char> vic_variant;

enum vic_idx : unsigned char {
	VECTOR_IDX = 0, INT_IDX, CHAR_IDX
};

int switchVICVariant(const vic_variant& var) {
	int sum = 0;

	switch (var.index()) {
	case VECTOR_IDX:
		for (const int& n : std::get<std::vector<int>>(var)) {
			sum += n;
		}
		break;
	case INT_IDX:
		sum += std::get<int>(var);
		break;
	case CHAR_IDX:
		sum += std::get<char>(var);
		break;
	}

	return sum;
}

int sumVICVariant(const vic_variant& var1, const vic_variant& var2) {
	int sum = 0;

	sum += switchVICVariant(var1);
	sum += switchVICVariant(var2);

	return sum;
}

#endif
