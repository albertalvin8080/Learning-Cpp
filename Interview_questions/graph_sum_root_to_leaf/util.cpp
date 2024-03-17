#include <iostream>
#include "node.h"

std::shared_ptr<Node> graphV1() {
//		 5
//		/ \
//	   4   8
//	  /   / \
//	 11  13  4
//	/ \       \
// 7   2       1

	std::shared_ptr<Node> root = std::make_shared<Node>(5);

	root->left = std::make_shared<Node>(4);

	root->left->left = std::make_shared<Node>(11);
	root->left->left->left = std::make_shared<Node>(7);
	root->left->left->right = std::make_shared<Node>(2);
	
	root->right = std::make_shared<Node>(8);
	root->right->left = std::make_shared<Node>(13);
	root->right->right = std::make_shared<Node>(4);
	root->right->right->right = std::make_shared<Node>(1);

	return root;
}

void printGraph(std::shared_ptr<Node> sp) {
	// pre-order
	std::cout << sp->value << " ";
	if(sp->left)
		printGraph(sp->left);
	if(sp->right)
		printGraph(sp->right);
}

int _sumRootToLeaf(std::shared_ptr<Node>& root, const int& target, const int sum) {
	if (!root) {
		return sum == target;
	}

	// sum > target
	if (sum > target) {
		return 0;
	}

	if (_sumRootToLeaf(root->left, target, sum + root->value)) {
		return 1;
	}

	if (_sumRootToLeaf(root->right, target, sum + root->value)) {
		return 1;
	}

	return 0;
}

int graphSum(std::shared_ptr<Node>& root) {
	if (!root) {
		return 0;
	}
	return root->value + graphSum(root->left) + graphSum(root->right);
}

int sumRootToLeaf(std::shared_ptr<Node>& root, const int& target, const int sum) {
	if (graphSum(root) < target) {
		return 0;
	}
	return _sumRootToLeaf(root, target, sum);
}