#pragma once
#include "Array.h"
class Queue
{
private:
	Array<int> _arr;
	size_t _size;
public:
	Queue();
	void Clear();
	int Top();
	void Pop();
	void Push(int val);
};

