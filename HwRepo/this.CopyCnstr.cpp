#include <iostream>
#include "String.h"
#include "Array.h"

int main()
{
	String str;
	str.GetString();
	str.Show();
	char string[] = "helloGithub";
	String str2(string);
	str2.Show();
	String str3(str2);
	str3.Show();

	Array arr(10);
	arr.Show();
	Array arr2(10, true);
	arr2.Show();
	Array arr3(arr2);
	arr3.Show();
	Array arr4(20, 10, 50);
	arr4.Show();

	return 0;
}