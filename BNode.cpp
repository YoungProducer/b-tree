#include "BNode.h"

BNode::BNode(std::vector<float> data, size_t maxSize)
	: _data(data), _maxSize(maxSize)
{ 
	_childNodes.resize(maxSize + 1, NULL);

	if (data.size() == maxSize)
	{
		_full = true;
	}
}

BNode::BNode(size_t maxSize)
	: _maxSize(maxSize)
{
	_childNodes.resize(maxSize + 1, NULL);
}

const void BNode::add(float value)
{
	int32_t index = getInsertIndex(value);

	if (index == -1) return;

	if (!_full)
	{
		std::vector<float>::iterator it = _data.begin();
		std::advance(it, index);

		_data.insert(it, value);

		if (_data.size() == _maxSize) _full = true;
	}
	else
	{
		std::vector<BNode*>::iterator it = _childNodes.begin();
		std::advance(it, index);

		if (*it == nullptr)
		{
			*it = new BNode(std::vector<float>{value}, _maxSize);
		}
		else
		{
			(*it)->add(value);
		}
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

std::string BNode::dataToString() const
{
	std::stringstream ss{ "" };

	for (const float value : _data)
	{
		ss << " " << value;
	}

	return ss.str();
}

std::string BNode::toString() const
{
	std::stringstream ss{ "" };

	ss << dataToString() << std::endl;

	for (const BNode* child : _childNodes)
	{
		if (child == nullptr) continue;
		ss << child->toString();
	}

	return ss.str();
}