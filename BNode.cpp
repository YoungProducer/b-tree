#include "BNode.h"

const void BNode::add(float value)
{
	if (_data.size() == _maxSize)
	{

	}
}

int32_t BNode::getInsertIndex(float value)
{
	return getInsertIndex(value, 0, _data.size() - 1);
}

int32_t BNode::getInsertIndex(float value, size_t start, size_t end)
{
	if (end - start == 1 && _data[start] < value && value < _data[end]) return end;
	if (value < _data[start]) return start;
	if (value > _data[end]) return end + 1;
	
	size_t mid = (start + end) / 2;

	if (value > _data[mid]) return getInsertIndex(value, mid + 1, end);
	else if (value < _data[mid]) return getInsertIndex(value, start, mid - 1);
	else return -1;
}