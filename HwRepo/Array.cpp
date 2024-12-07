#include "Array.h"
#include <iostream>

//template<typename T>
//Array<T>::Array(size_t n)
//{
//	_size = n;
//	_data = new int[_size] {};
//}
//
//template<typename T>
//Array<T>::Array(size_t n, bool random)
//{
//	_size = n;
//	_data = new int[_size];
//	srand(time(0));
//	for (size_t i = 0; i < _size; i++)
//	{
//		_data[i] = rand() % 100;
//	}
//}
//
//template<typename T>
//Array<T>::Array(size_t n, int min, int max)
//{
//	_size = n;
//	_data = new int[_size];
//	srand(time(0));
//	for (size_t i = 0; i < _size; i++)
//	{
//		_data[i] = min + (rand() % (max - min));
//	}
//}
//
//template<typename T>
//Array<T>::Array(const Array& other)
//{
//	_size = other._size;
//	_data = new int[_size];
//	for (size_t i = 0; i < _size; i++)
//	{
//		_data[i] = other._data[i];
//	}
//}
//
//template<typename T>
//Array<T>::~Array()
//{
//	delete[] _data;
//}
//
//template<typename T>
//void Array<T>::Show()
//{
//	for (size_t i = 0; i < _size; i++)
//	{
//		std::cout << _data[i] << " ";
//	}
//	std::cout << std::endl;
//}
//
//template<typename T>
//void Array<T>::fillRandom()
//{
//	for (size_t i = 0; i < _size; i++)
//	{
//		_data[i] = rand() % 100;
//	}
//}
//
//template<typename T>
//void Array<T>::setSize(int n)
//{
//	int* tmp = _data;
//	_data = new int[n];
//	srand(time(0));
//	for (size_t i = 0; i < n; i++)
//	{
//		if (i >= _size)
//		{
//			_data[i] = 0;
//			continue;
//		}
//		_data[i] = tmp[i];
//	}
//	_size = n;
//	delete[] tmp;
//}
//
//template<typename T>
//void Array<T>::Sort()
//{
//	int temp, end = _size;
//	for (size_t i = 0; i < _size; i++)
//	{
//		for (int j = 0; j < end - 1; j++)
//		{
//			if (_data[j] > _data[j + 1])
//			{
//				temp = _data[j];
//				_data[j] = _data[j + 1];
//				_data[j + 1] = temp;
//			}
//		}
//		end--;
//	}
//}
//
//template<typename T>
//int Array<T>::Min()
//{
//	int res = _data[0];
//	for (size_t i = 1; i < _size; i++)
//	{
//		if (_data[i] < res)
//		{
//			res = _data[i];
//		}
//	}
//	return res;
//}
//
//template<typename T>
//int Array<T>::Max()
//{
//	int res = _data[0];
//	for (size_t i = 1; i < _size; i++)
//	{
//		if (_data[i] > res)
//		{
//			res = _data[i];
//		}
//	}
//	return res;
//}
