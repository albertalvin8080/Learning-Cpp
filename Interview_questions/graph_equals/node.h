#pragma once
#include <memory>
#include <iostream>

struct Node {
	int value;
	std::shared_ptr<Node> right;
	std::shared_ptr<Node> left;
	Node(int value) : value(value) {}
};

void _printGraph(std::shared_ptr<Node> g) {
	// pre-order
	std::cout << g->value << " ";
	if (g->left)
		_printGraph(g->left);
	if (g->right)
		_printGraph(g->right);
}

void printGraph(std::shared_ptr<Node> g) {
	_printGraph(g);
	std::cout << std::endl;
}

std::shared_ptr<Node> graphV1() {
	std::shared_ptr<Node> root = std::make_shared<Node>(1);
	root->left = std::make_shared<Node>(-1);
	root->right = std::make_shared<Node>(3);

	root->left->left = std::make_shared<Node>(14);
	root->left->right = std::make_shared<Node>(2);

	return root;
}

std::shared_ptr<Node> graphV2() {
	std::shared_ptr<Node> root = std::make_shared<Node>(1);
	root->left = std::make_shared<Node>(-1);
	root->left->left = std::make_shared<Node>(14);

	return root;
}

std::shared_ptr<Node> graphV3() {
	std::shared_ptr<Node> root = std::make_shared<Node>(1);
	root->left = std::make_shared<Node>(-1);
	//root->left->left = std::make_shared<Node>(14);

	return root;
}

int graphEquals(const std::shared_ptr<Node>& g1, const std::shared_ptr<Node>& g2) {
	if (!g1 || !g2) {
		return !g1 && !g2;
	}

	if (g1->value != g2->value) {
		return 0;
	}

	// the logical AND (&&) takes advantage of short-circuiting (returns false imediatelly if the left side is false)
	return graphEquals(g1->left, g2->left) && graphEquals(g1->right, g2->right);
	// the bitwise AND (&) ensure that both recursive calls are executed.
	//return graphEquals(g1->left, g2->left) & graphEquals(g1->right, g2->right);
}