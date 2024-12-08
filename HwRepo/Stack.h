#pragma once
#include "Array.h"


class Stack
{
private:
	Array<int> _arr;
	size_t _size;
public:
	Stack();
	void Clear();
	int Top();
	void Pop();
	void Push(int val);
};

