#include "String.h"
#include <string>
#include<iostream>

String::String()
{
	length = 80;
	cStr = new char[length];
}

String::~String()
{
	delete[] cStr;
}

String::String(size_t size)
{
	length = size;
	cStr = new char[length];
}

String::String(char* str)
{
	length = strlen(str) + 1;
	cStr = new char[length];
	strcpy_s(cStr, length, str);	
}

String::String(const char* str)
{
	length = strlen(str) + 1;
	cStr = new char[length];
	strcpy_s(cStr, length, str);
}

String::String(const String& str)
{
	length = str.length;
	cStr = new char[length];
	strcpy_s(cStr, length, str.cStr);
}

void String::Show()
{
	puts(cStr);
}

void String::GetString()
{
	char str[80];
	gets_s(str);
	length = strlen(str);
	strcpy_s(cStr, length + 1, str);


}

String& String::operator=(const String& other)
{
	delete[] cStr;
	length = other.length;
	cStr = new char[length];
	strcpy_s(cStr, length, other.cStr);
	return *this;
}

String String::operator+(const String& other)
{
	size_t size = length + other.length - 1;
	char* tmp = new char[size];
	strcpy_s(tmp, size, cStr);
	strcat_s(tmp, size, other.cStr);
	String newStr(tmp);
	delete[] tmp;
	return newStr;
}

String& String::operator+=(const String& other)
{
	length += other.length - 1;
	char* tmp = new char[length];
	strcpy_s(tmp, length, cStr);
	strcat_s(tmp, length, other.cStr);
	delete[] cStr;
	cStr = tmp;
	return *this;
}

bool String::operator==(const String& other)
{

	if (strcmp(cStr, other.cStr) == 0)
	{
		return true;
	}
	return false;
}

bool String::operator!=(const String& other)
{
	if (strcmp(cStr, other.cStr) != 0)
	{
		return true;
	}
	return false;
}

bool String::operator<(const String& other)
{
	return length < other.length;
}

bool String::operator>(const String& other)
{
	return length > other.length;
}

char String::operator[](size_t index)
{
	return cStr[index];
}

std::ostream& operator<<(std::ostream& os, const String& self)
{
	os << self.cStr << std::endl;
	return os;
}
