#pragma once
#include "Array.h"

template<typename T>
class Queue
{
private:
	Array<T> _arr;
	size_t _size;
public:
	Queue();
	void Clear();
	T Top();
	void Pop();
	void Push(T val);
};

template<typename T>
Queue<T>::Queue()
	:_arr()
{
	_size = 0;
}

template<typename T>
void Queue<T>::Clear()
{
	_arr.Clear();
}

template<typename T>
T Queue<T>::Top()
{
	return _arr.at(0);
}

template<typename T>
void Queue<T>::Pop()
{
	_size--;
	_arr.Pop_Front();
}

template<typename T>
void Queue<T>::Push(T val)
{
	_size++;
	_arr.Push_Back(val);
}
