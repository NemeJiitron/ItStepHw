#include "Array.h"
#include <iostream>

Array::Array(size_t n)
{
	_size = n;
	_data = new int[_size] {};
}

Array::Array(size_t n, bool random)
{
	_size = n;
	_data = new int[_size];
	srand(time(0));
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = rand() % 100;
	}
}

Array::Array(size_t n, int min, int max)
{
	_size = n;
	_data = new int[_size];
	srand(time(0));
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = min + (rand() % (max - min));
	}
}

Array::Array(const Array& other)
{
	_size = other._size;
	_data = new int[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
}

Array::~Array()
{
	delete[] _data;
}

void Array::Show()
{
	for (size_t i = 0; i < _size; i++)
	{
		std::cout << _data[i] << " ";
	}
	std::cout << std::endl;
}
