#include <iostream>
#include <optional>
#include <climits>
#include <iomanip>

std::optional<double> divisionOrNull(const int &a, const int& b) {
	if (b != 0) {
		return { (double)a / b };
	}
	return {};
}

int main() {
	std::cout << std::fixed << divisionOrNull(2, 3).value() << "\n";
	std::cout << std::fixed << std::setprecision(1) << divisionOrNull(2, 0).value_or(INT_MIN) << "\n";
	std::cout << std::fixed << divisionOrNull(2, 21445).value_or(INT_MIN) << "\n";

	return EXIT_SUCCESS;
}