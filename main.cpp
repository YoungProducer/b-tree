#include <string>
#include <iostream>
#include <vector>
#include "BNode.h"



int main(int argc, char* argv[])
{
	BNode* node = new BNode(std::vector<float>{3, 5, 7, 10}, 4);


	std::cout << node->getInsertIndex(5) << std::endl;


	return 0;
};