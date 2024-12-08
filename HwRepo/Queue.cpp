#include "Queue.h"

Queue::Queue()
	:_arr()
{
	_size = 0;
}

void Queue::Clear()
{
	_arr.Clear();
}

int Queue::Top()
{
	return _arr.at(0);
}

void Queue::Pop()
{
	_arr.Pop_Front();
}

void Queue::Push(int val)
{
	_arr.Push_Back(val);
}
