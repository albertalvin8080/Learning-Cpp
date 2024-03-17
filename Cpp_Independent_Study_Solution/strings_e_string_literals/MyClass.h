#ifndef _MYCLASS_H_
#define _MYCLASS_H_

class MyClass {
private:
	int num;
public:
	mutable int debug;

	MyClass(int num) : num(num), debug(0) {}

	int getNum() const {
		debug++;
		return num;
	}
};

#endif