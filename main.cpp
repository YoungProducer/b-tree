#include <string>
#include <iostream>
#include <vector>
#include "BNode.h"

int main(int argc, char* argv[])
{
	BNode* node = new BNode(std::vector<float>{8, 16}, 4);

	node->add(1);
	node->add(2);
	node->add(5);
	node->add(6);
	node->add(9);
	node->add(12);
	node->add(18);
	node->add(21);
	node->add(3);
	node->add(19);
	node->add(22);
	node->add(23);
	node->add(4);
	node->add(7);
	node->add(23);


	std::cout << node->toString() << std::endl;

	return 0;
};