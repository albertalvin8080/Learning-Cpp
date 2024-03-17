#include <iostream>
#include "node.h"

int main_GRAPH() {
//int main() {
	std::shared_ptr<Node> root = 
		graphV1();
		//graphV2();

	std::cout << "Graph: ";
	printGraph(root);
	std::cout << std::endl;

	const int target = 18;
	std::cout << "target: " << target << std::endl;
	std::cout << (sumRootToLeaf(root, target, 0) == 1 ? "true" : "false") << std::endl;

	return 0;
}