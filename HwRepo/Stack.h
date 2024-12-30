#pragma once
#include "Array.h"

template<typename T>
class Stack
{
private:
	Array<T> _arr;
	size_t _size;
public:
	Stack();
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
void Stack<T>::Clear()
{
	_arr.Clear();
}

template<typename T>
T Stack<T>::Top()
{
	return _arr.at(_size - 1);
}

template<typename T>
void Stack<T>::Pop()
{
	_size--;
	_arr.Pop_Back();
}

template<typename T>
void Stack<T>::Push(T val)
{
	_size++;
	_arr.Push_Back(val);
}

template<typename T>
inline size_t Stack<T>::GetSize()
{
	return _size;
}

