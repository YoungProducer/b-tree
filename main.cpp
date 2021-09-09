#include <string>
#include <iostream>
#include <vector>
#include "BNode.h"



int main(int argc, char* argv[])
{
	BNode* node = new BNode(std::vector<float>{2, 4}, 2);


	std::cout << node->getInsertIndex(3) << std::endl;


	return 0;
};