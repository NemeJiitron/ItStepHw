#pragma once
#include "Array.h"
#include <iostream>

template<typename T>
class Stack
{
private:
	Array<T> _arr;
	size_t _size;
	int _max_size = INT_MAX;
public:
	Stack();
	Stack(int max_size);
	void Clear();
	T Top();
	void Pop();
	void Push(T val);
	size_t GetSize();
};

template<typename T>
Stack<T>::Stack()
	:_arr()
{
	_size = 0;
}

template<typename T>
Stack<T>::Stack(int max_size)
	:_arr(), _max_size(max_size)
{
}

template<typename T>
void Stack<T>::Clear()
{
	_arr.Clear();
}

template<typename T>
T Stack<T>::Top()
{
	if (_size == 0)
	{
		throw std::out_of_range("Stack is empty");
	}
	return _arr.at(_size - 1);
}

template<typename T>
void Stack<T>::Pop()
{
	if (_size == 0)
	{
		throw std::out_of_range("Stack is empty");
	}
	_size--;
	_arr.Pop_Back();
}

template<typename T>
void Stack<T>::Push(T val)
{
	if (_size == _max_size)
	{
		throw std::out_of_range("Stack overflow");
	}
	_size++;
	_arr.Push_Back(val);
}

template<typename T>
inline size_t Stack<T>::GetSize()
{
	return _size;
}

