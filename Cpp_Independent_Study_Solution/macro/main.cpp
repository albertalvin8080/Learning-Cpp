#include <iostream>

#ifdef _DEBUG
	#define LOG(x) std::cout << x << std::endl
#elif defined(NDEBUG)
	#define LOG(x)
#endif

//#define sum(x,y) int sum(int x, int y)\
//{\
//	return x+y;\
//}

#define sum(x, y) x+y

int main() {
	int x = sum(4, 5);
	LOG(x);
	return 0;
}