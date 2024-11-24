#include "String.h"
#include <iostream>

int main()
{
	int size = 100;
	char* str = new char[size];
	gets_s(str, size - 1);
	String Str(str);
	Str.Show();
	String Str2(Str);
	Str2.Show();

	return 0;
}
