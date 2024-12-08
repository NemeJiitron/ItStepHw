#pragma once
#include <iostream>

template<typename T>
class Array
{
private:
	T* _data;
	size_t _size;
public:
	Array();
	Array(size_t n);
	Array(size_t n, bool random);
	Array(size_t n, int min, int max);
	Array(const Array& other);
	~Array();
	void Show();
	void fillRandom();
	void setSize(int n);
	void Sort();
	int Min();
	int Max();
	void Push_Back(T val);
	void Pop_Back();
	void Pop_Front();
	void Clear();
	T at(size_t index);
};

template<typename T>
inline Array<T>::Array()
{
	_size = 0;
	_data = new T[_size];
}

template<typename T>
Array<T>::Array(size_t n)
{
	_size = n;
	_data = new T[_size] {};
}

template<typename T>
Array<T>::Array(size_t n, bool random)
{
	_size = n;
	_data = new T[_size];
	srand(time(0));
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = rand() % 100;
	}
}

template<typename T>
Array<T>::Array(size_t n, int min, int max)
{
	_size = n;
	_data = new T[_size];
	srand(time(0));
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = min + (rand() % (max - min));
	}
}

template<typename T>
Array<T>::Array(const Array& other)
{
	_size = other._size;
	_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
}

template<typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template<typename T>
void Array<T>::Show()
{
	for (size_t i = 0; i < _size; i++)
	{
		std::cout << _data[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void Array<T>::fillRandom()
{
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = rand() % 100;
	}
}

template<typename T>
void Array<T>::setSize(int n)
{
	T* tmp = _data;
	_data = new T[n];
	srand(time(0));
	for (size_t i = 0; i < n; i++)
	{
		if (i >= _size)
		{
			_data[i] = 0;
			continue;
		}
		_data[i] = tmp[i];
	}
	_size = n;
	delete[] tmp;
}

template<typename T>
void Array<T>::Sort()
{
	int temp, end = _size;
	for (size_t i = 0; i < _size; i++)
	{
		for (int j = 0; j < end - 1; j++)
		{
			if (_data[j] > _data[j + 1])
			{
				temp = _data[j];
				_data[j] = _data[j + 1];
				_data[j + 1] = temp;
			}
		}
		end--;
	}
}

template<typename T>
int Array<T>::Min()
{
	int res = _data[0];
	for (size_t i = 1; i < _size; i++)
	{
		if (_data[i] < res)
		{
			res = _data[i];
		}
	}
	return res;
}

template<typename T>
int Array<T>::Max()
{
	int res = _data[0];
	for (size_t i = 1; i < _size; i++)
	{
		if (_data[i] > res)
		{
			res = _data[i];
		}
	}
	return res;
}

template<typename T>
void Array<T>::Push_Back(T val)
{
	T* tmp = new T[_size + 1];
	for (size_t i = 0; i < _size; i++)
	{
		tmp[i] = _data[i];
	}
	tmp[_size] = val;
	_size++;
	delete[] _data;
	_data = tmp;
}

template<typename T>
inline void Array<T>::Pop_Back()
{
	T* tmp = new T[_size - 1];
	_size--;
	for (size_t i = 0; i < _size; i++)
	{
		tmp[i] = _data[i];
	}
	delete[] _data;
	_data = tmp;
}

template<typename T>
inline void Array<T>::Pop_Front()
{
	T* tmp = new T[_size - 1];
	for (size_t i = 0; i < _size; i++)
	{
		tmp[i] = _data[i + 1];
	}
	_size--;
	delete[] _data;
	_data = tmp;
}

template<typename T>
void Array<T>::Clear()
{
	_size = 0;
	delete[] _data;
	_data = new T[_size];
}

template<typename T>
T Array<T>::at(size_t index)
{
	return _data[index];
}


