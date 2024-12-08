#include "Stack.h"

Stack::Stack()
	:_arr()
{
	_size = 0;
}

void Stack::Clear()
{
	_arr.Clear();
}

int Stack::Top()
{
	return _arr.at(_size - 1);
}

void Stack::Pop()
{
	_size--;
	_arr.Pop_Back();
}

void Stack::Push(int val)
{
	_size++;
	_arr.Push_Back(val);
}
