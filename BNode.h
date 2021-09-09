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
	int32_t getInsertIndex(float value);
	int32_t getInsertIndex(float value, size_t start, size_t end);

private:
	uint16_t _maxSize;
	std::vector<float> _data;
	std::vector<BNode* > _childNodes;
};

#endif // _H_BNODE_