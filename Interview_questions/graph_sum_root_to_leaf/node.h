#pragma once
#include <iostream>

struct Node {
	int value;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
	Node(int value) : value(value) {}
};

std::shared_ptr<Node> graphV1();

void printGraph(std::shared_ptr<Node> sp);

int sumRootToLeaf(std::shared_ptr<Node>& root, const int& target, const int sum);