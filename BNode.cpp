#include "BNode.h"

const void BNode::add(float value)
{
	if (_data.size() == _maxSize)
	{

	}
}

uint16_t BNode::getInsertIndex(float value)
{
	return getInsertIndex(value, 0, _data.size());
}

uint16_t BNode::getInsertIndex(float value, uint32_t start, uint32_t end)
{
	if (_data[start] < value && value < _data[end]) return end;
	if (value < _data[start]) return start;
	if (value > _data[end]) return end + 1;
	
	uint32_t mid = (start + end) / 2;

	if (value > _data[mid]) return getInsertIndex(value, mid + 1, end);
	else if (value < _data[mid]) return getInsertIndex(value, start, mid - 1);
	else return -1;
}