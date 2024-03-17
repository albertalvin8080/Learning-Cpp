#include <iostream> 

int operacao(int x, int y, int f) {
	if (x == 1 && y == 1) {
		return 1;
	}
	else {
		if (x % f == 0 || y % f == 0) {
			x = (x % f == 0 ? x / f : x);
			y = (y % f == 0 ? y / f : y);
			return f * operacao(x, y, f);
		}
		else {
			return operacao(x, y, f+1);
		}
	}
}

int main() {
	int r = operacao(6, 8, 2);
	std::cout << r << "\n";
}