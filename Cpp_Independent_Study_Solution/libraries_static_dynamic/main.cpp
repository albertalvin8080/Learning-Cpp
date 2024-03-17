#include <iostream>

#include <GLFW/glfw3.h>
int main2() {
	int a = glfwInit();
	std::cout << a << std::endl;
	return 0;
}

#include <Engine.h>
int main() {
	Engine::printInfo();
}