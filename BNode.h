#pragma once

#ifndef _H_BNODE_
#define _H_BNODE_

#include <vector>

class BNode
{
public:
	BNode (std::vector<float> data, uint16_t maxSize): _data(data), _maxSize(maxSize) {}
	BNode (uint16_t maxSize): _maxSize(maxSize) {}

	const void add(float value);
	bool includable(float value);

public:
	uint16_t getInsertIndex(float value);
	uint16_t getInsertIndex(float value, uint32_t start, uint32_t end);

private:
	uint16_t _maxSize;
	std::vector<float> _data;
	std::vector<BNode* > _childNodes;
};

#endif // _H_BNODE_