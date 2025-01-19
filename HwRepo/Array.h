#pragma once
#include <ios>
#include <ostream> 
#include <istream> 
#include <iostream>
#include <fstream>

template<typename T>
class Array
{
	const size_t DEFAULT_SIZE = 1;
private:
	T* _data;
	size_t _size;
	size_t capacity;
public:
	Array();
	Array(size_t n);
	Array(size_t n, bool random);
	Array(size_t n, T*);
	Array(size_t n, int min, int max);
	Array(const Array& other);
	Array(Array&& other) noexcept;
	Array(std::initializer_list<int> list);
	~Array();
	void Show();
	size_t getSize();
	size_t getCapacity();
	void fillRandom();
	void setSize(int n);
	void Sort();
	int Min();
	int Max();
	void Push_Back(T val);
	void Pop_Back();
	void Pop_Front();
	void Errase(int index);
	void Clear();
	void Reserve(int val);
	void Shrink();
	void Save(const char* filename);
	void Load(const char* filename);
	T at(size_t index);
	Array& operator=(const Array& other);
	Array& operator=(Array&& other);
	Array& operator=(std::initializer_list<int> list);
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
	capacity = DEFAULT_SIZE;
	_data = new T[capacity];
}

template<typename T>
Array<T>::Array(size_t n)
{
	_size = n;
	capacity = n;
	_data = new T[_size] {};
}

template<typename T>
Array<T>::Array(size_t n, bool random)
{
	_size = n;
	capacity = n;
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
	capacity = n;
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
	capacity = n;
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
	capacity = other._size;
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
	capacity = other._size;
	other._data = nullptr;
	other._size = 0;

}

template<typename T>
Array<T>::Array(std::initializer_list<int> list)
{
	_size = list.size();
	capacity = _size;
	_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = *(list.begin() + i);
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
inline size_t Array<T>::getSize()
{
	return _size;
}

template<typename T>
inline size_t Array<T>::getCapacity()
{
	return capacity;
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
	if (n > capacity)
	{
		T* tmp = _data;
		capacity = n;
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
		capacity = n;
		delete[] tmp;
	}
	else if (_size < n) {
		for (size_t i = _size; i < n; i++)
		{
			_data[i] = 0;
		}
	}
	else {
		for (size_t i = _size; i > n; i--)
		{
			_data[i] = -1;
		}
		_size = n;
	}
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
	if (capacity == _size)
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
	else 
	{
		_data[_size] = val;
		_size++;
	}
}

template<typename T>
void Array<T>::Pop_Back()
{
	_data[_size - 1] = -1;
	_size--;
}

template<typename T>
void Array<T>::Pop_Front()
{
	_data[0] = -1;
	for (size_t i = 0; i < _size - 1; i++)
	{
		_data[i] = _data[i + 1];
		_data[i + 1] = -1;
	}
	_size--;
}

template<typename T>
void Array<T>::Errase(int index)
{
	_data[index] = -1;
	for (size_t i = index; i < _size - 1; i++)
	{
		_data[i] = _data[i + 1];
		_data[i + 1] = -1;
	}
	_size--;
}

template<typename T>
void Array<T>::Clear()
{
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = -1;
	}
	_size = 0;
}

template<typename T>
void Array<T>::Reserve(int val)
{
	capacity += val;
	T* tmp = new T[capacity];
	for (size_t i = 0; i < _size; i++)
	{
		tmp[i] = _data[i];
	}
	delete[] _data;
	_data = tmp;
}

template<typename T>
void Array<T>::Shrink()
{
	if (_size != capacity)
	{
		capacity = _size;
		T* tmp = new T[_size];
		for (size_t i = 0; i < _size; i++)
		{
			tmp[i] = _data[i];
		}
		delete[] _data;
		_data = tmp;
	}
}

template<typename T>
void Array<T>::Save(const char* filename)
{
	std::fstream filestream(filename, std::ios::out);
	if (filestream.is_open())
	{
		filestream.write(reinterpret_cast<char*>(&_size), sizeof(size_t));
		filestream.write(reinterpret_cast<char*>(_data), sizeof(T) * _size);
		
	}
}

template<typename T>
void Array<T>::Load(const char* filename)
{
	std::fstream filestream(filename, std::ios::in);
	if (filestream.is_open())
	{
		filestream.read(reinterpret_cast<char*>(&_size), sizeof(size_t));
		delete[] _data;
		_data = new T[_size];
		capacity = _size;
		filestream.read(reinterpret_cast<char*>(_data), sizeof(T) * _size);
	}
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
	capacity = other._size;
	_data = new T[capacity];
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
	 capacity - other.capacity;
	 other._data = nullptr;
	 other._size = 0;
	 other.capacity = 0;
}

template<typename T>
Array<T>& Array<T>::operator=(std::initializer_list<int> list)
{
	
	if (list.size() > capacity)
	{
		_size = list.size();
		capacity = _size;
		delete[] _data;
		_data = new T[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = *(list.begin() + i);
		}
	}
	else
	{
		_size = list.size();
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = *(list.begin() + i);
		}
	}
	return *this;
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
	capacity = size;
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
