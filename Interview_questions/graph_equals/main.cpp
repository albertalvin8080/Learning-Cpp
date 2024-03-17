#include <iostream>
#include "node.h"

int main(){
	std::shared_ptr<Node> g1 = graphV1();
	std::shared_ptr<Node> g2 = graphV2();
	std::shared_ptr<Node> g3 = graphV3();
	printGraph(g1);
	printGraph(g2);
	printGraph(g3);

	std::cout << std::endl;
	std::cout << "g1 && g1: " << graphEquals(g1, g1) << std::endl;
	std::cout << "g1 && g2: " << graphEquals(g1, g2) << std::endl;
	std::cout << "g2 && g3: " << graphEquals(g2, g3) << std::endl;

	return 0;
}