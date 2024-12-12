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
	Array(size_t n, T*);
	Array(size_t n, int min, int max);
	Array(const Array& other);
	Array(Array&& other) noexcept;
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
	Array& operator=(const Array& other);
	Array& operator=(Array&& other);
	Array operator+(const Array& other);
	Array& operator+=(const Array& other);
	T operator[](size_t index);
	friend std::ostream& operator<<(std::ostream& os, const Array& arr)
	{
		for (size_t i = 0; i < arr._size; i++)
		{
			os << arr._data[i] << " ";
		}
		os << std::endl;
		return os;
	};
	bool operator==(const Array& other);
	bool operator!=(const Array& other);
	bool operator<(const Array& other);
	bool operator>(const Array& other);
	Array operator*(const Array& other);
};

template<typename T>
Array<T>::Array()
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
Array<T>::Array(size_t n, T* arr)
{
	_size = n;
	_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = arr[i];
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
Array<T>::Array(Array&& other) noexcept
{
	_data = other._data;
	_size - other._size;
	other._data = nullptr;
	other._size = 0;

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
void Array<T>::Pop_Back()
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
void Array<T>::Pop_Front()
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

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	delete[] _data;
	_size = other._size;
	_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
	return *this;
}

template<typename T>
 Array<T>& Array<T>::operator=(Array&& other)
{
	 delete[] _data;
	 delete[] _size;
	 _data = other._data;
	 _size - other._size;
	 other._data = nullptr;
	 other._size = 0;
}

template<typename T>
Array<T> Array<T>::operator+(const Array& other)
{
	size_t size = _size + other._size;
	T* tmp = new T[size];
	for (size_t i = 0; i < _size; i++)
	{
		tmp[i] = _data[i];
	}
	for (size_t i = _size; i < size; i++)
	{
		tmp[i] = other._data[i - _size];
	}
	Array nArr(size, tmp);
	delete[] tmp;
	return nArr;
}

template<typename T>
Array<T>& Array<T>::operator+=(const Array& other)
{
	size_t size = _size + other._size;
	T* tmp = new T[size];
	for (size_t i = 0; i < _size; i++)
	{
		tmp[i] = _data[i];
	}
	for (size_t i = _size; i < size; i++)
	{
		tmp[i] = other._data[i - _size];
	}
	_size = size;
	delete[] _data;
	_data = tmp;
	return *this;
}

template<typename T>
T Array<T>::operator[](size_t index)
{
	return _data[index];
}

template<typename T>
bool Array<T>::operator==(const Array& other)
{
	for (size_t i = 0; i < _size; i++)
	{
		if (_data[i] != other._data[i])
		{
			return false;
		}
	}
	return true;
}

template<typename T>
bool Array<T>::operator!=(const Array& other)
{
	for (size_t i = 0; i < _size; i++)
	{
		if (_data[i] != other._data[i])
		{
			return true;
		}
	}
	return false;
}

template<typename T>
bool Array<T>::operator<(const Array& other)
{
	return _size < other._size;
}

template<typename T>
bool Array<T>::operator>(const Array& other)
{
	return _size > other._size;
}

template<typename T>
inline Array<T> Array<T>::operator*(const Array& other)
{
	size_t size = 0;
	int* temp = new int[_size];
	for (size_t i = 0; i < _size; i++)
	{
		for (size_t j = 0; j < other._size; j++)
		{
			if (_data[i] == other._data[i])
			{
				temp[size] = _data[i];
				size++;
				break;
			}
		}
	}
	int* dynam_temp = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		dynam_temp[i] = temp[i];
	}
	Array nArr(size, dynam_temp);
	delete[] temp;
	delete[] dynam_temp;
	return nArr;
}
