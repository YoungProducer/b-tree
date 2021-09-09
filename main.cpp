#include <string>
#include <iostream>
#include <vector>
#include "BNode.h"



int main(int argc, char* argv[])
{
	BNode* node = new BNode(std::vector<float>{1, 10, 20, 30}, 4);

	node->add(4);
	node->add(2);

	std::cout << node->toString() << std::endl;

	return 0;
};