#pragma once

#ifndef _H_BNODE_
#define _H_BNODE_

#include <vector>
#include <string>
#include <sstream>

class BNode
{
public:
	BNode(std::vector<float> data, size_t maxSize, BNode* parent);
	BNode(size_t maxSize, BNode* parent);

	BNode(std::vector<float> data, size_t maxSize);
	BNode(size_t maxSize);

	const void add(float value);
	std::string dataToString() const;
	std::string toString() const;

public:
	/*
	* Return true only if current node _data vector is full(_data.size equeals to _maxSize).
	*/
	bool isFull() const { return _full; };
	/*
	* Return true if and only if all branches are full, except if node doesn't have branches(the node is leaf).
	* If at least one branch or leaf aren't full then returns false.
	*/
	bool isChildsFull() const;
	/* Combines isFull and isChildsFull methods. */
	bool isNodeFull() const;
	bool isCurrentLevelFull() const;
	bool isLevelsAboveFull() const;

private:
	int32_t getInsertIndex(float value);
	int32_t getInsertIndex(float value, size_t start, size_t end);
	void assignNeighbours(int32_t index);

public:
	/* If parent is null then current node is a root node of tree. */
	BNode* _parent = nullptr;
	/* Gives access to closest neighbours if exist. */
	BNode* _left = nullptr;
	BNode* _right = nullptr;

private:
	bool _full = false;
	uint16_t _maxSize;
	std::vector<float> _data;
	std::vector<BNode* > _childNodes;
};

#endif // _H_BNODE_