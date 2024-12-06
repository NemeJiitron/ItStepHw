#pragma once
class Array
{
private:
	int* _data;
	size_t _size;
public:
	Array(size_t n);
	Array(size_t n, bool random);
	Array(size_t n, int min, int max);
	Array(const Array& other);
	~Array();
	void Show();
};

