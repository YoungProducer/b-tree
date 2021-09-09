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

BNode::BNode(std::vector<float> data, size_t maxSize, BNode* parent)
	: _data(data), _maxSize(maxSize), _parent(parent)
{
	_childNodes.resize(maxSize + 1, NULL);

	if (data.size() == maxSize)
	{
		_full = true;
	}
}

BNode::BNode(size_t maxSize, BNode* parent)
	: _maxSize(maxSize), _parent(parent)
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
		return;
	}
	
	if (isCurrentLevelFull() && isLevelsAboveFull())
	{
		std::vector<BNode*>::iterator it = _childNodes.begin();
		std::advance(it, index);

		if (*it == nullptr)
		{
			*it = new BNode(std::vector<float>{value}, _maxSize, this);
			(*it)->assignNeighbours(index);
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

void BNode::assignNeighbours(int32_t index)
{
	if (_parent == nullptr) return;

	std::vector<BNode*>::iterator left = _parent->_childNodes.begin();
	std::vector<BNode*>::iterator right = _parent->_childNodes.begin();
	if (index > 0)
	{
		std::advance(left, index - 1);
		_left = *left;
	}
	if (index < _parent->_childNodes.size() - 1)
	{
		std::advance(right, index + 1);
		_right = *right;
	}
}

bool BNode::isCurrentLevelFull() const
{
	if (!_full) return false;

	BNode* left = _left;
	BNode* right = _right;

	while (left != nullptr)
	{
		if (!left->isFull()) return false;
		left = left->_left;
	}

	while (right != nullptr)
	{
		if (!right->isFull()) return false;
		right = right->_right;
	}

	return true;
}

bool BNode::isLevelsAboveFull() const
{
	if (_parent == nullptr) return true;
	if (_parent->isCurrentLevelFull()) return _parent->isLevelsAboveFull();
	return false;
}

bool BNode::isChildsFull() const
{
	bool full = true;

	for (const BNode* child : _childNodes)
	{
		if (child == nullptr) continue;

		if (!child->isFull() || !child->isChildsFull())
		{
			full = false;
			break;
		}
	}

	return full;
}

bool BNode::isNodeFull() const
{
	return isFull() && isChildsFull();
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