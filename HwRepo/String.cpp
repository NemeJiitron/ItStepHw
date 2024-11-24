#include "String.h"
#include <string>

String::String()
{
	length = 80;
	cStr = new char[length];
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

