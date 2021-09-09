#pragma once

#ifndef _H_BNODE_
#define _H_BNODE_

#include <vector>
#include <string>
#include <sstream>

class BNode
{
public:
	BNode(std::vector<float> data, size_t maxSize);
	BNode(size_t maxSize);

	const void add(float value);
	bool includable(float value);
	std::string dataToString() const;
	std::string toString() const;

public:
	int32_t getInsertIndex(float value);
	int32_t getInsertIndex(float value, size_t start, size_t end);

public:
	bool isFull() const { return _full; };

private:
	bool _full = false;
	uint16_t _maxSize;
	std::vector<float> _data;
	std::vector<BNode* > _childNodes;
};

#endif // _H_BNODE_